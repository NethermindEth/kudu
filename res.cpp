1
1
1
2
2
1
2
1
1
/*=====================================================*
 *                       WARNING                       *
 *  Solidity to Yul compilation is still EXPERIMENTAL  *
 *       It can result in LOSS OF FUNDS or worse       *
 *                !USE AT YOUR OWN RISK!               *
 *=====================================================*/

/// @use-src 0:"ERC20_marked.sol", 1:"#utility.yul"
object "WARP_167" {
    code {
        {
            /// @src 0:27:1383
            let _1 := 128
            let _2 := 64
            mstore(_2, _1)
            let _3 := callvalue()
            if _3
            {
                revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
            }
            constructor_WARP()
            let _4 := datasize("WARP_167_deployed")
            let _5 := dataoffset("WARP_167_deployed")
            let _6 := _1
            codecopy(_1, _5, _4)
            let _7 := _1
            return(_1, _4)
        }
        function constructor_WARP()
        {
            /// @src 0:76:78
            update_storage_value_offsett_rational_by_to_uint8()
            /// @src 0:113:149
            update_storage_value_offsett_rational_by_to_uint256()
        }
        /// @src 0:27:1383
        function revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
        {
            let _1 := 0
            let _2 := _1
            revert(_1, _1)
        }
        function update_byte_slice_shift_117(value) -> result
        {
            /// @src 0:76:78
            let _1 := 0x12
            /// @src 0:27:1383
            let _2 := not(255)
            let _3 := and(value, _2)
            result := or(_3, /** @src 0:76:78 */ _1)
        }
        /// @src 0:27:1383
        function update_byte_slice_shift(value) -> result
        {
            result := /** @src 0:113:149 */ 0x13426172c74d822b878fe800000000
        }
        /// @src 0:27:1383
        function update_storage_value_offsett_rational_by_to_uint256()
        {
            /// @src 0:113:149
            let _1 := 0x01
            /// @src 0:27:1383
            let _2 := sload(/** @src 0:113:149 */ _1)
            /// @src 0:27:1383
            let _3 := update_byte_slice_shift(_2)
            /// @src 0:113:149
            let _4 := _1
            /// @src 0:27:1383
            sstore(/** @src 0:113:149 */ _1, /** @src 0:27:1383 */ _3)
        }
        function update_storage_value_offsett_rational_by_to_uint8()
        {
            /// @src 0:76:78
            let _1 := 0x00
            /// @src 0:27:1383
            let _2 := sload(/** @src 0:76:78 */ _1)
            /// @src 0:27:1383
            let _3 := update_byte_slice_shift_117(_2)
            /// @src 0:76:78
            let _4 := _1
            /// @src 0:27:1383
            sstore(/** @src 0:76:78 */ _1, /** @src 0:27:1383 */ _3)
        }
    }
    object "WARP_167_deployed" {
        code {
            {
                /// @src 0:27:1383
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
                            revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                        }
                        let _18 := _4
                        abi_decode(_4)
                        /// @src 0:84:149
                        let _19 := 1
                        /// @src 0:27:1383
                        let _20 := sload(/** @src 0:84:149 */ _19)
                        /// @src 0:27:1383
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
                            revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
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
                    case 0x51984eb3 {
                        let _29 := _4
                        let param_5, param_6, param_7, param_8 := abi_decode_array_address_dyn_calldatat_array_uint256_dyn_calldata(_4)
                        fun_deposit_dynArgs(param_5, param_6, param_7, param_8)
                        let _30 := _7
                        let _31 := mload(_1)
                        return(_31, _7)
                    }
                    case 0x70a08231 {
                        let _32 := callvalue()
                        if _32
                        {
                            revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                        }
                        let _33 := _4
                        let _34 := abi_decode_address(_4)
                        let ret_3 := getter_fun_balanceOf(_34)
                        let memPos_3 := mload(_1)
                        let _35 := abi_encode_uint256(memPos_3, ret_3)
                        let _36 := sub(_35, memPos_3)
                        return(memPos_3, _36)
                    }
                    case 0x90f8fa2d {
                        let _37 := _4
                        let param_9, param_10, param_11, param_12, param_13, param_14, param_15 := abi_decode_addresst_array_address_dyn_calldatat_uint256t_addresst_array_uint256_dyn_calldata(_4)
                        let ret_4 := fun_transferFrom_dynArgs(param_9, param_10, param_11, param_12, param_13, param_14, param_15)
                        let memPos_4 := mload(_1)
                        let _38 := abi_encode_bool(memPos_4, ret_4)
                        let _39 := sub(_38, memPos_4)
                        return(memPos_4, _39)
                    }
                    case 0xacc77ab5 {
                        let _40 := _4
                        let param_16, param_17 := abi_decode_addresst_uint256(_4)
                        fun_deposit(param_16, param_17)
                        let _41 := _7
                        let _42 := mload(_1)
                        return(_42, _7)
                    }
                    case 0xdd62ed3e {
                        let _43 := callvalue()
                        if _43
                        {
                            revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                        }
                        let _44 := _4
                        let param_18, param_19 := abi_decode_addresst_address(_4)
                        /// @src 0:249:314
                        let _45 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_768(/** @src 0:27:1383 */ param_18)
                        /// @src 0:249:314
                        let _46 := mapping_index_access_mapping_address_mapping_address_uint256_of_address(_45, /** @src 0:27:1383 */ param_19)
                        let ret_5 := /** @src 0:249:314 */ read_from_storage_split_dynamic_uint256(_46)
                        /// @src 0:27:1383
                        let memPos_5 := mload(_1)
                        let _47 := abi_encode_uint256(memPos_5, ret_5)
                        let _48 := sub(_47, memPos_5)
                        return(memPos_5, _48)
                    }
                }
                revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
            }
            function abi_decode_address_1770() -> value
            {
                let _1 := 4
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1772() -> value
            {
                let _1 := 36
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1774() -> value
            {
                let _1 := 100
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1777() -> value
            {
                let _1 := 68
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_array_address_dyn_calldata(offset, end) -> arrayPos, length
            {
                let _1 := 0x1f
                let _2 := add(offset, _1)
                let _3 := slt(_2, end)
                let _4 := iszero(_3)
                if _4
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                length := calldataload(offset)
                let _5 := sub(shl(64, 1), 1)
                let _6 := gt(length, _5)
                if _6
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
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
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
            }
            function abi_decode(dataEnd)
            {
                let _1 := 0
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
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
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                value0 := abi_decode_address_1770()
            }
            function abi_decode_addresst_address(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                value0 := abi_decode_address_1770()
                value1 := abi_decode_address_1772()
            }
            function abi_decode_addresst_array_address_dyn_calldatat_uint256t_addresst_array_uint256_dyn_calldata(dataEnd) -> value0, value1, value2, value3, value4, value5, value6
            {
                let _1 := 160
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                value0 := abi_decode_address_1770()
                let _5 := 36
                let offset := calldataload(_5)
                let _6 := sub(shl(64, 1), 1)
                let _7 := gt(offset, _6)
                if _7
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                let _8 := 4
                let _9 := add(_8, offset)
                let value1_1, value2_1 := abi_decode_array_address_dyn_calldata(_9, dataEnd)
                value1 := value1_1
                value2 := value2_1
                let _10 := 68
                value3 := calldataload(_10)
                value4 := abi_decode_address_1774()
                let _11 := 132
                let offset_1 := calldataload(_11)
                let _12 := gt(offset_1, _6)
                if _12
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
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
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                value0 := abi_decode_address_1770()
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
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                value0 := abi_decode_address_1770()
                let _5 := 36
                value1 := calldataload(_5)
                value2 := abi_decode_address_1777()
            }
            function abi_decode_array_address_dyn_calldatat_array_uint256_dyn_calldata(dataEnd) -> value0, value1, value2, value3
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                let _5 := 4
                let offset := calldataload(_5)
                let _6 := sub(shl(64, 1), 1)
                let _7 := gt(offset, _6)
                if _7
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
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
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                let _12 := _5
                let _13 := add(_5, offset_1)
                let value2_1, value3_1 := abi_decode_array_address_dyn_calldata(_13, dataEnd)
                value2 := value2_1
                value3 := value3_1
            }
            function abi_decode_uint256t_address(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                }
                let _5 := 4
                value0 := calldataload(_5)
                value1 := abi_decode_address_1772()
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
            function calldata_array_index_access_address_dyn_calldata_772(base_ref, length) -> addr
            {
                /// @src 0:444:445
                let _1 := 0x02
                /// @src 0:27:1383
                let _2 := lt(/** @src 0:444:445 */ _1, /** @src 0:27:1383 */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 64
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata_773(base_ref, length) -> addr
            {
                /// @src 0:454:455
                let _1 := 0x04
                /// @src 0:27:1383
                let _2 := lt(/** @src 0:454:455 */ _1, /** @src 0:27:1383 */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 128
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata(base_ref, length) -> addr
            {
                /// @src 0:1342:1343
                let _1 := 0x05
                /// @src 0:27:1383
                let _2 := lt(/** @src 0:1342:1343 */ _1, /** @src 0:27:1383 */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 160
                addr := add(base_ref, _4)
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
            /// @src 0:735:887
            function fun_approve(var_guy, var_wad, var_sender) -> var
            {
                /// @src 0:831:848
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_770(var_sender)
                /// @src 0:831:853
                let _2 := mapping_index_access_mapping_address_mapping_address_uint256_of_address(/** @src 0:831:848 */ _1, /** @src 0:831:853 */ var_guy)
                /// @src 0:831:859
                update_storage_value_offsett_uint256_to_uint256(/** @src 0:831:853 */ _2, /** @src 0:831:859 */ var_wad)
                /// @src 0:869:880
                var := /** @src 0:876:880 */ 0x01
            }
            /// @src 0:470:580
            function fun_deposit(var_sender, var_value)
            {
                /// @src 0:547:564
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_771(var_sender)
                /// @src 0:27:1383
                let _2 := sload(/** @src 0:547:573 */ _1)
                /// @src 0:27:1383
                let _3 := cleanup_from_storage_uint256(_2)
                /// @src 0:547:573
                let _4 := checked_add_uint256(/** @src 0:27:1383 */ _3, /** @src 0:547:573 */ var_value)
                update_storage_value_offsett_uint256_to_uint256(_1, _4)
            }
            /// @src 0:322:464
            function fun_deposit_dynArgs(var_sender_offset, var_sender_length, var_value_offset, var_value_25_length)
            {
                /// @src 0:437:446
                let _1 := calldata_array_index_access_address_dyn_calldata_772(var_sender_offset, var_sender_length)
                let expr := read_from_calldatat_address(_1)
                /// @src 0:448:456
                let _2 := calldata_array_index_access_address_dyn_calldata_773(var_value_offset, var_value_25_length)
                let _3 := read_from_calldatat_uint256(_2)
                fun_deposit(expr, _3)
            }
            /// @src 0:893:1381
            function fun_transferFrom_dynArgs(var_src, var_dst_offset, var_dst_length, var_wad, var_sender, var_value_108_offset, var_value_length) -> var_
            {
                /// @src 0:1102:1107
                fun_deposit_dynArgs(var_dst_offset, var_dst_length, var_value_108_offset, var_value_length)
                /// @src 0:27:1383
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:1122:1135 */ var_sender, /** @src 0:27:1383 */ _1)
                let _3 := and(/** @src 0:1122:1135 */ var_src, /** @src 0:27:1383 */ _1)
                /// @src 0:1122:1135
                let _4 := eq(/** @src 0:27:1383 */ _3, _2)
                /// @src 0:1122:1135
                let _5 := iszero(_4)
                /// @src 0:1118:1287
                if /** @src 0:1122:1135 */ _5
                /// @src 0:1118:1287
                {
                    /// @src 0:1159:1173
                    let _6 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_770(var_src)
                    /// @src 0:1159:1181
                    let _7 := mapping_index_access_mapping_address_mapping_address_uint256_of_address(/** @src 0:1159:1173 */ _6, /** @src 0:1159:1181 */ var_sender)
                    let _8 := read_from_storage_split_dynamic_uint256(_7)
                    /// @src 0:1159:1188
                    let _9 := lt(/** @src 0:1159:1181 */ _8, /** @src 0:1159:1188 */ var_wad)
                    let _10 := iszero(_9)
                    /// @src 0:1151:1189
                    require_helper(/** @src 0:1159:1188 */ _10)
                    /// @src 0:1211:1225
                    let _11 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_771(var_src)
                    let _12 := read_from_storage_split_dynamic_uint256(_11)
                    /// @src 0:1211:1232
                    let _13 := cleanup_from_storage_uint256(/** @src 0:1211:1225 */ _12)
                    /// @src 0:1211:1232
                    let _14 := lt(_13, var_wad)
                    let _15 := iszero(_14)
                    /// @src 0:1203:1233
                    require_helper(/** @src 0:1211:1232 */ _15)
                    /// @src 0:1247:1261
                    let _16 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_770(var_src)
                    /// @src 0:1247:1269
                    let _17 := mapping_index_access_mapping_address_mapping_address_uint256_of_address(/** @src 0:1247:1261 */ _16, /** @src 0:1247:1269 */ var_sender)
                    /// @src 0:27:1383
                    let _18 := sload(/** @src 0:1247:1276 */ _17)
                    /// @src 0:27:1383
                    let _19 := cleanup_from_storage_uint256(_18)
                    /// @src 0:1247:1276
                    let _20 := checked_sub_uint256(/** @src 0:27:1383 */ _19, /** @src 0:1247:1276 */ var_wad)
                    update_storage_value_offsett_uint256_to_uint256(_17, _20)
                }
                /// @src 0:1297:1311
                let _21 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_771(var_src)
                /// @src 0:27:1383
                let _22 := sload(/** @src 0:1297:1318 */ _21)
                /// @src 0:27:1383
                let _23 := cleanup_from_storage_uint256(_22)
                /// @src 0:1297:1318
                let _24 := checked_sub_uint256(/** @src 0:27:1383 */ _23, /** @src 0:1297:1318 */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_21, _24)
                /// @src 0:1338:1344
                let _25 := calldata_array_index_access_address_dyn_calldata(var_dst_offset, var_dst_length)
                let _26 := read_from_calldatat_address(_25)
                /// @src 0:1328:1345
                let _27 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_771(/** @src 0:1338:1344 */ _26)
                /// @src 0:27:1383
                let _28 := sload(/** @src 0:1328:1352 */ _27)
                /// @src 0:27:1383
                let _29 := cleanup_from_storage_uint256(_28)
                /// @src 0:1328:1352
                let _30 := checked_add_uint256(/** @src 0:27:1383 */ _29, /** @src 0:1328:1352 */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_27, _30)
                /// @src 0:1363:1374
                var_ := /** @src 0:1370:1374 */ 0x01
            }
            /// @src 0:586:729
            function fun_withdraw(var_wad, var_sender)
            {
                /// @src 0:663:680
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_771(var_sender)
                let _2 := read_from_storage_split_dynamic_uint256(_1)
                /// @src 0:663:687
                let _3 := lt(/** @src 0:663:680 */ _2, /** @src 0:663:687 */ var_wad)
                let _4 := iszero(_3)
                /// @src 0:655:688
                require_helper(/** @src 0:663:687 */ _4)
                /// @src 0:698:715
                let _5 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_771(var_sender)
                /// @src 0:27:1383
                let _6 := sload(/** @src 0:698:722 */ _5)
                /// @src 0:27:1383
                let _7 := cleanup_from_storage_uint256(_6)
                /// @src 0:698:722
                let _8 := checked_sub_uint256(/** @src 0:27:1383 */ _7, /** @src 0:698:722 */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_5, _8)
            }
            /// @src 0:178:243
            function getter_fun_balanceOf(key) -> ret
            {
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_782(key)
                ret := read_from_storage_split_dynamic_uint256(_1)
            }
            /// @src 0:27:1383
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_768(key) -> dataSlot
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
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_770(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:831:840
                let _4 := 0x04
                /// @src 0:27:1383
                let _5 := 0x20
                mstore(_5, /** @src 0:831:840 */ _4)
                /// @src 0:27:1383
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_771(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:547:556
                let _4 := 0x03
                /// @src 0:27:1383
                let _5 := 0x20
                mstore(_5, /** @src 0:547:556 */ _4)
                /// @src 0:27:1383
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_782(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:178:243
                let _4 := 3
                /// @src 0:27:1383
                let _5 := 0x20
                mstore(_5, /** @src 0:178:243 */ _4)
                /// @src 0:27:1383
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
            function revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
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
        data ".metadata" hex"a2646970667358221220edff6b428b1bf3c403014ea9551a8dc75561604765bfb25ba6e60f515ef020cc64736f6c637827302e382e372d646576656c6f702e323032312e392e31332b636f6d6d69742e65323864303061370058"
    }
}

