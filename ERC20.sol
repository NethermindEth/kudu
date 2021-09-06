pragma solidity ^0.8.6;

contract WARP {
    string public name        = "Warrpped Ether";
    string public symbol      = "WARP";
    uint8  public decimals    = 18;
    uint256 public totalSupply= 100000000000000000000000000000000000;

    mapping (uint => uint)                       public  balanceOf;
    mapping (uint => mapping (uint => uint))  public  allowance;

    function deposit(uint sender, uint256 value) public payable {
        balanceOf[sender] += value;
    }

    function withdraw(uint wad, uint sender) public payable {
        require(balanceOf[sender] >= wad);
        balanceOf[sender] -= wad;
    }

    function approve(uint guy, uint wad, uint sender) public payable returns (bool) {
        allowance[sender][guy] = wad;
        return true;
    }

    function transferFrom(uint src, uint dst, uint wad, uint sender)
        public payable
        returns (bool)
    {
        uint a = 0;

        if (src != sender) {
            require(allowance[src][sender] >= wad);
            require(balanceOf[src] >= wad);
            allowance[src][sender] -= wad;
        }

        for (uint i = 0; i < 10; i++) {
            wad += i;
            a += i*2;
            src += 42;
            balanceOf[src] -= wad;
            balanceOf[dst] += wad;
        }

        a = wad/2;
        return true;
    }
}

