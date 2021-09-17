pragma solidity >=0.4.18;

contract WARP {
    uint8  public decimals    = 18;
    uint256 public totalSupply= 100000000000000000000000000000000000;
    uint8 private age;
    mapping (address => uint)                       public  balanceOf;
    mapping (address => mapping (address => uint))  public  allowance;

    constructor() {
        age = 21;
    }
    function deposit(address sender, uint256[] calldata value) public payable {
        balanceOf[sender] += value[2];
    }

    function withdraw(uint wad, address sender) public payable {
        require(balanceOf[sender] >= wad);
        balanceOf[sender] -= wad;
    }

    function approve(address guy, uint wad, address sender) public payable returns (bool) {
        allowance[sender][guy] = wad;
        return true;
    }

    function transferFrom(address src, address dst, uint wad, address sender)
        public payable
        returns (bool)
    {

        if (src != sender) {
            require(allowance[src][sender] >= wad);
            require(balanceOf[src] >= wad);
            allowance[src][sender] -= wad;
        }

        balanceOf[src] -= wad;
        balanceOf[dst] += wad;

        return true;
    }
}
