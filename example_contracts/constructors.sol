// SPDX-License-Identifier: GPL-2.0-or-later
pragma solidity ^0.8.6;

contract WARP {
    address public owner;
    uint public ownerAge;
    uint public ownerCellNumber;

    function warp_constructor(address _owner, uint[] memory _ownerAge, uint _ownerCellNumber) public payable {
        owner = _owner;
        ownerAge = _ownerAge[0];
        ownerCellNumber = _ownerCellNumber;
        payable(_owner).transfer(100);
    }

}