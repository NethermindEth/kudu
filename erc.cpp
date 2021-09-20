object "WARP_174" {
	code {
		//holder
	}

    object "WARP_174_deployed" {
        code {
            function abi_decode_address_1806() -> value
            {
                let _1 := 4
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1808() -> value
            {
                let _1 := 36
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1810() -> value
            {
                let _1 := 100
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1813() -> value
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
                value0 := abi_decode_address_1806()
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
                value0 := abi_decode_address_1806()
                value1 := abi_decode_address_1808()
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
                value0 := abi_decode_address_1806()
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
                value4 := abi_decode_address_1810()
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
                value0 := abi_decode_address_1806()
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
                value0 := abi_decode_address_1806()
                let _5 := 36
                value1 := calldataload(_5)
                value2 := abi_decode_address_1813()
            }
            function abi_decode_array_address_dyn_calldatat_array_uint256_dyn_calldatat_uint256(dataEnd) -> value0, value1, value2, value3, value4
            {
                let _1 := 96
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
                let _14 := 68
                value4 := calldataload(_14)
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
                value1 := abi_decode_address_1808()
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
            function calldata_array_index_access_address_dyn_calldata_789(base_ref, length) -> addr
            {
                /// @src 0:541:542
                let _1 := 0x02
                /// @src 0:27:1481
                let _2 := lt(/** @src 0:541:542 */ _1, /** @src 0:27:1481 */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 64
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata(base_ref, length) -> addr
            {
                /// @src 0:551:552
                let _1 := 0x04
                /// @src 0:27:1481
                let _2 := lt(/** @src 0:551:552 */ _1, /** @src 0:27:1481 */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 128
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata_796(base_ref, length) -> addr
            {
                /// @src 0:1440:1441
                let _1 := 0x05
                /// @src 0:27:1481
                let _2 := lt(/** @src 0:1440:1441 */ _1, /** @src 0:27:1481 */ length)
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
            /// @src 0:830:982
            function fun_approve(var_guy, var_wad, var_sender) -> var
            {
                /// @src 0:926:943
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_787(var_sender)
                /// @src 0:926:948
                let _2 := mapping_index_access_mapping_address_mapping_address_uint256_of_address(/** @src 0:926:943 */ _1, /** @src 0:926:948 */ var_guy)
                /// @src 0:926:954
                update_storage_value_offsett_uint256_to_uint256(/** @src 0:926:948 */ _2, /** @src 0:926:954 */ var_wad)
                /// @src 0:964:975
                var := /** @src 0:971:975 */ 0x01
            }
            /// @src 0:567:675
            function fun_deposit(var_sender, var_value)
            {
                /// @src 0:642:659
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_788(var_sender)
                /// @src 0:27:1481
                let _2 := sload(/** @src 0:642:668 */ _1)
                /// @src 0:27:1481
                let _3 := cleanup_from_storage_uint256(_2)
                /// @src 0:642:668
                let _4 := checked_add_uint256(/** @src 0:27:1481 */ _3, /** @src 0:642:668 */ var_value)
                update_storage_value_offsett_uint256_to_uint256(_1, _4)
            }
            /// @src 0:366:561
            function fun_deposit_dynArgs(var_sender_offset, var_sender_length, var_value_offset, var_value_29_length)
            {
                /// @src 0:534:543
                let _1 := calldata_array_index_access_address_dyn_calldata_789(var_sender_offset, var_sender_length)
                let expr := read_from_calldatat_address(_1)
                /// @src 0:545:553
                let _2 := calldata_array_index_access_address_dyn_calldata(var_value_offset, var_value_29_length)
                let _3 := read_from_calldatat_uint256(_2)
                fun_deposit(expr, _3)
            }
            /// @src 0:366:561
            function fun_deposit_dynArgs_791(var_sender_offset, var_sender_length, var_value_offset, var_value_length)
            {
                fun_deposit_dynArgs(var_sender_offset, var_sender_length, var_value_offset, var_value_length)
            }
            function fun_deposit_dynArgs_380(var_sender_offset, var_sender_length, var_value_offset, var_value_length, var_allowance_mapping$addressTmapping$addressTuint)
            {
                fun_deposit_dynArgs(var_sender_offset, var_sender_length, var_value_offset, var_value_length)
            }
            /// @src 0:988:1479
            function fun_transferFrom_dynArgs(var_src, var_dst_offset, var_dst_length, var_wad, var_sender, var_value_114_offset, var_value_length) -> var_
            {
                /// @src 0:1176:1206
                fun_deposit_dynArgs_791(var_dst_offset, var_dst_length, var_value_114_offset, var_value_length)
                /// @src 0:27:1481
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:1220:1233 */ var_sender, /** @src 0:27:1481 */ _1)
                let _3 := and(/** @src 0:1220:1233 */ var_src, /** @src 0:27:1481 */ _1)
                /// @src 0:1220:1233
                let _4 := eq(/** @src 0:27:1481 */ _3, _2)
                /// @src 0:1220:1233
                let _5 := iszero(_4)
                /// @src 0:1216:1385
                if /** @src 0:1220:1233 */ _5
                /// @src 0:1216:1385
                {
                    /// @src 0:1257:1271
                    let _6 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_787(var_src)
                    /// @src 0:1257:1279
                    let _7 := mapping_index_access_mapping_address_mapping_address_uint256_of_address(/** @src 0:1257:1271 */ _6, /** @src 0:1257:1279 */ var_sender)
                    let _8 := read_from_storage_split_dynamic_uint256(_7)
                    /// @src 0:1257:1286
                    let _9 := lt(/** @src 0:1257:1279 */ _8, /** @src 0:1257:1286 */ var_wad)
                    let _10 := iszero(_9)
                    /// @src 0:1249:1287
                    require_helper(/** @src 0:1257:1286 */ _10)
                    /// @src 0:1309:1323
                    let _11 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_788(var_src)
                    let _12 := read_from_storage_split_dynamic_uint256(_11)
                    /// @src 0:1309:1330
                    let _13 := cleanup_from_storage_uint256(/** @src 0:1309:1323 */ _12)
                    /// @src 0:1309:1330
                    let _14 := lt(_13, var_wad)
                    let _15 := iszero(_14)
                    /// @src 0:1301:1331
                    require_helper(/** @src 0:1309:1330 */ _15)
                    /// @src 0:1345:1359
                    let _16 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_787(var_src)
                    /// @src 0:1345:1367
                    let _17 := mapping_index_access_mapping_address_mapping_address_uint256_of_address(/** @src 0:1345:1359 */ _16, /** @src 0:1345:1367 */ var_sender)
                    /// @src 0:27:1481
                    let _18 := sload(/** @src 0:1345:1374 */ _17)
                    /// @src 0:27:1481
                    let _19 := cleanup_from_storage_uint256(_18)
                    /// @src 0:1345:1374
                    let _20 := checked_sub_uint256(/** @src 0:27:1481 */ _19, /** @src 0:1345:1374 */ var_wad)
                    update_storage_value_offsett_uint256_to_uint256(_17, _20)
                }
                /// @src 0:1395:1409
                let _21 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_788(var_src)
                /// @src 0:27:1481
                let _22 := sload(/** @src 0:1395:1416 */ _21)
                /// @src 0:27:1481
                let _23 := cleanup_from_storage_uint256(_22)
                /// @src 0:1395:1416
                let _24 := checked_sub_uint256(/** @src 0:27:1481 */ _23, /** @src 0:1395:1416 */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_21, _24)
                /// @src 0:1436:1442
                let _25 := calldata_array_index_access_address_dyn_calldata_796(var_dst_offset, var_dst_length)
                let _26 := read_from_calldatat_address(_25)
                /// @src 0:1426:1443
                let _27 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_788(/** @src 0:1436:1442 */ _26)
                /// @src 0:27:1481
                let _28 := sload(/** @src 0:1426:1450 */ _27)
                /// @src 0:27:1481
                let _29 := cleanup_from_storage_uint256(_28)
                /// @src 0:1426:1450
                let _30 := checked_add_uint256(/** @src 0:27:1481 */ _29, /** @src 0:1426:1450 */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_27, _30)
                /// @src 0:1461:1472
                var_ := /** @src 0:1468:1472 */ 0x01
            }
            /// @src 0:681:824
            function fun_withdraw(var_wad, var_sender)
            {
                /// @src 0:758:775
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_788(var_sender)
                let _2 := read_from_storage_split_dynamic_uint256(_1)
                /// @src 0:758:782
                let _3 := lt(/** @src 0:758:775 */ _2, /** @src 0:758:782 */ var_wad)
                let _4 := iszero(_3)
                /// @src 0:750:783
                require_helper(/** @src 0:758:782 */ _4)
                /// @src 0:793:810
                let _5 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_788(var_sender)
                /// @src 0:27:1481
                let _6 := sload(/** @src 0:793:817 */ _5)
                /// @src 0:27:1481
                let _7 := cleanup_from_storage_uint256(_6)
                /// @src 0:793:817
                let _8 := checked_sub_uint256(/** @src 0:27:1481 */ _7, /** @src 0:793:817 */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_5, _8)
            }
            /// @src 0:176:241
            function getter_fun_balanceOf(key) -> ret
            {
                let _1 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_800(key)
                ret := read_from_storage_split_dynamic_uint256(_1)
            }
            /// @src 0:27:1481
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_785(key) -> dataSlot
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
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_787(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:926:935
                let _4 := 0x04
                /// @src 0:27:1481
                let _5 := 0x20
                mstore(_5, /** @src 0:926:935 */ _4)
                /// @src 0:27:1481
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_788(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:642:651
                let _4 := 0x03
                /// @src 0:27:1481
                let _5 := 0x20
                mstore(_5, /** @src 0:642:651 */ _4)
                /// @src 0:27:1481
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_mapping_address_uint256_of_address_800(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:176:241
                let _4 := 3
                /// @src 0:27:1481
                let _5 := 0x20
                mstore(_5, /** @src 0:176:241 */ _4)
                /// @src 0:27:1481
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
			function fun_ENTRY_POINT()
            {
                /// @src 0:27:1481
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
                        /// @src 0:83:147
                        let _19 := 1
                        /// @src 0:27:1481
                        let _20 := sload(/** @src 0:83:147 */ _19)
                        /// @src 0:27:1481
                        let ret_1 := cleanup_from_storage_uint256(_20)
                        let memPos_1 := mload(_1)
                        let _21 := abi_encode_uint256(memPos_1, ret_1)
                        let _22 := sub(_21, memPos_1)
                        return(memPos_1, _22)
                    }
                    case 0x29a8d3bf {
                        let _23 := _4
                        let param_5, param_6 := abi_decode_addresst_uint256(_4)
                        fun_deposit(param_5, param_6)
                        let _24 := _7
                        let _25 := mload(_1)
                        return(_25, _7)
                    }
                    case 0x313ce567 {
                        let _26 := callvalue()
                        if _26
                        {
                            revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                        }
                        let _27 := _4
                        abi_decode(_4)
                        let _28 := _7
                        let _29 := sload(_7)
                        let ret_2 := extract_from_storage_value_dynamict_uint8(_29)
                        let memPos_2 := mload(_1)
                        let _30 := abi_encode_uint8(memPos_2, ret_2)
                        let _31 := sub(_30, memPos_2)
                        return(memPos_2, _31)
                    }
                    case 0x58acc0e6 {
                        let _32 := _4
                        let param_7, param_8, param_9, param_10, param_11 := abi_decode_array_address_dyn_calldatat_array_uint256_dyn_calldatat_uint256(_4)
                        fun_deposit_dynArgs_380(param_7, param_8, param_9, param_10, param_11)
                        let _33 := _7
                        let _34 := mload(_1)
                        return(_34, _7)
                    }
                    case 0x70a08231 {
                        let _35 := callvalue()
                        if _35
                        {
                            revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                        }
                        let _36 := _4
                        let _37 := abi_decode_address(_4)
                        let ret_3 := getter_fun_balanceOf(_37)
                        let memPos_3 := mload(_1)
                        let _38 := abi_encode_uint256(memPos_3, ret_3)
                        let _39 := sub(_38, memPos_3)
                        return(memPos_3, _39)
                    }
                    case 0x90f8fa2d {
                        let _40 := _4
                        let param_12, param_13, param_14, param_15, param_16, param_17, param_18 := abi_decode_addresst_array_address_dyn_calldatat_uint256t_addresst_array_uint256_dyn_calldata(_4)
                        let ret_4 := fun_transferFrom_dynArgs(param_12, param_13, param_14, param_15, param_16, param_17, param_18)
                        let memPos_4 := mload(_1)
                        let _41 := abi_encode_bool(memPos_4, ret_4)
                        let _42 := sub(_41, memPos_4)
                        return(memPos_4, _42)
                    }
                    case 0xdd62ed3e {
                        let _43 := callvalue()
                        if _43
                        {
                            revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
                        }
                        let _44 := _4
                        let param_19, param_20 := abi_decode_addresst_address(_4)
                        /// @src 0:247:312
                        let _45 := mapping_index_access_mapping_address_mapping_address_uint256_of_address_785(/** @src 0:27:1481 */ param_19)
                        /// @src 0:247:312
                        let _46 := mapping_index_access_mapping_address_mapping_address_uint256_of_address(_45, /** @src 0:27:1481 */ param_20)
                        let ret_5 := /** @src 0:247:312 */ read_from_storage_split_dynamic_uint256(_46)
                        /// @src 0:27:1481
                        let memPos_5 := mload(_1)
                        let _47 := abi_encode_uint256(memPos_5, ret_5)
                        let _48 := sub(_47, memPos_5)
                        return(memPos_5, _48)
                    }
                }
                revert_error_15abf5612cd996bc235ba1e55a4a30ac60e6bb601ff7ba4ad3f179b6be8d0490()
            }

        }
        data ".metadata" hex"a2646970667358221220ab792bf022efeef047393943b033d217e0c8e4b438048cc33c0a4b3c671262e864736f6c637827302e382e372d646576656c6f702e323032312e392e31332b636f6d6d69742e65323864303061370058"
    }
}