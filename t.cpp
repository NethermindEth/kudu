ERC20.sol:WARP

Optimized IR:
/*=====================================================*
 *                       WARNING                       *
 *  Solidity to Yul compilation is still EXPERIMENTAL  *
 *       It can result in LOSS OF FUNDS or worse       *
 *                !USE AT YOUR OWN RISK!               *
 *=====================================================*/

/// @use-src 0:"ERC20.sol"
object "WARP_168" {
    code {
        {
            /// @src 0:27:1468  "contract WARP {..."
            let _1 := 128
            let _2 := 64
            mstore(_2, _1)
            let _3 := callvalue()
            if _3
            {
                revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
            }
            constructor_WARP()
            let _4 := datasize("WARP_168_deployed")
            let _5 := dataoffset("WARP_168_deployed")
            let _6 := _1
            codecopy(_1, _5, _4)
            let _7 := _1
            return(_1, _4)
        }
        function revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
        {
            let _1 := 0
            let _2 := _1
            revert(_1, _1)
        }
        function update_byte_slice_shift_120(value) -> result
        {
            /// @src 0:76:78  "18"
            let _1 := 0x12
            /// @src 0:27:1468  "contract WARP {..."
            let _2 := not(255)
            let _3 := and(value, _2)
            result := or(_3, /** @src 0:76:78  "18" */ _1)
        }
        /// @src 0:27:1468  "contract WARP {..."
        function update_storage_value_offsett_rational_by_to_uint8()
        {
            /// @src 0:76:78  "18"
            let _1 := 0x00
            /// @src 0:27:1468  "contract WARP {..."
            let _2 := sload(/** @src 0:76:78  "18" */ _1)
            /// @src 0:27:1468  "contract WARP {..."
            let _3 := update_byte_slice_shift_120(_2)
            /// @src 0:76:78  "18"
            let _4 := _1
            /// @src 0:27:1468  "contract WARP {..."
            sstore(/** @src 0:76:78  "18" */ _1, /** @src 0:27:1468  "contract WARP {..." */ _3)
        }
        function update_byte_slice_shift(value) -> result
        {
            result := /** @src 0:113:149  "100000000000000000000000000000000000" */ 0x13426172c74d822b878fe800000000
        }
        /// @src 0:27:1468  "contract WARP {..."
        function update_storage_value_offsett_rational_by_to_uint256()
        {
            /// @src 0:113:149  "100000000000000000000000000000000000"
            let _1 := 0x01
            /// @src 0:27:1468  "contract WARP {..."
            let _2 := sload(/** @src 0:113:149  "100000000000000000000000000000000000" */ _1)
            /// @src 0:27:1468  "contract WARP {..."
            let _3 := update_byte_slice_shift(_2)
            /// @src 0:113:149  "100000000000000000000000000000000000"
            let _4 := _1
            /// @src 0:27:1468  "contract WARP {..."
            sstore(/** @src 0:113:149  "100000000000000000000000000000000000" */ _1, /** @src 0:27:1468  "contract WARP {..." */ _3)
        }
        function constructor_WARP()
        {
            /// @src 0:76:78  "18"
            update_storage_value_offsett_rational_by_to_uint8()
            /// @src 0:113:149  "100000000000000000000000000000000000"
            update_storage_value_offsett_rational_by_to_uint256()
        }
    }
    /// @use-src 0:"ERC20.sol"
    object "WARP_168_deployed" {
        code {
            {
                /// @src 0:27:1468  "contract WARP {..."
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
                    case 0x0efe6a8b {
                        let _14 := _4
                        let param_2, param_3, param_4 := abi_decode_addresst_uint256t_uint256(_4)
                        let _15 := _7
                        let _16 := mload(_1)
                        return(_16, _7)
                    }
                    case 0x1271f09a {
                        let _17 := _4
                        let param_5, param_6, param_7 := abi_decode_addresst_uint256t_address(_4)
                        let ret := fun_approve(param_5, param_6, param_7)
                        let memPos := mload(_1)
                        let _18 := abi_encode_bool(memPos, ret)
                        let _19 := sub(_18, memPos)
                        return(memPos, _19)
                    }
                    case 0x18160ddd {
                        let _20 := callvalue()
                        if _20
                        {
                            revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                        }
                        let _21 := _4
                        abi_decode(_4)
                        /// @src 0:84:149  "uint256 public totalSupply = 100000000000000000000000000000000000"
                        let _22 := 1
                        /// @src 0:27:1468  "contract WARP {..."
                        let _23 := sload(/** @src 0:84:149  "uint256 public totalSupply = 100000000000000000000000000000000000" */ _22)
                        /// @src 0:27:1468  "contract WARP {..."
                        let ret_1 := cleanup_uint256(_23)
                        let memPos_1 := mload(_1)
                        let _24 := abi_encode_uint256(memPos_1, ret_1)
                        let _25 := sub(_24, memPos_1)
                        return(memPos_1, _25)
                    }
                    case 0x1f324995 {
                        let _26 := _4
                        let param_8, param_9, param_10, param_11, param_12, param_13, param_14 := abi_decode_addresst_array_address_dyn_calldatat_uint256t_addresst_array_uint256_dyn_calldata(_4)
                        let ret_2 := fun_transferFrom(param_8, param_9, param_10, param_11, param_12, param_13, param_14)
                        let memPos_2 := mload(_1)
                        let _27 := abi_encode_bool(memPos_2, ret_2)
                        let _28 := sub(_27, memPos_2)
                        return(memPos_2, _28)
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
                    case 0xdd62ed3e {
                        let _40 := callvalue()
                        if _40
                        {
                            revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                        }
                        let _41 := _4
                        let param_15, param_16 := abi_decode_addresst_address(_4)
                        /// @src 0:249:314  "mapping (address => mapping (address => uint))  public  allowance"
                        let _42 := mapping_index_access_mapping_address_uint256_of_address_785(/** @src 0:27:1468  "contract WARP {..." */ param_15)
                        /// @src 0:249:314  "mapping (address => mapping (address => uint))  public  allowance"
                        let _43 := mapping_index_access_mapping_address_uint256_of_address(_42, /** @src 0:27:1468  "contract WARP {..." */ param_16)
                        let ret_5 := /** @src 0:249:314  "mapping (address => mapping (address => uint))  public  allowance" */ read_from_storage_split_dynamic_uint256(_43)
                        /// @src 0:27:1468  "contract WARP {..."
                        let memPos_5 := mload(_1)
                        let _44 := abi_encode_uint256(memPos_5, ret_5)
                        let _45 := sub(_44, memPos_5)
                        return(memPos_5, _45)
                    }
                    case 0xefc908a1 {
                        let _46 := _4
                        let param_17, param_18, param_19, param_20 := abi_decode_array_address_dyn_calldatat_array_uint256_dyn_calldata(_4)
                        fun_deposit(param_17, param_18, param_19, param_20)
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
            function abi_decode_address_1802() -> value
            {
                let _1 := 36
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1803() -> value
            {
                let _1 := 4
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1805() -> value
            {
                let _1 := 68
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_1809() -> value
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
                value1 := abi_decode_address_1802()
            }
            function abi_decode_addresst_uint256t_uint256(dataEnd) -> value0, value1, value2
            {
                let _1 := 96
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_dbdddcbe895c83990c08b3492a0e83918d802a52331272ac6fdb6a7c4aea3b1b()
                }
                value0 := abi_decode_address_1803()
                let _5 := 36
                value1 := calldataload(_5)
                let _6 := 68
                value2 := calldataload(_6)
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
                value0 := abi_decode_address_1803()
                let _5 := 36
                value1 := calldataload(_5)
                value2 := abi_decode_address_1805()
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
                value0 := abi_decode_address_1803()
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
                value4 := abi_decode_address_1809()
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
                value0 := abi_decode_address_1803()
            }
            function mapping_index_access_mapping_address_uint256_of_address_785(key) -> dataSlot
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
            function mapping_index_access_mapping_address_uint256_of_address_788(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:178:243  "mapping (address => uint)                       public  balanceOf"
                let _4 := 3
                /// @src 0:27:1468  "contract WARP {..."
                let _5 := 0x20
                mstore(_5, /** @src 0:178:243  "mapping (address => uint)                       public  balanceOf" */ _4)
                /// @src 0:27:1468  "contract WARP {..."
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_uint256_of_address_792(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:764:773  "balanceOf"
                let _4 := 0x03
                /// @src 0:27:1468  "contract WARP {..."
                let _5 := 0x20
                mstore(_5, /** @src 0:764:773  "balanceOf" */ _4)
                /// @src 0:27:1468  "contract WARP {..."
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_uint256_of_address_794(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:932:941  "allowance"
                let _4 := 0x04
                /// @src 0:27:1468  "contract WARP {..."
                let _5 := 0x20
                mstore(_5, /** @src 0:932:941  "allowance" */ _4)
                /// @src 0:27:1468  "contract WARP {..."
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
            /// @ast-id 13 @src 0:178:243  "mapping (address => uint)                       public  balanceOf"
            function getter_fun_balanceOf(key) -> ret
            {
                let _1 := mapping_index_access_mapping_address_uint256_of_address_788(key)
                ret := read_from_storage_split_dynamic_uint256(_1)
            }
            /// @src 0:27:1468  "contract WARP {..."
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
                value0 := abi_decode_address_1803()
                value1 := abi_decode_address_1802()
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
            function calldata_array_index_access_address_dyn_calldata(base_ref, length) -> addr
            {
                /// @src 0:432:433  "2"
                let _1 := 0x02
                /// @src 0:27:1468  "contract WARP {..."
                let _2 := lt(/** @src 0:432:433  "2" */ _1, /** @src 0:27:1468  "contract WARP {..." */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 64
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata_791(base_ref, length) -> addr
            {
                /// @src 0:442:443  "4"
                let _1 := 0x04
                /// @src 0:27:1468  "contract WARP {..."
                let _2 := lt(/** @src 0:442:443  "4" */ _1, /** @src 0:27:1468  "contract WARP {..." */ length)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 128
                addr := add(base_ref, _4)
            }
            function calldata_array_index_access_address_dyn_calldata_799(base_ref, length) -> addr
            {
                /// @src 0:1427:1428  "5"
                let _1 := 0x05
                /// @src 0:27:1468  "contract WARP {..."
                let _2 := lt(/** @src 0:1427:1428  "5" */ _1, /** @src 0:27:1468  "contract WARP {..." */ length)
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
            /// @ast-id 39 @src 0:322:457  "function deposit(address[] calldata sender, uint256[] calldata value) public payable {..."
            function fun_deposit(var_sender_offset, var_sender_length, var_value_offset, var_value_25_length)
            {
                /// @src 0:425:434  "sender[2]"
                let _1 := calldata_array_index_access_address_dyn_calldata(var_sender_offset, var_sender_length)
                let _2 := read_from_calldatat_address(_1)
                pop(_2)
                /// @src 0:436:444  "value[4]"
                let _3 := calldata_array_index_access_address_dyn_calldata_791(var_value_offset, var_value_25_length)
                pop(_3)
            }
            /// @src 0:27:1468  "contract WARP {..."
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
            function checked_sub_uint256(x, y) -> diff
            {
                let _1 := lt(x, y)
                if _1 { panic_error_0x11() }
                diff := sub(x, y)
            }
            function update_byte_slice_shift(value, toInsert) -> result
            { result := toInsert }
            function update_storage_value_offsett_uint256_to_uint256(slot, value)
            {
                let _1 := sload(slot)
                let _2 := update_byte_slice_shift(_1, value)
                sstore(slot, _2)
            }
            /// @ast-id 75 @src 0:687:830  "function withdraw(uint wad, address sender) public payable {..."
            function fun_withdraw(var_wad, var_sender)
            {
                /// @src 0:764:781  "balanceOf[sender]"
                let _1 := mapping_index_access_mapping_address_uint256_of_address_792(var_sender)
                let _2 := read_from_storage_split_dynamic_uint256(_1)
                /// @src 0:764:788  "balanceOf[sender] >= wad"
                let _3 := lt(/** @src 0:764:781  "balanceOf[sender]" */ _2, /** @src 0:764:788  "balanceOf[sender] >= wad" */ var_wad)
                let _4 := iszero(_3)
                /// @src 0:756:789  "require(balanceOf[sender] >= wad)"
                require_helper(/** @src 0:764:788  "balanceOf[sender] >= wad" */ _4)
                /// @src 0:799:816  "balanceOf[sender]"
                let _5 := mapping_index_access_mapping_address_uint256_of_address_792(var_sender)
                /// @src 0:27:1468  "contract WARP {..."
                let _6 := sload(/** @src 0:799:823  "balanceOf[sender] -= wad" */ _5)
                /// @src 0:27:1468  "contract WARP {..."
                let _7 := cleanup_uint256(_6)
                /// @src 0:799:823  "balanceOf[sender] -= wad"
                let _8 := checked_sub_uint256(/** @src 0:27:1468  "contract WARP {..." */ _7, /** @src 0:799:823  "balanceOf[sender] -= wad" */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_5, _8)
            }
            /// @ast-id 97 @src 0:836:988  "function approve(address guy, uint wad, address sender) public payable returns (bool) {..."
            function fun_approve(var_guy, var_wad, var_sender) -> var
            {
                /// @src 0:932:949  "allowance[sender]"
                let _1 := mapping_index_access_mapping_address_uint256_of_address_794(var_sender)
                /// @src 0:932:954  "allowance[sender][guy]"
                let _2 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:932:949  "allowance[sender]" */ _1, /** @src 0:932:954  "allowance[sender][guy]" */ var_guy)
                /// @src 0:932:960  "allowance[sender][guy] = wad"
                update_storage_value_offsett_uint256_to_uint256(/** @src 0:932:954  "allowance[sender][guy]" */ _2, /** @src 0:932:960  "allowance[sender][guy] = wad" */ var_wad)
                /// @src 0:970:981  "return true"
                var := /** @src 0:977:981  "true" */ 0x01
            }
            /// @src 0:27:1468  "contract WARP {..."
            function checked_add_uint256(x, y) -> sum
            {
                let _1 := not(y)
                let _2 := gt(x, _1)
                if _2 { panic_error_0x11() }
                sum := add(x, y)
            }
            /// @ast-id 167 @src 0:994:1466  "function transferFrom(address src, ..."
            function fun_transferFrom(var_src, var_dst_offset, var_dst_length, var_wad, var_sender, var_value_109_offset, var_value_length) -> var_
            {
                /// @src 0:1187:1192  "value"
                fun_deposit(var_dst_offset, var_dst_length, var_value_109_offset, var_value_length)
                /// @src 0:27:1468  "contract WARP {..."
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:1207:1220  "src != sender" */ var_sender, /** @src 0:27:1468  "contract WARP {..." */ _1)
                let _3 := and(/** @src 0:1207:1220  "src != sender" */ var_src, /** @src 0:27:1468  "contract WARP {..." */ _1)
                /// @src 0:1207:1220  "src != sender"
                let _4 := eq(/** @src 0:27:1468  "contract WARP {..." */ _3, _2)
                /// @src 0:1207:1220  "src != sender"
                let _5 := iszero(_4)
                /// @src 0:1203:1372  "if (src != sender) {..."
                if /** @src 0:1207:1220  "src != sender" */ _5
                /// @src 0:1203:1372  "if (src != sender) {..."
                {
                    /// @src 0:1244:1258  "allowance[src]"
                    let _6 := mapping_index_access_mapping_address_uint256_of_address_794(var_src)
                    /// @src 0:1244:1266  "allowance[src][sender]"
                    let _7 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:1244:1258  "allowance[src]" */ _6, /** @src 0:1244:1266  "allowance[src][sender]" */ var_sender)
                    let _8 := read_from_storage_split_dynamic_uint256(_7)
                    /// @src 0:1244:1273  "allowance[src][sender] >= wad"
                    let _9 := lt(/** @src 0:1244:1266  "allowance[src][sender]" */ _8, /** @src 0:1244:1273  "allowance[src][sender] >= wad" */ var_wad)
                    let _10 := iszero(_9)
                    /// @src 0:1236:1274  "require(allowance[src][sender] >= wad)"
                    require_helper(/** @src 0:1244:1273  "allowance[src][sender] >= wad" */ _10)
                    /// @src 0:1296:1310  "balanceOf[src]"
                    let _11 := mapping_index_access_mapping_address_uint256_of_address_792(var_src)
                    let _12 := read_from_storage_split_dynamic_uint256(_11)
                    /// @src 0:1296:1317  "balanceOf[src] >= wad"
                    let _13 := cleanup_uint256(/** @src 0:1296:1310  "balanceOf[src]" */ _12)
                    /// @src 0:1296:1317  "balanceOf[src] >= wad"
                    let _14 := lt(_13, var_wad)
                    let _15 := iszero(_14)
                    /// @src 0:1288:1318  "require(balanceOf[src] >= wad)"
                    require_helper(/** @src 0:1296:1317  "balanceOf[src] >= wad" */ _15)
                    /// @src 0:1332:1346  "allowance[src]"
                    let _16 := mapping_index_access_mapping_address_uint256_of_address_794(var_src)
                    /// @src 0:1332:1354  "allowance[src][sender]"
                    let _17 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:1332:1346  "allowance[src]" */ _16, /** @src 0:1332:1354  "allowance[src][sender]" */ var_sender)
                    /// @src 0:27:1468  "contract WARP {..."
                    let _18 := sload(/** @src 0:1332:1361  "allowance[src][sender] -= wad" */ _17)
                    /// @src 0:27:1468  "contract WARP {..."
                    let _19 := cleanup_uint256(_18)
                    /// @src 0:1332:1361  "allowance[src][sender] -= wad"
                    let _20 := checked_sub_uint256(/** @src 0:27:1468  "contract WARP {..." */ _19, /** @src 0:1332:1361  "allowance[src][sender] -= wad" */ var_wad)
                    update_storage_value_offsett_uint256_to_uint256(_17, _20)
                }
                /// @src 0:1382:1396  "balanceOf[src]"
                let _21 := mapping_index_access_mapping_address_uint256_of_address_792(var_src)
                /// @src 0:27:1468  "contract WARP {..."
                let _22 := sload(/** @src 0:1382:1403  "balanceOf[src] -= wad" */ _21)
                /// @src 0:27:1468  "contract WARP {..."
                let _23 := cleanup_uint256(_22)
                /// @src 0:1382:1403  "balanceOf[src] -= wad"
                let _24 := checked_sub_uint256(/** @src 0:27:1468  "contract WARP {..." */ _23, /** @src 0:1382:1403  "balanceOf[src] -= wad" */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_21, _24)
                /// @src 0:1423:1429  "dst[5]"
                let _25 := calldata_array_index_access_address_dyn_calldata_799(var_dst_offset, var_dst_length)
                let _26 := read_from_calldatat_address(_25)
                /// @src 0:1413:1430  "balanceOf[dst[5]]"
                let _27 := mapping_index_access_mapping_address_uint256_of_address_792(/** @src 0:1423:1429  "dst[5]" */ _26)
                /// @src 0:27:1468  "contract WARP {..."
                let _28 := sload(/** @src 0:1413:1437  "balanceOf[dst[5]] += wad" */ _27)
                /// @src 0:27:1468  "contract WARP {..."
                let _29 := cleanup_uint256(_28)
                /// @src 0:1413:1437  "balanceOf[dst[5]] += wad"
                let _30 := checked_add_uint256(/** @src 0:27:1468  "contract WARP {..." */ _29, /** @src 0:1413:1437  "balanceOf[dst[5]] += wad" */ var_wad)
                update_storage_value_offsett_uint256_to_uint256(_27, _30)
                /// @src 0:1448:1459  "return true"
                var_ := /** @src 0:1455:1459  "true" */ 0x01
            }
        }
        data ".metadata" hex"a3646970667358221220dad7e9d957b4c988398cee48d7423c66d12a2c40255e22c506979e9faf02bcc06c6578706572696d656e74616cf564736f6c63430008080041"
    }
}

