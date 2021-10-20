//SPDX-License-Identifier: Unlicensed
pragma solidity >=0.8.0;

import './interfaces/IUniswapV2Pair.sol';
import './interfaces/IERC20.sol';

interface IWETH is IERC20 {
  function deposit() external payable;
  function withdraw(uint) external;
}

//UniswapV2 + SushiSwapV2
contract UniswapV2Trader {
  address payable private immutable WETHAddress;
  address payable private immutable owner;

  constructor(address _WETHAddress) 
    payable {
    WETHAddress = payable(_WETHAddress);
    owner = payable(msg.sender);
  }
  
  function V2Buy(
    bool fromIsToken0,
    address from,
    address pairAddress,
    uint256 inputAmount,
    uint256 reserveInMin,
    uint256 outputAmountMin,
    uint256 deadline
  )
  external
  onlyOwner()
  ensure(deadline) {
    IUniswapV2Pair pair = IUniswapV2Pair(pairAddress);
    (uint256 reserve0, uint256 reserve1,) = pair.getReserves();
    //BUY
    uint256 inputAmountWithFee = inputAmount * uint256(997);
    if (fromIsToken0) {
      require(reserve0 >= reserveInMin);
      uint256 outputAmount = (inputAmountWithFee * reserve1) / (reserve0 * uint256(1000) + inputAmountWithFee);
      require(outputAmount >= outputAmountMin);
      //transfer inputAmount to pairAddress
      from.call(abi.encodeWithSelector(0xa9059cbb, pairAddress, inputAmount));
      //swap
      pair.swap(uint256(0), outputAmount, address(this), new bytes(0));
    } else {
      require(reserve1 >= reserveInMin);
      uint256 outputAmount = (inputAmountWithFee * reserve0) / (reserve1 * uint256(1000) + inputAmountWithFee);
      require(outputAmount >= outputAmountMin);
      //transfer inputAmount to pairAddress
      from.call(abi.encodeWithSelector(0xa9059cbb, pairAddress, inputAmount));
      //swap
      pair.swap(outputAmount, uint256(0), address(this), new bytes(0));
    }
  }

function V2Sell(
    bool fromIsToken0,
    address from,
    address pairAddress,
    uint256 outputAmountMin,
    uint256 deadline
  )
  external
  onlyOwner()
  ensure(deadline) {
    IUniswapV2Pair pair = IUniswapV2Pair(pairAddress);
    (uint256 reserve0, uint256 reserve1,) = pair.getReserves();
    //SELL
    uint256 inputAmount = IERC20(from).balanceOf(address(this)) - uint256(1);
    uint256 inputAmountWithFee = inputAmount * uint256(997);
    if (fromIsToken0) {
      //transfer inputAmount to pairAddress
      from.call(abi.encodeWithSelector(0xa9059cbb, pairAddress, inputAmount));
      //check inputAmount again
      uint256 _inputAmount = IERC20(from).balanceOf(pairAddress) - reserve0;
      uint256 _inputAmountWithFee = _inputAmount * uint256(997);
      uint256 _outputAmount = (_inputAmountWithFee * reserve1) / (reserve0 * uint256(1000) + _inputAmountWithFee);
      require(_outputAmount >= outputAmountMin, 'INSUFFICIENT_OUTPUT_AMOUNT');
      //swap
      pair.swap(uint256(0), _outputAmount, address(this), new bytes(0));
    } else {
      //transfer inputAmount to pairAddress
      from.call(abi.encodeWithSelector(0xa9059cbb, pairAddress, inputAmount));
      //check WETHAmount again
      uint256 _inputAmount = IERC20(from).balanceOf(pairAddress) - reserve1;
      uint256 _inputAmountWithFee = _inputAmount * uint256(997);
      uint256 _outputAmount = (_inputAmountWithFee * reserve0) / (reserve1 * uint256(1000) + _inputAmountWithFee);
      require(_outputAmount >= outputAmountMin, 'INSUFFICIENT_OUTPUT_AMOUNT');
      //swap
      pair.swap(_outputAmount, uint256(0), address(this), new bytes(0));
    }
  }

  receive() external payable {}

  fallback() external { require(msg.data.length == 0, 'FALLBACK_TRIGGERED'); }

  function convertETHtoWETH(uint256 amount)
    external
    onlyOwner() {
      IWETH(WETHAddress).deposit{value: amount}();
  }

  function withdrawETH(uint256 amount)
    external
    onlyOwner() {
      uint256 ETHBalance = address(this).balance;
      if (amount > ETHBalance) {
        IWETH WETH = IWETH(WETHAddress);
        uint256 WETHBalance = WETH.balanceOf(address(this));
        if (WETHBalance + ETHBalance >= amount) {
          WETH.withdraw(amount - ETHBalance);
          owner.transfer(amount);
        } else {
          WETH.withdraw(WETHBalance);
          owner.transfer(ETHBalance + WETHBalance);
        }
      } else {
        owner.transfer(amount);
      }
  }
  
  function withdrawToken(address token)
    external
    onlyOwner() {
      uint256 balance = IERC20(token).balanceOf(address(this));
      token.call(abi.encodeWithSelector(0xa9059cbb, owner, balance));
  }

  modifier onlyOwner() {
    require(msg.sender == owner, 'ONLY_OWNER');
    _;
  }

  modifier ensure(uint deadline) {
    require(deadline >= block.timestamp, 'EXPIRED');
    _;
  }
}