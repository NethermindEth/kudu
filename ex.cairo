    mapping (address => uint)                       public  balanceOf;
    mapping (address => mapping (address => uint))  public  allowance;

@storage_var 
func balanceOf(uint256, uint256) -> (res: (felt, felt))
end

@storage_var 
func allowance(uint256, uint256, uint256) -> (res: (felt, felt))
end
