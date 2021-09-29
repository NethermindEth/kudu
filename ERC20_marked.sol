pragma solidity ^0.8.6;


interface ICounter {
    function count() external view returns (uint);
    function increment() external;
}


contract WARP {


    uint8  public decimals    = 18;
    uint256 public totalSupply= 100000000000000000000000000000000000;

    mapping (address => uint)                       public  balanceOf;
    mapping (address => mapping (address => uint))  public  allowance;
    address counterAddr;

    function setCounterAddr(address _counter_addr_t) public payable {
       counterAddr = _counter_addr_t;
    }

    function getCount() external view returns (uint) {
        return ICounter(counterAddr).count();
    }

    function deposit(address sender_addr_t, uint256 value) public payable returns (uint, uint){
        balanceOf[sender_addr_t] += value;
        return (21,12);
    }

    function withdraw(uint wad, address sender_addr_t) public payable {
        require(balanceOf[sender_addr_t] >= wad);
        balanceOf[sender_addr_t] -= wad;
        (uint a, uint b) = deposit(sender_addr_t, wad);
    }

    function approve_dynArgs(address[] calldata guy, uint wad, address sender_addr_t) public payable returns (bool) {
        allowance[sender_addr_t][guy[0]] = wad;
        return true;
    }

    function transferFrom(address src_addr_t, address dst_addr_t, uint wad, address sender_addr_t)
        public payable
        returns (bool)
    {


        if (src_addr_t != sender_addr_t) {
            require(allowance[src_addr_t][sender_addr_t] >= wad);
            require(balanceOf[src_addr_t] >= wad);
            allowance[src_addr_t][sender_addr_t] -= wad;
        }

        balanceOf[src_addr_t] -= wad;
        balanceOf[dst_addr_t] += wad;

        return true;
    }
}



