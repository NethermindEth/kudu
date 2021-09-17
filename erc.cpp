object "WARP_135" {
    code {
    }
    object "WARP_135_deployed" {
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
                            revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                        }
                        let _18 := _4
                        abi_decode(_4)
                        let _19 := 1
                        let _20 := sload( _19)
                        let ret_1 := cleanup_from_storage_uint256(_20)
                        let memPos_1 := mload(_1)
                        let _21 := abi_encode_uint256(memPos_1, ret_1)
                        let _22 := sub(_21, memPos_1)
                        return(memPos_1, _22)
                    }
                    case 0x313ce567 {
                        let _23 := callvalue()
                        if _23
                        {
                            revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
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
                        fun_deposit(param_5, param_6)
                        let _30 := _7
                        let _31 := mload(_1)
                        return(_31, _7)
                    }
                    case 0x5fc9309c {
                        let _32 := _4
                        let param_7, param_8, param_9, param_10 := abi_decode_addresst_addresst_uint256t_address(_4)
                        let ret_3 := fun_transferFrom(param_7, param_8, param_9, param_10)
                        let memPos_3 := mload(_1)
                        let _33 := abi_encode_bool(memPos_3, ret_3)
                        let _34 := sub(_33, memPos_3)
                        return(memPos_3, _34)
                    }
                    case 0x70a08231 {
                        let _35 := callvalue()
                        if _35
                        {
                            revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                        }
                        let _36 := _4
                        let _37 := abi_decode_address(_4)
                        let ret_4 := getter_fun_balanceOf(_37)
                        let memPos_4 := mload(_1)
                        let _38 := abi_encode_uint256(memPos_4, ret_4)
                        let _39 := sub(_38, memPos_4)
                        return(memPos_4, _39)
                    }
                    case 0xdd62ed3e {
                        let _40 := callvalue()
                        if _40
                        {
                            revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                        }
                        let _41 := _4
                        let param_11, param_12 := abi_decode_addresst_address(_4)
                        let _42 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_613( param_11)
                        let _43 := mapping_index_access_mapping_address_mapping_address_uint256_of_address(_42,  param_12)
                        let ret_5 :=  read_from_storage_split_dynamic_uint256(_43)
                        let memPos_5 := mload(_1)
                        let _44 := abi_encode_uint256(memPos_5, ret_5)
                        let _45 := sub(_44, memPos_5)
                        return(memPos_5, _45)
                    }
                }
                revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
            }
            function abi_decode_address_1378() -> value
            {
                let _1 := 4
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1380() -> value
            {
                let _1 := 36
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1383() -> value
            {
                let _1 := 100
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1386() -> value
            {
                let _1 := 68
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode(dataEnd)
            {
                let _1 := 0
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                }
            }
            function abi_decode_address(dataEnd) -> value0
            {
                let _1 := 32
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                }
                value0 := abi_decode_address_1378()
            }
            function abi_decode_addresst_address(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                }
                value0 := abi_decode_address_1378()
                value1 := abi_decode_address_1380()
            }
            function abi_decode_addresst_addresst_uint256t_address(dataEnd) -> value0, value1, value2, value3
            {
                let _1 := 128
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                }
                value0 := abi_decode_address_1378()
                value1 := abi_decode_address_1380()
                let _5 := 68
                value2 := calldataload(_5)
                value3 := abi_decode_address_1383()
            }
            function abi_decode_addresst_uint256(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                }
                value0 := abi_decode_address_1378()
                let _5 := 36
                value1 := calldataload(_5)
            }
            function abi_decode_addresst_uint256t_address(dataEnd) -> value0, value1, value2
            {
                let _1 := 96
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                }
                value0 := abi_decode_address_1378()
                let _5 := 36
                value1 := calldataload(_5)
                value2 := abi_decode_address_1386()
            }
            function abi_decode_uint256t_address(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
                }
                let _5 := 4
                value0 := calldataload(_5)
                value1 := abi_decode_address_1380()
            }
            function abi_encode_bool_to_bool(value, pos)
            {
                let _1 := iszero(value)
                let _2 := iszero(_1)
                mstore(pos, _2)
            }
            function abi_encode_uint256_to_uint256(value, pos)
            { mstore(pos, value) }
            function abi_encode_uint8_to_uint8(value, pos)
            {
                let _1 := 0xff
                let _2 := and(value, _1)
                mstore(pos, _2)
            }
            function abi_encode_bool(headStart, value0) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_bool_to_bool(value0, headStart)
            }
            function abi_encode_uint256(headStart, value0) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_uint256_to_uint256(value0, headStart)
            }
            function abi_encode_uint8(headStart, value0) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_uint8_to_uint8(value0, headStart)
            }
            function checked_add_uint256(x, y) -> sum
            {
                let _1 := not(y)
                let _2 := gt(x, _1)
                if _2 { panic_error_0x11() }
                sum := add(x, y)
            }
            function checked_sub_uint256(x, y) -> diff
            {
                let _1 := lt(x, y)
                if _1 { panic_error_0x11() }
                diff := sub(x, y)
            }
            function cleanup_from_storage_uint256(value) -> cleaned
            { cleaned := value }
            function extract_from_storage_value_dynamict_uint8(slot_value) -> value
            {
                let _1 := 0xff
                value := and(slot_value, _1)
            }
            function fun_approve(var_guy, var_wad, var_sender) -> var_
            {
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_615(var_sender)
                let _2 := mapping_index_access_mapping_address_mapping_address_uint256_of_address( _1,  var_guy)
                update_storage_value_offsett_uint256_to_uint256( _2,  var_wad)
                var_ :=  0x01
            }
            function fun_deposit(var_sender, var_value)
            {
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_616(var_sender)
                let _2 := sload( _1)
                let _3 := cleanup_from_storage_uint256(_2)
                let _4 := checked_add_uint256( _3,  var_value)
                update_storage_value_offsett_uint256_to_uint256(_1, _4)
            }
            function fun_transferFrom(var_src, var_dst, var_wad, var_sender) -> var
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and( var_sender,  _1)
                let _3 := and( var_src,  _1)
                let _4 := eq( _3, _2)
                let _5 := iszero(_4)
                if  _5
                {
                    let _6 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_615(var_src)
                    let _7 := mapping_index_access_mapping_address_mapping_address_uint256_of_address( _6,  var_sender)
                    let _8 := read_from_storage_split_dynamic_uint256(_7)
                    let _9 := lt( _8,  var_wad)
                    let _10 := iszero(_9)
                    require_helper( _10)
                    let _11 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_616(var_src)
                    let _12 := read_from_storage_split_dynamic_uint256(_11)
                    let _13 := cleanup_from_storage_uint256( _12)
                    let _14 := lt(_13, var_wad)
                    let _15 := iszero(_14)
                    require_helper( _15)
                    let _16 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_615(var_src)
                    let _17 := mapping_index_access_mapping_address_mapping_address_uint256_of_address( _16,  var_sender)
                    let _18 := sload( _17)
                    let _19 := cleanup_from_storage_uint256(_18)
                    let _20 := checked_sub_uint256( _19,  var_wad)
                    update_storage_value_offsett_uint256_to_uint256(_17, _20)
                }
                let _21 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_616(var_src)
                let _22 := sload( _21)
                let _23 := cleanup_from_storage_uint256(_22)
                let _24 := checked_sub_uint256( _23,  var_wad)
                update_storage_value_offsett_uint256_to_uint256(_21, _24)
                let _25 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_616(var_dst)
                let _26 := sload( _25)
                let _27 := cleanup_from_storage_uint256(_26)
                let _28 := checked_add_uint256( _27,  var_wad)
                update_storage_value_offsett_uint256_to_uint256(_25, _28)
                var :=  0x01
            }
            function fun_withdraw(var_wad, var_sender)
            {
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_616(var_sender)
                let _2 := read_from_storage_split_dynamic_uint256(_1)
                let _3 := lt( _2,  var_wad)
                let _4 := iszero(_3)
                require_helper( _4)
                let _5 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_616(var_sender)
                let _6 := sload( _5)
                let _7 := cleanup_from_storage_uint256(_6)
                let _8 := checked_sub_uint256( _7,  var_wad)
                update_storage_value_offsett_uint256_to_uint256(_5, _8)
            }
            function getter_fun_balanceOf(key) -> ret
            {
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_624(key)
                ret := read_from_storage_split_dynamic_uint256(_1)
            }
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_613(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 3
                let _5 := 0x20
                mstore(_5,  _4)
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_615(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 0x03
                let _5 := 0x20
                mstore(_5,  _4)
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_616(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 0x02
                let _5 := 0x20
                mstore(_5,  _4)
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_624(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                let _4 := 2
                let _5 := 0x20
                mstore(_5,  _4)
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address(slot, key) -> dataSlot
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
            function read_from_storage_split_dynamic_uint256(slot) -> value
            {
                let _1 := sload(slot)
                value := cleanup_from_storage_uint256(_1)
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
            function revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
            {
                let _1 := 0
                let _2 := _1
                revert(_1, _1)
            }
            function update_byte_slice_shift(value, toInsert) -> result
            { result := toInsert }
            function update_storage_value_offsett_uint256_to_uint256(slot, value)
            {
                let _1 := sload(slot)
                let _2 := update_byte_slice_shift(_1, value)
                sstore(slot, _2)
            }
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
        }
        data ".metadata" hex"a264697066735822122028d80bcbb07ba26c8c4d7e2c225305e163bd1b2a34baa8e2ef4e09521cf1aa4364736f6c63430008070033"
    }
}
