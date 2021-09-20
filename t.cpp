object "WARP_174" {
    object "WARP_174_deployed" {
        code {
            {
                let _1 := 64
                let _2 := 128
                mstore(_1, _2)
                let _3 := 4
                let _4 := calldatasize()
                let _5 := lt(_4, _3)
                let _6 := iszero(_5)
                if _6
                {
                    let _7 := 0
                    let _8 := calldataload(_7)
                    let _9 := 224
                    let _10 := shr(_9, _8)
                    switch _10
                    case 0x00f714ce {
                        let _11 := _4
                        let param, param_1 := abi_decode_uint256t_address(_4)
                        fun_withdraw(param, param_1)
                        let _12 := _7
                        let _13 := mload(_1)
                        return(_13, _7)
                    }
                    case 0x1271f09a {
                        let _14 := _4
                        let param_2, param_3, param_4 := abi_decode_addresst_uint256t_address(_4)
                        let ret := fun_approve(param_2, param_3, param_4)
                        let memPos := mload(_1)
                        let _15 := abi_encode_bool(memPos, ret)
                        let _16 := sub(_15, memPos)
                        return(memPos, _16)
                    }
                    case 0x18160ddd {
                        let _17 := callvalue()
                        if _17
                        {
                            revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                        }
                        let _18 := _4
                        abi_decode(_4)
                        let _19 := 1
                        let _20 := sload(/** @src 0:83:147  "uint256 public totalSupply= 100000000000000000000000000000000000" */ _19)
                        let ret_1 := cleanup_uint256(_20)
                        let memPos_1 := mload(_1)
                        let _21 := abi_encode_uint256(memPos_1, ret_1)
                        let _22 := sub(_21, memPos_1)
                        return(memPos_1, _22)
                    }
                    case 0x1f324995 {
                        let _23 := _4
                        let param_5, param_6, param_7, param_8, param_9, param_10, param_11 := abi_decode_addresst_array_address_dyn_calldatat_uint256t_addresst_array_uint256_dyn_calldata(_4)
                        let ret_2 := fun_transferFrom(param_5, param_6, param_7, param_8, param_9, param_10, param_11)
                        let memPos_2 := mload(_1)
                        let _24 := abi_encode_bool(memPos_2, ret_2)
                        let _25 := sub(_24, memPos_2)
                        return(memPos_2, _25)
                    }
                    case 0x29a8d3bf {
                        let _26 := _4
                        let param_12, param_13 := abi_decode_addresst_uint256(_4)
                        fun_deposit(param_12, param_13)
                        let _27 := _7
                        let _28 := mload(_1)
                        return(_28, _7)
                    }
                    case 0x313ce567 {
                        let _29 := callvalue()
                        if _29
                        {
                            revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                        }
                        let _30 := _4
                        abi_decode(_4)
                        let _31 := _7
                        let _32 := sload(_7)
                        let ret_3 := extract_from_storage_value_dynamict_uint8(_32)
                        let memPos_3 := mload(_1)
                        let _33 := abi_encode_uint8(memPos_3, ret_3)
                        let _34 := sub(_33, memPos_3)
                        return(memPos_3, _34)
                    }
                    case 0x70a08231 {
                        let _35 := callvalue()
                        if _35
                        {
                            revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                        }
                        let _36 := _4
                        let _37 := abi_decode_address(_4)
                        let ret_4 := getter_fun_balanceOf(_37)
                        let memPos_4 := mload(_1)
                        let _38 := abi_encode_uint256(memPos_4, ret_4)
                        let _39 := sub(_38, memPos_4)
                        return(memPos_4, _39)
                    }
                    case 0xd2ce52d2 {
                        let _40 := _4
                        let param_14, param_15, param_16, param_17, param_18 := abi_decode_array_address_dyn_calldatat_array_uint256_dyn_calldatat_uint256(_4)
                        fun_deposit_397(param_14, param_15, param_16, param_17, param_18)
                        let _41 := _7
                        let _42 := mload(_1)
                        return(_42, _7)
                    }
                    case 0xdd62ed3e {
                        let _43 := callvalue()
                        if _43
                        {
                            revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                        }
                        let _44 := _4
                        let param_19, param_20 := abi_decode_addresst_address(_4)
                        let _45 := mapping_index_access_mapping_address_uint256_of_address_801(/** @src 0:27:1457  "contract WARP {..." */ param_19)
                        let _46 := mapping_index_access_mapping_address_uint256_of_address(_45, /** @src 0:27:1457  "contract WARP {..." */ param_20)
                        let ret_5 := /** @src 0:247:312  "mapping (address => mapping (address => uint))  public  allowance" */ read_from_storage_split_dynamic_uint256(_46)
                        let memPos_5 := mload(_1)
                        let _47 := abi_encode_uint256(memPos_5, ret_5)
                        let _48 := sub(_47, memPos_5)
                        return(memPos_5, _48)
                    }
                }
                revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
            }
            function revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
            {
                let _1 := 0
                let _2 := _1
                revert(_1, _1)
            }
            function cleanup_uint256(value) -> cleaned
            { cleaned := value }
            function validator_revert_address(value)
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(value, _1)
                let _3 := eq(value, _2)
                let _4 := iszero(_3)
                if _4
                {
                    let _5 := 0
                    let _6 := _5
                    revert(_5, _5)
                }
            }
            function abi_decode_address_1853() -> value
            {
                let _1 := 36
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1854() -> value
            {
                let _1 := 4
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1855() -> value
            {
                let _1 := 68
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1859() -> value
            {
                let _1 := 100
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_uint256t_address(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                let _5 := 4
                value0 := calldataload(_5)
                value1 := abi_decode_address_1853()
            }
            function abi_decode_addresst_uint256t_address(dataEnd) -> value0, value1, value2
            {
                let _1 := 96
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                value0 := abi_decode_address_1854()
                let _5 := 36
                value1 := calldataload(_5)
                value2 := abi_decode_address_1855()
            }
            function abi_encode_bool_to_bool(value, pos)
            {
                let _1 := iszero(value)
                let _2 := iszero(_1)
                mstore(pos, _2)
            }
            function abi_encode_bool(headStart, value0) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_bool_to_bool(value0, headStart)
            }
            function abi_decode(dataEnd)
            {
                let _1 := 0
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
            }
            function read_from_storage_split_dynamic_uint256(slot) -> value
            {
                let _1 := sload(slot)
                value := cleanup_uint256(_1)
            }
            function abi_encode_uint256_to_uint256(value, pos)
            { mstore(pos, value) }
            function abi_encode_uint256(headStart, value0) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_uint256_to_uint256(value0, headStart)
            }
            function abi_decode_array_address_dyn_calldata(offset, end) -> arrayPos, length
            {
                let _1 := 0x1f
                let _2 := add(offset, _1)
                let _3 := slt(_2, end)
                let _4 := iszero(_3)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                length := calldataload(offset)
                let _5 := 0xffffffffffffffff
                let _6 := gt(length, _5)
                if _6
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                let _7 := 0x20
                arrayPos := add(offset, _7)
                let _8 := _7
                let _9 := 5
                let _10 := shl(_9, length)
                let _11 := add(offset, _10)
                let _12 := add(_11, _7)
                let _13 := gt(_12, end)
                if _13
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
            }
            function abi_decode_addresst_array_address_dyn_calldatat_uint256t_addresst_array_uint256_dyn_calldata(dataEnd) -> value0, value1, value2, value3, value4, value5, value6
            {
                let _1 := 160
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                value0 := abi_decode_address_1854()
                let _5 := 36
                let offset := calldataload(_5)
                let _6 := 0xffffffffffffffff
                let _7 := gt(offset, _6)
                if _7
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                let _8 := 4
                let _9 := add(_8, offset)
                let value1_1, value2_1 := abi_decode_array_address_dyn_calldata(_9, dataEnd)
                value1 := value1_1
                value2 := value2_1
                let _10 := 68
                value3 := calldataload(_10)
                value4 := abi_decode_address_1859()
                let _11 := 132
                let offset_1 := calldataload(_11)
                let _12 := gt(offset_1, _6)
                if _12
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                let _13 := _8
                let _14 := add(_8, offset_1)
                let value5_1, value6_1 := abi_decode_array_address_dyn_calldata(_14, dataEnd)
                value5 := value5_1
                value6 := value6_1
            }
            function abi_decode_addresst_uint256(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                value0 := abi_decode_address_1854()
                let _5 := 36
                value1 := calldataload(_5)
            }
            function extract_from_storage_value_dynamict_uint8(slot_value) -> value
            {
                let _1 := 0xff
                value := and(slot_value, _1)
            }
            function abi_encode_uint8_to_uint8(value, pos)
            {
                let _1 := 0xff
                let _2 := and(value, _1)
                mstore(pos, _2)
            }
            function abi_encode_uint8(headStart, value0) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_uint8_to_uint8(value0, headStart)
            }
            function abi_decode_address(dataEnd) -> value0
            {
                let _1 := 32
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                value0 := abi_decode_address_1854()
            }
            function mapping_index_access_mapping_address_uint256_of_address_801(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 4
                let _5 := 0x20
                mstore(_5, _4)
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_uint256_of_address_803(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 3
                let _5 := 0x20
                mstore(_5, /** @src 0:176:241  "mapping (address => uint)                       public  balanceOf" */ _4)
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_uint256_of_address_807(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 0x03
                let _5 := 0x20
                mstore(_5, /** @src 0:634:643  "balanceOf" */ _4)
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_uint256_of_address_810(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 0x04
                let _5 := 0x20
                mstore(_5, /** @src 0:918:927  "allowance" */ _4)
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_uint256_of_address(slot, key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 0x20
                mstore(_4, slot)
                let _5 := 0x40
                let _6 := _3
                dataSlot := keccak256(_3, _5)
            }
            function getter_fun_balanceOf(key) -> ret
            {
                let _1 := mapping_index_access_mapping_address_uint256_of_address_803(key)
                ret := read_from_storage_split_dynamic_uint256(_1)
            }
            function abi_decode_array_address_dyn_calldatat_array_uint256_dyn_calldatat_uint256(dataEnd) -> value0, value1, value2, value3, value4
            {
                let _1 := 96
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                let _5 := 4
                let offset := calldataload(_5)
                let _6 := 0xffffffffffffffff
                let _7 := gt(offset, _6)
                if _7
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                let _8 := _5
                let _9 := add(_5, offset)
                let value0_1, value1_1 := abi_decode_array_address_dyn_calldata(_9, dataEnd)
                value0 := value0_1
                value1 := value1_1
                let _10 := 36
                let offset_1 := calldataload(_10)
                let _11 := gt(offset_1, _6)
                if _11
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                let _12 := _5
                let _13 := add(_5, offset_1)
                let value2_1, value3_1 := abi_decode_array_address_dyn_calldata(_13, dataEnd)
                value2 := value2_1
                value3 := value3_1
                let _14 := 68
                value4 := calldataload(_14)
            }
            function abi_decode_addresst_address(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                value0 := abi_decode_address_1854()
                value1 := abi_decode_address_1853()
            }
            function panic_error_0x32()
            {
                let _1 := shl(224, 0x4e487b71)
                let _2 := 0
                mstore(_2, _1)
                let _3 := 0x32
                let _4 := 4
                mstore(_4, _3)
                let _5 := 0x24
                let _6 := _2
                revert(_2, _5)
            }
            function calldata_array_index_access_address_dyn_calldata(base_ref, length) -> addr
            {
                let _1 := 0x02
                let _2 := lt(/** @src 0:533:534  "2" */ _1, /** @src 0:27:1457  "contract WARP {..." */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 64
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata_806(base_ref, length) -> addr
            {
                let _1 := 0x04
                let _2 := lt(/** @src 0:543:544  "4" */ _1, /** @src 0:27:1457  "contract WARP {..." */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 128
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata_816(base_ref, length) -> addr
            {
                let _1 := 0x05
                let _2 := lt(/** @src 0:1416:1417  "5" */ _1, /** @src 0:27:1457  "contract WARP {..." */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 160
                addr := add(base_ref, _4)
            }
            function read_from_calldatat_address(ptr) -> returnValue
            {
                let value := calldataload(ptr)
                validator_revert_address(value)
                returnValue := value
            }
            function read_from_calldatat_uint256(ptr) -> returnValue
            {
                returnValue := calldataload(ptr)
            }
            function fun_deposit_44(var_sender_offset, var_sender_length, var_value_offset, var_value_29_length)
            {
                let _1 := calldata_array_index_access_address_dyn_calldata(var_sender_offset, var_sender_length)
                let expr := read_from_calldatat_address(_1)
                let _2 := calldata_array_index_access_address_dyn_calldata_806(var_value_offset, var_value_29_length)
                let _3 := read_from_calldatat_uint256(_2)
                fun_deposit(expr, _3)
            }
            function fun_deposit_397_811(var_sender_offset, var_sender_length, var_value_offset, var_value_length)
            {
                /** @ast-id 44 */ /** @ast-id 44 */ fun_deposit_44(/** @ast-id 44 */ var_sender_offset, /** @ast-id 44 */ var_sender_length, /** @ast-id 44 */ var_value_offset, /** @ast-id 44 */ var_value_length)
            }
            function fun_deposit_397(var_sender_offset, var_sender_length, var_value_offset, var_value_length, var_allowance_mapping$addressTmapping$addressTuint)
            {
                /** @ast-id 44 */ /** @ast-id 44 */ fun_deposit_44(/** @ast-id 44 */ var_sender_offset, /** @ast-id 44 */ var_sender_length, /** @ast-id 44 */ var_value_offset, /** @ast-id 44 */ var_value_length)
            }
            function panic_error_0x11()
            {
                let _1 := shl(224, 0x4e487b71)
                let _2 := 0
                mstore(_2, _1)
                let _3 := 0x11
                let _4 := 4
                mstore(_4, _3)
                let _5 := 0x24
                let _6 := _2
                revert(_2, _5)
            }
            function checked_add_uint256(x, y) -> sum
            {
                let _1 := not(y)
                let _2 := gt(x, _1)
                if _2 { panic_error_0x11() }
                sum := add(x, y)
            }
            function update_byte_slice_shift(value, toInsert) -> result
            { result := toInsert }
            function update_storage_value_offsett_uint256_to_uint256(slot, value)
            {
                let _1 := sload(slot)
                let _2 := update_byte_slice_shift(_1, value)
                sstore(slot, _2)
            }
            function fun_deposit(var_sender, var_value)
            {
                let _1 := mapping_index_access_mapping_address_uint256_of_address_807(var_sender)
                let _2 := sload(/** @src 0:634:660  "balanceOf[sender] += value" */ _1)
                let _3 := cleanup_uint256(_2)
                let _4 := checked_add_uint256(/** @src 0:27:1457  "contract WARP {..." */ _3, /** @src 0:634:660  "balanceOf[sender] += value" */ var_value)
                update_storage_value_offsett_uint256_to_uint256(_1, _4)
            }
            function require_helper(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 0
                    let _3 := _2
                    revert(_2, _2)
                }
            }
            function checked_sub_uint256(x, y) -> diff
            {
                let _1 := lt(x, y)
                if _1 { panic_error_0x11() }
                diff := sub(x, y)
            }
            function fun_withdraw(var_wad, var_sender)
            {
                let _1 := mapping_index_access_mapping_address_uint256_of_address_807(var_sender)
                let _2 := read_from_storage_split_dynamic_uint256(_1)
                let _3 := lt(/** @src 0:750:767  "balanceOf[sender]" */ _2, /** @src 0:750:774  "balanceOf[sender] >= wad" */ var_wad)
                let _4 := iszero(_3)
                require_helper(/** @src 0:750:774  "balanceOf[sender] >= wad" */ _4)
                let _5 := mapping_index_access_mapping_address_uint256_of_address_807(var_sender)
                let _6 := sload(/** @src 0:785:809  "balanceOf[sender] -= wad" */ _5)
                let _7 := cleanup_uint256(_6)
                let _8 := checked_sub_uint256(/** @src 0:27:1457  "contract WARP {..." */ _7, /** @src 0:785:809  "balanceOf[sender] -= wad" */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_5, _8)
            }
            function fun_approve(var_guy, var_wad, var_sender) -> var
            {
                let _1 := mapping_index_access_mapping_address_uint256_of_address_810(var_sender)
                let _2 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:918:935  "allowance[sender]" */ _1, /** @src 0:918:940  "allowance[sender][guy]" */ var_guy)
                update_storage_value_offsett_uint256_to_uint256(/** @src 0:918:940  "allowance[sender][guy]" */ _2, /** @src 0:918:946  "allowance[sender][guy] = wad" */ var_wad)
                var := /** @src 0:963:967  "true" */ 0x01
            }
            function fun_transferFrom(var_src, var_dst_offset, var_dst_length, var_wad, var_sender, var_value_114_offset, var_value_length) -> var_
            {
                fun_deposit_397_811(var_dst_offset, var_dst_length, var_value_114_offset, var_value_length)
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:1196:1209  "src != sender" */ var_sender, /** @src 0:27:1457  "contract WARP {..." */ _1)
                let _3 := and(/** @src 0:1196:1209  "src != sender" */ var_src, /** @src 0:27:1457  "contract WARP {..." */ _1)
                let _4 := eq(/** @src 0:27:1457  "contract WARP {..." */ _3, _2)
                let _5 := iszero(_4)
                if /** @src 0:1196:1209  "src != sender" */ _5
                {
                    let _6 := mapping_index_access_mapping_address_uint256_of_address_810(var_src)
                    let _7 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:1233:1247  "allowance[src]" */ _6, /** @src 0:1233:1255  "allowance[src][sender]" */ var_sender)
                    let _8 := read_from_storage_split_dynamic_uint256(_7)
                    let _9 := lt(/** @src 0:1233:1255  "allowance[src][sender]" */ _8, /** @src 0:1233:1262  "allowance[src][sender] >= wad" */ var_wad)
                    let _10 := iszero(_9)
                    require_helper(/** @src 0:1233:1262  "allowance[src][sender] >= wad" */ _10)
                    let _11 := mapping_index_access_mapping_address_uint256_of_address_807(var_src)
                    let _12 := read_from_storage_split_dynamic_uint256(_11)
                    let _13 := cleanup_uint256(/** @src 0:1285:1299  "balanceOf[src]" */ _12)
                    let _14 := lt(_13, var_wad)
                    let _15 := iszero(_14)
                    require_helper(/** @src 0:1285:1306  "balanceOf[src] >= wad" */ _15)
                    let _16 := mapping_index_access_mapping_address_uint256_of_address_810(var_src)
                    let _17 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:1321:1335  "allowance[src]" */ _16, /** @src 0:1321:1343  "allowance[src][sender]" */ var_sender)
                    let _18 := sload(/** @src 0:1321:1350  "allowance[src][sender] -= wad" */ _17)
                    let _19 := cleanup_uint256(_18)
                    let _20 := checked_sub_uint256(/** @src 0:27:1457  "contract WARP {..." */ _19, /** @src 0:1321:1350  "allowance[src][sender] -= wad" */ var_wad)
                    update_storage_value_offsett_uint256_to_uint256(_17, _20)
                }
                let _21 := mapping_index_access_mapping_address_uint256_of_address_807(var_src)
                let _22 := sload(/** @src 0:1371:1392  "balanceOf[src] -= wad" */ _21)
                let _23 := cleanup_uint256(_22)
                let _24 := checked_sub_uint256(/** @src 0:27:1457  "contract WARP {..." */ _23, /** @src 0:1371:1392  "balanceOf[src] -= wad" */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_21, _24)
                let _25 := calldata_array_index_access_address_dyn_calldata_816(var_dst_offset, var_dst_length)
                let _26 := read_from_calldatat_address(_25)
                let _27 := mapping_index_access_mapping_address_uint256_of_address_807(/** @src 0:1412:1418  "dst[5]" */ _26)
                let _28 := sload(/** @src 0:1402:1426  "balanceOf[dst[5]] += wad" */ _27)
                let _29 := cleanup_uint256(_28)
                let _30 := checked_add_uint256(/** @src 0:27:1457  "contract WARP {..." */ _29, /** @src 0:1402:1426  "balanceOf[dst[5]] += wad" */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_27, _30)
                var_ := /** @src 0:1444:1448  "true" */ 0x01
            }
        }
        data ".metadata" hex"a364697066735822122075c170fc966d0284c764e2a6ac7bc78897778001d7f3dfcfb4dd346608f845d86c6578706572696d656e74616cf564736f6c63430008080041"
    }
}
