object "WARP_159" {
    object "WARP_159_deployed" {
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
                    case 0x313ce567 {
                        let _23 := callvalue()
                        if _23
                        {
                            revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                        }
                        let _24 := _4
                        abi_decode(_4)
                        let _25 := _7
                        let _26 := sload(_7)
                        let ret_2 := extract_from_storage_value_dynamict_uint8(_26)
                        let memPos_2 := mload(_1)
                        let _27 := abi_encode_uint8(memPos_2, ret_2)
                        let _28 := sub(_27, memPos_2)
                        return(memPos_2, _28)
                    }
                    case 0x47e7ef24 {
                        let _29 := _4
                        let param_5, param_6 := abi_decode_addresst_uint256(_4)
                        fun_deposit_52(param_5, param_6)
                        let _30 := _7
                        let _31 := mload(_1)
                        return(_31, _7)
                    }
                    case 0x70a08231 {
                        let _32 := callvalue()
                        if _32
                        {
                            revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                        }
                        let _33 := _4
                        let _34 := abi_decode_address(_4)
                        let ret_3 := getter_fun_balanceOf(_34)
                        let memPos_3 := mload(_1)
                        let _35 := abi_encode_uint256(memPos_3, ret_3)
                        let _36 := sub(_35, memPos_3)
                        return(memPos_3, _36)
                    }
                    case 0xcdbe200f {
                        let _37 := _4
                        let param_7, param_8, param_9, param_10, param_11 := abi_decode_addresst_array_address_dyn_calldatat_uint256t_address(_4)
                        let ret_4 := fun_transferFrom(param_7, param_8, param_9, param_10, param_11)
                        let memPos_4 := mload(_1)
                        let _38 := abi_encode_bool(memPos_4, ret_4)
                        let _39 := sub(_38, memPos_4)
                        return(memPos_4, _39)
                    }
                    case 0xdd62ed3e {
                        let _40 := callvalue()
                        if _40
                        {
                            revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                        }
                        let _41 := _4
                        let param_12, param_13 := abi_decode_addresst_address(_4)
                        let _42 := mapping_index_access_mapping_address_uint256_of_address_762(/** @src 0:27:1293  "contract WARP {..." */ param_12)
                        let _43 := mapping_index_access_mapping_address_uint256_of_address(_42, /** @src 0:27:1293  "contract WARP {..." */ param_13)
                        let ret_5 := /** @src 0:247:312  "mapping (address => mapping (address => uint))  public  allowance" */ read_from_storage_split_dynamic_uint256(_43)
                        let memPos_5 := mload(_1)
                        let _44 := abi_encode_uint256(memPos_5, ret_5)
                        let _45 := sub(_44, memPos_5)
                        return(memPos_5, _45)
                    }
                    case 0xefc908a1 {
                        let _46 := _4
                        let param_14, param_15, param_16, param_17 := abi_decode_array_address_dyn_calldatat_array_uint256_dyn_calldata(_4)
                        fun_deposit(param_14, param_15, param_16, param_17)
                        let _47 := _7
                        let _48 := mload(_1)
                        return(_48, _7)
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
            function abi_decode_address_1763() -> value
            {
                let _1 := 36
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1764() -> value
            {
                let _1 := 4
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1765() -> value
            {
                let _1 := 68
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1771() -> value
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
                value1 := abi_decode_address_1763()
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
                value0 := abi_decode_address_1764()
                let _5 := 36
                value1 := calldataload(_5)
                value2 := abi_decode_address_1765()
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
                value0 := abi_decode_address_1764()
                let _5 := 36
                value1 := calldataload(_5)
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
                value0 := abi_decode_address_1764()
            }
            function mapping_index_access_mapping_address_uint256_of_address_762(key) -> dataSlot
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
            function mapping_index_access_mapping_address_uint256_of_address_765(key) -> dataSlot
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
            function mapping_index_access_mapping_address_uint256_of_address_769(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 0x03
                let _5 := 0x20
                mstore(_5, /** @src 0:528:537  "balanceOf" */ _4)
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_uint256_of_address_772(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 0x04
                let _5 := 0x20
                mstore(_5, /** @src 0:812:821  "allowance" */ _4)
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
                let _1 := mapping_index_access_mapping_address_uint256_of_address_765(key)
                ret := read_from_storage_split_dynamic_uint256(_1)
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
            function abi_decode_addresst_array_address_dyn_calldatat_uint256t_address(dataEnd) -> value0, value1, value2, value3, value4
            {
                let _1 := 128
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                value0 := abi_decode_address_1764()
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
                value4 := abi_decode_address_1771()
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
                value0 := abi_decode_address_1764()
                value1 := abi_decode_address_1763()
            }
            function abi_decode_array_address_dyn_calldatat_array_uint256_dyn_calldata(dataEnd) -> value0, value1, value2, value3
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
            function calldata_array_index_access_address_dyn_calldata_767(base_ref, length) -> addr
            {
                let _1 := 0x02
                let _2 := lt(/** @src 0:429:430  "2" */ _1, /** @src 0:27:1293  "contract WARP {..." */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 64
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata_768(base_ref, length) -> addr
            {
                let _1 := 0x04
                let _2 := lt(/** @src 0:439:440  "4" */ _1, /** @src 0:27:1293  "contract WARP {..." */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 128
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata(base_ref, length) -> addr
            {
                let _1 := 0x05
                let _2 := lt(/** @src 0:1252:1253  "5" */ _1, /** @src 0:27:1293  "contract WARP {..." */ length)
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
            function fun_deposit(var_sender_offset, var_sender_length, var_value_offset, var_value_length)
            {
                let _1 := calldata_array_index_access_address_dyn_calldata_767(var_sender_offset, var_sender_length)
                let expr := read_from_calldatat_address(_1)
                let _2 := calldata_array_index_access_address_dyn_calldata_768(var_value_offset, var_value_length)
                let _3 := read_from_calldatat_uint256(_2)
                fun_deposit_52(expr, _3)
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
            function fun_deposit_52(var_sender, var_value)
            {
                let _1 := mapping_index_access_mapping_address_uint256_of_address_769(var_sender)
                let _2 := sload(/** @src 0:528:554  "balanceOf[sender] += value" */ _1)
                let _3 := cleanup_uint256(_2)
                let _4 := checked_add_uint256(/** @src 0:27:1293  "contract WARP {..." */ _3, /** @src 0:528:554  "balanceOf[sender] += value" */ var_value)
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
                let _1 := mapping_index_access_mapping_address_uint256_of_address_769(var_sender)
                let _2 := read_from_storage_split_dynamic_uint256(_1)
                let _3 := lt(/** @src 0:644:661  "balanceOf[sender]" */ _2, /** @src 0:644:668  "balanceOf[sender] >= wad" */ var_wad)
                let _4 := iszero(_3)
                require_helper(/** @src 0:644:668  "balanceOf[sender] >= wad" */ _4)
                let _5 := mapping_index_access_mapping_address_uint256_of_address_769(var_sender)
                let _6 := sload(/** @src 0:679:703  "balanceOf[sender] -= wad" */ _5)
                let _7 := cleanup_uint256(_6)
                let _8 := checked_sub_uint256(/** @src 0:27:1293  "contract WARP {..." */ _7, /** @src 0:679:703  "balanceOf[sender] -= wad" */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_5, _8)
            }
            function fun_approve(var_guy, var_wad, var_sender) -> var
            {
                let _1 := mapping_index_access_mapping_address_uint256_of_address_772(var_sender)
                let _2 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:812:829  "allowance[sender]" */ _1, /** @src 0:812:834  "allowance[sender][guy]" */ var_guy)
                update_storage_value_offsett_uint256_to_uint256(/** @src 0:812:834  "allowance[sender][guy]" */ _2, /** @src 0:812:840  "allowance[sender][guy] = wad" */ var_wad)
                var := /** @src 0:857:861  "true" */ 0x01
            }
            function fun_transferFrom(var_src, var_dst_offset, var_dst_length, var_wad, var_sender) -> var_
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:1032:1045  "src != sender" */ var_sender, /** @src 0:27:1293  "contract WARP {..." */ _1)
                let _3 := and(/** @src 0:1032:1045  "src != sender" */ var_src, /** @src 0:27:1293  "contract WARP {..." */ _1)
                let _4 := eq(/** @src 0:27:1293  "contract WARP {..." */ _3, _2)
                let _5 := iszero(_4)
                if /** @src 0:1032:1045  "src != sender" */ _5
                {
                    let _6 := mapping_index_access_mapping_address_uint256_of_address_772(var_src)
                    let _7 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:1069:1083  "allowance[src]" */ _6, /** @src 0:1069:1091  "allowance[src][sender]" */ var_sender)
                    let _8 := read_from_storage_split_dynamic_uint256(_7)
                    let _9 := lt(/** @src 0:1069:1091  "allowance[src][sender]" */ _8, /** @src 0:1069:1098  "allowance[src][sender] >= wad" */ var_wad)
                    let _10 := iszero(_9)
                    require_helper(/** @src 0:1069:1098  "allowance[src][sender] >= wad" */ _10)
                    let _11 := mapping_index_access_mapping_address_uint256_of_address_769(var_src)
                    let _12 := read_from_storage_split_dynamic_uint256(_11)
                    let _13 := cleanup_uint256(/** @src 0:1121:1135  "balanceOf[src]" */ _12)
                    let _14 := lt(_13, var_wad)
                    let _15 := iszero(_14)
                    require_helper(/** @src 0:1121:1142  "balanceOf[src] >= wad" */ _15)
                    let _16 := mapping_index_access_mapping_address_uint256_of_address_772(var_src)
                    let _17 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:1157:1171  "allowance[src]" */ _16, /** @src 0:1157:1179  "allowance[src][sender]" */ var_sender)
                    let _18 := sload(/** @src 0:1157:1186  "allowance[src][sender] -= wad" */ _17)
                    let _19 := cleanup_uint256(_18)
                    let _20 := checked_sub_uint256(/** @src 0:27:1293  "contract WARP {..." */ _19, /** @src 0:1157:1186  "allowance[src][sender] -= wad" */ var_wad)
                    update_storage_value_offsett_uint256_to_uint256(_17, _20)
                }
                let _21 := mapping_index_access_mapping_address_uint256_of_address_769(var_src)
                let _22 := sload(/** @src 0:1207:1228  "balanceOf[src] -= wad" */ _21)
                let _23 := cleanup_uint256(_22)
                let _24 := checked_sub_uint256(/** @src 0:27:1293  "contract WARP {..." */ _23, /** @src 0:1207:1228  "balanceOf[src] -= wad" */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_21, _24)
                let _25 := calldata_array_index_access_address_dyn_calldata(var_dst_offset, var_dst_length)
                let _26 := read_from_calldatat_address(_25)
                let _27 := mapping_index_access_mapping_address_uint256_of_address_769(/** @src 0:1248:1254  "dst[5]" */ _26)
                let _28 := sload(/** @src 0:1238:1262  "balanceOf[dst[5]] += wad" */ _27)
                let _29 := cleanup_uint256(_28)
                let _30 := checked_add_uint256(/** @src 0:27:1293  "contract WARP {..." */ _29, /** @src 0:1238:1262  "balanceOf[dst[5]] += wad" */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_27, _30)
                var_ := /** @src 0:1280:1284  "true" */ 0x01
            }
        }
        data ".metadata" hex"a364697066735822122078e20fa5ee0a44d94f78f5be48060d30f0a3e06f2d2ea75186d705e53ccbf0376c6578706572696d656e74616cf564736f6c63430008080041"
    }
}
