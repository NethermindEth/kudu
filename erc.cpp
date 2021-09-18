object "KongsNFT_2450" {
    object "KongsNFT_2450_deployed" {
        code {
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
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
                    case 0x01ffc9a7 {
                        let _11 := callvalue()
                        if _11
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _12 := not(127)
                        let _13 := _4
                        let _14 := abi_decode_bytes4(_4)
                        let _15 := fun_supportsInterface_2277(_14)
                        let _16 := abi_encode_bool_4289(_15)
                        let _17 := add(_16, _12)
                        let _18 := _2
                        return(_2, _17)
                    }
                    case 0x06fdde03 {
                        let _19 := callvalue()
                        if _19
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _20 := _4
                        abi_decode(_4)
                        let ret := copy_array_from_storage_to_memory_string_8788()
                        let memPos := mload(_1)
                        let _21 := abi_encode_string(memPos, ret)
                        let _22 := sub(_21, memPos)
                        return(memPos, _22)
                    }
                    case 0x081812fc {
                        let _23 := callvalue()
                        if _23
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _24 := _4
                        let _25 := abi_decode_uint256(_4)
                        let ret_1 := fun_getApproved(_25)
                        let memPos_1 := mload(_1)
                        let _26 := abi_encode_tuple_address(memPos_1, ret_1)
                        let _27 := sub(_26, memPos_1)
                        return(memPos_1, _27)
                    }
                    case 0x095ea7b3 {
                        let _28 := callvalue()
                        if _28
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _29 := _4
                        let param, param_1 := abi_decode_addresst_uint256(_4)
                        fun_approve(param, param_1)
                        let _30 := mload(_1)
                        return(_30, _7)
                    }
                    case 0x18160ddd {
                        let _31 := callvalue()
                        if _31
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _32 := _4
                        abi_decode(_4)
                        /// @src 0:37867:37877  "_allTokens"
                        let _33 := 0x08
                        /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                        let ret_2 := sload(/** @src 0:37867:37877  "_allTokens" */ _33)
                        /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                        let memPos_2 := mload(_1)
                        let _34 := abi_encode_uint256(memPos_2, ret_2)
                        let _35 := sub(_34, memPos_2)
                        return(memPos_2, _35)
                    }
                    case 0x23b872dd {
                        let _36 := callvalue()
                        if _36
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _37 := _4
                        let param_2, param_3, param_4 := abi_decode_addresst_addresst_uint256(_4)
                        fun_transferFrom(param_2, param_3, param_4)
                        let _38 := mload(_1)
                        return(_38, _7)
                    }
                    case 0x2f745c59 {
                        let _39 := callvalue()
                        if _39
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _40 := _4
                        let param_5, param_6 := abi_decode_addresst_uint256(_4)
                        let ret_3 := fun_tokenOfOwnerByIndex(param_5, param_6)
                        let memPos_3 := mload(_1)
                        let _41 := abi_encode_uint256(memPos_3, ret_3)
                        let _42 := sub(_41, memPos_3)
                        return(memPos_3, _42)
                    }
                    case 0x339181d9 {
                        let _43 := callvalue()
                        if _43
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _44 := _4
                        abi_decode(_4)
                        let memPos_4 := mload(_1)
                        let _45 := abi_encode_uint8(memPos_4)
                        let _46 := sub(_45, memPos_4)
                        return(memPos_4, _46)
                    }
                    case 0x3ccfd60b {
                        let _47 := callvalue()
                        if _47
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _48 := _4
                        abi_decode(_4)
                        fun_withdraw()
                        let _49 := mload(_1)
                        return(_49, _7)
                    }
                    case 0x42842e0e {
                        let _50 := callvalue()
                        if _50
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _51 := _4
                        let param_7, param_8, param_9 := abi_decode_addresst_addresst_uint256(_4)
                        fun_safeTransferFrom_1282(param_7, param_8, param_9)
                        let _52 := mload(_1)
                        return(_52, _7)
                    }
                    case 0x4f6ccce7 {
                        let _53 := callvalue()
                        if _53
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _54 := _4
                        let _55 := abi_decode_uint256(_4)
                        let ret_4 := fun_tokenByIndex(_55)
                        let memPos_5 := mload(_1)
                        let _56 := abi_encode_uint256(memPos_5, ret_4)
                        let _57 := sub(_56, memPos_5)
                        return(memPos_5, _57)
                    }
                    case 0x55f804b3 {
                        let _58 := callvalue()
                        if _58
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _59 := _4
                        let _60 := abi_decode_string_4303(_4)
                        fun_setBaseURI(_60)
                        let _61 := mload(_1)
                        return(_61, _7)
                    }
                    case 0x6352211e {
                        let _62 := callvalue()
                        if _62
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _63 := _4
                        let _64 := abi_decode_uint256(_4)
                        let ret_5 := fun_ownerOf(_64)
                        let memPos_6 := mload(_1)
                        let _65 := abi_encode_tuple_address(memPos_6, ret_5)
                        let _66 := sub(_65, memPos_6)
                        return(memPos_6, _66)
                    }
                    case 0x6ecd2306 {
                        let _67 := _4
                        let _68 := abi_decode_uint8(_4)
                        fun_mint(_68)
                        let _69 := mload(_1)
                        return(_69, _7)
                    }
                    case 0x70a08231 {
                        let _70 := callvalue()
                        if _70
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _71 := _4
                        let _72 := abi_decode_address(_4)
                        let ret_6 := fun_balanceOf(_72)
                        let memPos_7 := mload(_1)
                        let _73 := abi_encode_uint256(memPos_7, ret_6)
                        let _74 := sub(_73, memPos_7)
                        return(memPos_7, _74)
                    }
                    case 0x715018a6 {
                        let _75 := callvalue()
                        if _75
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _76 := _4
                        abi_decode(_4)
                        fun_renounceOwnership()
                        let _77 := mload(_1)
                        return(_77, _7)
                    }
                    case 0x82d95df5 {
                        let _78 := callvalue()
                        if _78
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _79 := _4
                        let _80 := abi_decode_uint256(_4)
                        fun_setStartDate(_80)
                        let _81 := mload(_1)
                        return(_81, _7)
                    }
                    case 0x8da5cb5b {
                        let _82 := callvalue()
                        if _82
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _83 := _4
                        abi_decode(_4)
                        /// @src 0:3256:3262  "_owner"
                        let _84 := 0x0b
                        /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                        let _85 := sload(/** @src 0:3256:3262  "_owner" */ _84)
                        /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                        let ret_7 := cleanup_address(_85)
                        let memPos_8 := mload(_1)
                        let _86 := abi_encode_tuple_address(memPos_8, ret_7)
                        let _87 := sub(_86, memPos_8)
                        return(memPos_8, _87)
                    }
                    case 0x95d89b41 {
                        let _88 := callvalue()
                        if _88
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _89 := _4
                        abi_decode(_4)
                        let ret_8 := copy_array_from_storage_to_memory_string_8790()
                        let memPos_9 := mload(_1)
                        let _90 := abi_encode_string(memPos_9, ret_8)
                        let _91 := sub(_90, memPos_9)
                        return(memPos_9, _91)
                    }
                    case 0xa22cb465 {
                        let _92 := callvalue()
                        if _92
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _93 := _4
                        let param_10, param_11 := abi_decode_addresst_bool(_4)
                        fun_setApprovalForAll(param_10, param_11)
                        let _94 := mload(_1)
                        return(_94, _7)
                    }
                    case 0xac8daba0 {
                        let _95 := callvalue()
                        if _95
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _96 := _4
                        abi_decode(_4)
                        /// @src 0:45216:45254  "uint256 public _startDate = 1630936800"
                        let _97 := 14
                        /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                        let _98 := sload(/** @src 0:45216:45254  "uint256 public _startDate = 1630936800" */ _97)
                        /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                        let ret_9 := cleanup_uint256(_98)
                        let memPos_10 := mload(_1)
                        let _99 := abi_encode_uint256(memPos_10, ret_9)
                        let _100 := sub(_99, memPos_10)
                        return(memPos_10, _100)
                    }
                    case 0xb88d4fde {
                        let _101 := callvalue()
                        if _101
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _102 := _4
                        let param_12, param_13, param_14, param_15 := abi_decode_addresst_addresst_uint256t_bytes(_4)
                        fun_safeTransferFrom(param_12, param_13, param_14, param_15)
                        let _103 := mload(_1)
                        return(_103, _7)
                    }
                    case 0xc87b56dd {
                        let _104 := callvalue()
                        if _104
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _105 := _4
                        let _106 := abi_decode_uint256(_4)
                        let ret_10 := fun_tokenURI_2411(_106)
                        let memPos_11 := mload(_1)
                        let _107 := abi_encode_string(memPos_11, ret_10)
                        let _108 := sub(_107, memPos_11)
                        return(memPos_11, _108)
                    }
                    case 0xd5abeb01 {
                        let _109 := callvalue()
                        if _109
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _110 := _4
                        abi_decode(_4)
                        let memPos_12 := mload(_1)
                        let _111 := abi_encode_uint16(memPos_12)
                        let _112 := sub(_111, memPos_12)
                        return(memPos_12, _112)
                    }
                    case 0xe985e9c5 {
                        let _113 := callvalue()
                        if _113
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _114 := _4
                        let param_16, param_17 := abi_decode_addresst_address(_4)
                        /// @src 0:27793:27818  "_operatorApprovals[owner]"
                        let _115 := mapping_index_access_mapping_address_uint256_of_address_4320(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ param_16)
                        /// @src 0:27793:27828  "_operatorApprovals[owner][operator]"
                        let _116 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:27793:27818  "_operatorApprovals[owner]" */ _115, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ param_17)
                        let ret_11 := /** @src 0:27793:27828  "_operatorApprovals[owner][operator]" */ read_from_storage_split_offset_bool(_116)
                        /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                        let memPos_13 := mload(_1)
                        let _117 := abi_encode_bool(memPos_13, ret_11)
                        let _118 := sub(_117, memPos_13)
                        return(memPos_13, _118)
                    }
                    case 0xeb91d37e {
                        let _119 := callvalue()
                        if _119
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _120 := _4
                        abi_decode(_4)
                        let memPos_14 := mload(_1)
                        let _121 := abi_encode_tuple_uint64(memPos_14)
                        let _122 := sub(_121, memPos_14)
                        return(memPos_14, _122)
                    }
                    case 0xf2fde38b {
                        let _123 := callvalue()
                        if _123
                        {
                            revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                        }
                        let _124 := _4
                        let _125 := abi_decode_address(_4)
                        fun_transferOwnership(_125)
                        let _126 := mload(_1)
                        return(_126, _7)
                    }
                }
                revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
            }
            function revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
            {
                let _1 := 0
                let _2 := _1
                revert(_1, _1)
            }
            function validator_revert_bytes4(value)
            {
                let _1 := shl(224, 0xffffffff)
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
            function abi_decode_t_bytes4() -> value
            {
                let _1 := 4
                value := calldataload(_1)
                validator_revert_bytes4(value)
            }
            function abi_decode_bytes4(dataEnd) -> value0
            {
                let _1 := 32
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                value0 := abi_decode_t_bytes4()
            }
            function cleanup_bool(value) -> cleaned
            {
                let _1 := iszero(value)
                cleaned := iszero(_1)
            }
            function abi_encode_bool_to_bool_8795(value)
            {
                let _1 := iszero(value)
                let _2 := iszero(_1)
                let _3 := 128
                mstore(_3, _2)
            }
            function abi_encode_bool_to_bool(value, pos)
            {
                let _1 := iszero(value)
                let _2 := iszero(_1)
                mstore(pos, _2)
            }
            function abi_encode_bool_4289(value0) -> tail
            {
                tail := 160
                abi_encode_bool_to_bool_8795(value0)
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
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
            }
            function array_storeLengthForEncoding_string_4324(pos) -> updated_pos
            {
                let _1 := 32
                mstore(pos, _1)
                let _2 := _1
                updated_pos := add(pos, _1)
            }
            function array_storeLengthForEncoding_string_4326(pos) -> updated_pos
            {
                let _1 := 38
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4328(pos) -> updated_pos
            {
                let _1 := 42
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4330(pos) -> updated_pos
            {
                let _1 := 41
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4332(pos) -> updated_pos
            {
                let _1 := 33
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4333(pos) -> updated_pos
            {
                let _1 := 56
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4335(pos) -> updated_pos
            {
                let _1 := 44
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4337(pos) -> updated_pos
            {
                let _1 := 25
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4339(pos) -> updated_pos
            {
                let _1 := 49
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4341(pos) -> updated_pos
            {
                let _1 := 50
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4346(pos) -> updated_pos
            {
                let _1 := 36
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4354(pos) -> updated_pos
            {
                let _1 := 43
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4384(pos) -> updated_pos
            {
                let _1 := 16
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4385(pos) -> updated_pos
            {
                let _1 := 20
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4386(pos) -> updated_pos
            {
                let _1 := 61
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4387(pos) -> updated_pos
            {
                let _1 := 22
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4394(pos) -> updated_pos
            {
                let _1 := 28
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4402(pos) -> updated_pos
            {
                let _1 := 47
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string_4411(pos) -> updated_pos
            {
                let _1 := 24
                mstore(pos, _1)
                let _2 := 0x20
                updated_pos := add(pos, _2)
            }
            function array_storeLengthForEncoding_string(pos, length) -> updated_pos
            {
                mstore(pos, length)
                let _1 := 0x20
                updated_pos := add(pos, _1)
            }
            function copy_memory_to_memory(src, dst, length)
            {
                let i := 0
                for { }
                lt(i, length)
                {
                    let _1 := 32
                    i := add(i, _1)
                }
                {
                    let _2 := add(src, i)
                    let _3 := mload(_2)
                    let _4 := add(dst, i)
                    mstore(_4, _3)
                }
                let _5 := gt(i, length)
                if _5
                {
                    let _6 := 0
                    let _7 := add(dst, length)
                    mstore(_7, _6)
                }
            }
            function abi_encode_string_to_string(value, pos) -> end
            {
                let length := mload(value)
                let pos_1 := array_storeLengthForEncoding_string(pos, length)
                let _1 := 0x20
                let _2 := add(value, _1)
                copy_memory_to_memory(_2, pos_1, length)
                let _3 := not(31)
                let _4 := 31
                let _5 := add(length, _4)
                let _6 := and(_5, _3)
                end := add(pos_1, _6)
            }
            function abi_encode_string(headStart, value0) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_string_to_string(value0, _3)
            }
            function cleanup_uint256(value) -> cleaned
            { cleaned := value }
            function abi_decode_uint256(dataEnd) -> value0
            {
                let _1 := 32
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                let _5 := 4
                value0 := calldataload(_5)
            }
            function cleanup_address(value) -> cleaned
            {
                let _1 := sub(shl(160, 1), 1)
                cleaned := and(value, _1)
            }
            function abi_encode_address(value, pos)
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(value, _1)
                mstore(pos, _2)
            }
            function abi_encode_tuple_address(headStart, value0) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_address(value0, headStart)
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
            function abi_decode_address_8796() -> value
            {
                let _1 := 4
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_address_8799() -> value
            {
                let _1 := 36
                value := calldataload(_1)
                validator_revert_address(value)
            }
            function abi_decode_addresst_uint256(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                value0 := abi_decode_address_8796()
                let _5 := 36
                value1 := calldataload(_5)
            }
            function abi_encode_uint256_to_uint256(value, pos)
            { mstore(pos, value) }
            function abi_encode_uint256(headStart, value0) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_uint256_to_uint256(value0, headStart)
            }
            function abi_decode_addresst_addresst_uint256(dataEnd) -> value0, value1, value2
            {
                let _1 := 96
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                value0 := abi_decode_address_8796()
                value1 := abi_decode_address_8799()
                let _5 := 68
                value2 := calldataload(_5)
            }
            function abi_encode_uint8_to_uint8(pos)
            {
                /// @src 0:46377:46379  "30"
                let _1 := 0x1e
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                mstore(pos, /** @src 0:46377:46379  "30" */ _1)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function abi_encode_uint8(headStart) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_uint8_to_uint8(headStart)
            }
            function panic_error_0x41()
            {
                let _1 := shl(224, 0x4e487b71)
                let _2 := 0
                mstore(_2, _1)
                let _3 := 0x41
                let _4 := 4
                mstore(_4, _3)
                let _5 := 0x24
                let _6 := _2
                revert(_2, _5)
            }
            function finalize_allocation_15556(memPtr)
            {
                let _1 := 0x20
                let newFreePtr := add(memPtr, _1)
                let _2 := lt(newFreePtr, memPtr)
                let _3 := 0xffffffffffffffff
                let _4 := gt(newFreePtr, _3)
                let _5 := or(_4, _2)
                if _5 { panic_error_0x41() }
                let _6 := 64
                mstore(_6, newFreePtr)
            }
            function finalize_allocation_15558(memPtr)
            {
                let _1 := 64
                let newFreePtr := add(memPtr, _1)
                let _2 := lt(newFreePtr, memPtr)
                let _3 := 0xffffffffffffffff
                let _4 := gt(newFreePtr, _3)
                let _5 := or(_4, _2)
                if _5 { panic_error_0x41() }
                let _6 := _1
                mstore(_1, newFreePtr)
            }
            function finalize_allocation(memPtr, size)
            {
                let _1 := not(31)
                let _2 := 31
                let _3 := add(size, _2)
                let _4 := and(_3, _1)
                let newFreePtr := add(memPtr, _4)
                let _5 := lt(newFreePtr, memPtr)
                let _6 := 0xffffffffffffffff
                let _7 := gt(newFreePtr, _6)
                let _8 := or(_7, _5)
                if _8 { panic_error_0x41() }
                let _9 := 64
                mstore(_9, newFreePtr)
            }
            function allocate_memory_12158() -> memPtr
            {
                let _1 := 64
                memPtr := mload(_1)
                finalize_allocation_15556(memPtr)
            }
            function allocate_memory_12160() -> memPtr
            {
                let _1 := 64
                memPtr := mload(_1)
                finalize_allocation_15558(memPtr)
            }
            function allocate_memory(size) -> memPtr
            {
                let _1 := 64
                memPtr := mload(_1)
                finalize_allocation(memPtr, size)
            }
            function array_allocation_size_string(length) -> size
            {
                let _1 := 0xffffffffffffffff
                let _2 := gt(length, _1)
                if _2 { panic_error_0x41() }
                let _3 := 0x20
                let _4 := not(31)
                let _5 := 31
                let _6 := add(length, _5)
                let _7 := and(_6, _4)
                size := add(_7, _3)
            }
            function copy_calldata_to_memory(src, dst, length)
            {
                calldatacopy(dst, src, length)
                let _1 := 0
                let _2 := add(dst, length)
                mstore(_2, _1)
            }
            function abi_decode_available_length_string(src, length, end) -> array
            {
                let _1 := array_allocation_size_string(length)
                array := allocate_memory(_1)
                mstore(array, length)
                let _2 := add(src, length)
                let _3 := gt(_2, end)
                if _3
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                let _4 := 0x20
                let _5 := add(array, _4)
                copy_calldata_to_memory(src, _5, length)
            }
            function abi_decode_string(offset, end) -> array
            {
                let _1 := 0x1f
                let _2 := add(offset, _1)
                let _3 := slt(_2, end)
                let _4 := iszero(_3)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                let _5 := calldataload(offset)
                let _6 := 0x20
                let _7 := add(offset, _6)
                array := abi_decode_available_length_string(_7, _5, end)
            }
            function abi_decode_string_4303(dataEnd) -> value0
            {
                let _1 := 32
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                let _5 := 4
                let offset := calldataload(_5)
                let _6 := 0xffffffffffffffff
                let _7 := gt(offset, _6)
                if _7
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                let _8 := _5
                let _9 := add(_5, offset)
                value0 := abi_decode_string(_9, dataEnd)
            }
            function validator_revert_uint8(value)
            {
                let _1 := 0xff
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
            function abi_decode_uint8_8802() -> value
            {
                let _1 := 4
                value := calldataload(_1)
                validator_revert_uint8(value)
            }
            function abi_decode_uint8(dataEnd) -> value0
            {
                let _1 := 32
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                value0 := abi_decode_uint8_8802()
            }
            function abi_decode_address(dataEnd) -> value0
            {
                let _1 := 32
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                value0 := abi_decode_address_8796()
            }
            function validator_revert_bool(value)
            {
                let _1 := iszero(value)
                let _2 := iszero(_1)
                let _3 := eq(value, _2)
                let _4 := iszero(_3)
                if _4
                {
                    let _5 := 0
                    let _6 := _5
                    revert(_5, _5)
                }
            }
            function abi_decode_bool() -> value
            {
                let _1 := 36
                value := calldataload(_1)
                validator_revert_bool(value)
            }
            function abi_decode_addresst_bool(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                value0 := abi_decode_address_8796()
                value1 := abi_decode_bool()
            }
            function extract_from_storage_value_dynamict_uint256(slot_value, offset) -> value
            {
                let _1 := 3
                let _2 := shl(_1, offset)
                value := shr(_2, slot_value)
            }
            function abi_decode_addresst_addresst_uint256t_bytes(dataEnd) -> value0, value1, value2, value3
            {
                let _1 := 128
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                value0 := abi_decode_address_8796()
                value1 := abi_decode_address_8799()
                let _5 := 68
                value2 := calldataload(_5)
                let _6 := 100
                let offset := calldataload(_6)
                let _7 := 0xffffffffffffffff
                let _8 := gt(offset, _7)
                if _8
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                let _9 := 4
                let _10 := add(_9, offset)
                value3 := abi_decode_string(_10, dataEnd)
            }
            function abi_encode_uint16_12150(pos)
            {
                /// @src 0:45167:45171  "5000"
                let _1 := 0x1388
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                mstore(pos, /** @src 0:45167:45171  "5000" */ _1)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function abi_encode_uint16(headStart) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_uint16_12150(headStart)
            }
            function abi_decode_addresst_address(dataEnd) -> value0, value1
            {
                let _1 := 64
                let _2 := not(3)
                let _3 := add(dataEnd, _2)
                let _4 := slt(_3, _1)
                if _4
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                value0 := abi_decode_address_8796()
                value1 := abi_decode_address_8799()
            }
            function abi_encode_uint64(pos)
            {
                /// @src 0:46518:46540  "50_000_000_000_000_000"
                let _1 := 0xb1a2bc2ec50000
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                mstore(pos, /** @src 0:46518:46540  "50_000_000_000_000_000" */ _1)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function abi_encode_tuple_uint64(headStart) -> tail
            {
                let _1 := 32
                tail := add(headStart, _1)
                abi_encode_uint64(headStart)
            }
            function read_from_storage_split_offset_address(slot) -> value
            {
                let _1 := sload(slot)
                value := cleanup_address(_1)
            }
            function store_literal_in_memory_9924ebdf1add33d25d4ef888e16131f0a5687b0580a36c21b5c301a6c462effe(memPtr)
            {
                let _1 := "Ownable: caller is not the owner"
                mstore(memPtr, _1)
            }
            function abi_encode_stringliteral_9924(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4324(pos)
                store_literal_in_memory_9924ebdf1add33d25d4ef888e16131f0a5687b0580a36c21b5c301a6c462effe(pos_1)
                let _1 := 32
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_9924(_3)
            }
            function require_helper_stringliteral_9924(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 138 @src 0:3357:3474  "modifier onlyOwner() {..."
            function modifier_onlyOwner_142()
            {
                /// @src 0:3256:3262  "_owner"
                let _1 := 0x0b
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:3256:3262  "_owner" */ _1)
                /// @src 0:3396:3403  "owner()"
                let expr := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ cleanup_address(_2)
                /// @src 0:2148:2158  "msg.sender"
                let _3 := caller()
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := sub(shl(160, 1), 1)
                let _5 := and(/** @src 0:3396:3419  "owner() == _msgSender()" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:3396:3419  "owner() == _msgSender()"
                let _6 := eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _5, /** @src 0:2148:2158  "msg.sender" */ _3)
                /// @src 0:3388:3456  "require(owner() == _msgSender(), \"Ownable: caller is not the owner\")"
                require_helper_stringliteral_9924(/** @src 0:3396:3419  "owner() == _msgSender()" */ _6)
                /// @src 0:3466:3467  "_"
                fun_renounceOwnership_inner()
            }
            /// @src 0:3816:3908  "function renounceOwnership() public virtual onlyOwner {..."
            function fun_renounceOwnership_inner()
            {
                /// @src 0:3890:3900  "address(0)"
                fun_setOwner_4325()
            }
            /// @ast-id 152 @src 0:3816:3908  "function renounceOwnership() public virtual onlyOwner {..."
            function fun_renounceOwnership()
            { modifier_onlyOwner_142() }
            /// @ast-id 138 @src 0:3357:3474  "modifier onlyOwner() {..."
            function modifier_onlyOwner_158(var_newOwner)
            {
                /// @src 0:3256:3262  "_owner"
                let _1 := 0x0b
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:3256:3262  "_owner" */ _1)
                /// @src 0:3396:3403  "owner()"
                let expr := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ cleanup_address(_2)
                /// @src 0:2148:2158  "msg.sender"
                let _3 := caller()
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := sub(shl(160, 1), 1)
                let _5 := and(/** @src 0:3396:3419  "owner() == _msgSender()" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:3396:3419  "owner() == _msgSender()"
                let _6 := eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _5, /** @src 0:2148:2158  "msg.sender" */ _3)
                /// @src 0:3388:3456  "require(owner() == _msgSender(), \"Ownable: caller is not the owner\")"
                require_helper_stringliteral_9924(/** @src 0:3396:3419  "owner() == _msgSender()" */ _6)
                /// @src 0:3466:3467  "_"
                fun_transferOwnership_inner(var_newOwner)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_245f15ff17f551913a7a18385165551503906a406f905ac1c2437281a7cd0cfe(memPtr)
            {
                let _1 := "Ownable: new owner is the zero a"
                mstore(memPtr, _1)
                let _2 := "ddress"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_245f(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4326(pos)
                store_literal_in_memory_245f15ff17f551913a7a18385165551503906a406f905ac1c2437281a7cd0cfe(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_245f(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_245f(_3)
            }
            function require_helper_stringliteral_245f(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_245f(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @src 0:4057:4246  "function transferOwnership(address newOwner) public virtual onlyOwner {..."
            function fun_transferOwnership_inner(var_newOwner)
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:4145:4167  "newOwner != address(0)" */ var_newOwner, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:4145:4167  "newOwner != address(0)"
                let _3 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2)
                /// @src 0:4145:4167  "newOwner != address(0)"
                let _4 := iszero(_3)
                /// @src 0:4137:4210  "require(newOwner != address(0), \"Ownable: new owner is the zero address\")"
                require_helper_stringliteral_245f(/** @src 0:4145:4167  "newOwner != address(0)" */ _4)
                /// @src 0:4230:4238  "newOwner"
                fun_setOwner(var_newOwner)
            }
            /// @ast-id 175 @src 0:4057:4246  "function transferOwnership(address newOwner) public virtual onlyOwner {..."
            function fun_transferOwnership(var_newOwner)
            {
                modifier_onlyOwner_158(var_newOwner)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function update_byte_slice_shift_12152(value) -> result
            {
                let _1 := shl(160, 0xffffffffffffffffffffffff)
                result := and(value, _1)
            }
            function update_byte_slice_20_shift(value, toInsert) -> result
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(toInsert, _1)
                let _3 := shl(160, 0xffffffffffffffffffffffff)
                let _4 := and(value, _3)
                result := or(_4, _2)
            }
            function update_storage_value_offsett_address_to_address_8811()
            {
                /// @src 0:4326:4332  "_owner"
                let _1 := 0x0b
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:4326:4332  "_owner" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := update_byte_slice_shift_12152(_2)
                /// @src 0:4326:4332  "_owner"
                let _4 := _1
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                sstore(/** @src 0:4326:4332  "_owner" */ _1, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _3)
            }
            function update_storage_value_offsett_address_to_address_4327(value)
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(value, _1)
                /// @src 0:4326:4332  "_owner"
                let _3 := 0x0b
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := sload(/** @src 0:4326:4332  "_owner" */ _3)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _5 := update_byte_slice_20_shift(_4, _2)
                /// @src 0:4326:4332  "_owner"
                let _6 := _3
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                sstore(/** @src 0:4326:4332  "_owner" */ _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _5)
            }
            function update_storage_value_offsett_address_to_address_8815(slot)
            {
                let _1 := sload(slot)
                let _2 := update_byte_slice_shift_12152(_1)
                sstore(slot, _2)
            }
            function update_storage_value_offsett_address_to_address(slot, value)
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(value, _1)
                let _3 := sload(slot)
                let _4 := update_byte_slice_20_shift(_3, _2)
                sstore(slot, _4)
            }
            /// @ast-id 194 @src 0:4252:4421  "function _setOwner(address newOwner) private {..."
            function fun_setOwner_4325()
            {
                /// @src 0:4326:4332  "_owner"
                let _1 := 0x0b
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:4326:4332  "_owner" */ _1)
                let _3 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ cleanup_address(_2)
                /// @src 0:4342:4359  "_owner = newOwner"
                update_storage_value_offsett_address_to_address_8811()
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := 0
                /// @src 0:4374:4414  "OwnershipTransferred(oldOwner, newOwner)"
                let _5 := 0x8be0079c531659141344cd1fd0a4f28419497f9722a3daafe3b4186f6b6457e0
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _6 := _4
                let _7 := 64
                let _8 := mload(_7)
                /// @src 0:4374:4414  "OwnershipTransferred(oldOwner, newOwner)"
                log3(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _8, _4, /** @src 0:4374:4414  "OwnershipTransferred(oldOwner, newOwner)" */ _5, _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
            }
            /// @ast-id 194 @src 0:4252:4421  "function _setOwner(address newOwner) private {..."
            function fun_setOwner(var_newOwner)
            {
                /// @src 0:4326:4332  "_owner"
                let _1 := 0x0b
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:4326:4332  "_owner" */ _1)
                let _3 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ cleanup_address(_2)
                /// @src 0:4342:4359  "_owner = newOwner"
                update_storage_value_offsett_address_to_address_4327(var_newOwner)
                /// @src 0:4374:4414  "OwnershipTransferred(oldOwner, newOwner)"
                let _4 := 0x8be0079c531659141344cd1fd0a4f28419497f9722a3daafe3b4186f6b6457e0
                let _5 := 0
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _6 := 64
                let _7 := mload(_6)
                /// @src 0:4374:4414  "OwnershipTransferred(oldOwner, newOwner)"
                log3(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _7, /** @src 0:4374:4414  "OwnershipTransferred(oldOwner, newOwner)" */ _5, _4, _3, var_newOwner)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_7395d4d3901c50cdfcab223d072f9aa36241df5d883e62cbf147ee1b05a9e6ba(memPtr)
            {
                let _1 := "ERC721: balance query for the ze"
                mstore(memPtr, _1)
                let _2 := "ro address"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_7395d4d3901c50cdfcab223d072f9aa36241df5d883e62cbf147ee1b05a9e6ba(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4328(pos)
                store_literal_in_memory_7395d4d3901c50cdfcab223d072f9aa36241df5d883e62cbf147ee1b05a9e6ba(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_7395(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_7395d4d3901c50cdfcab223d072f9aa36241df5d883e62cbf147ee1b05a9e6ba(_3)
            }
            function require_helper_stringliteral_7395(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_7395(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function mapping_index_access_mapping_address_uint256_of_address_4320(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:27793:27811  "_operatorApprovals"
                let _4 := 0x05
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _5 := 0x20
                mstore(_5, /** @src 0:27793:27811  "_operatorApprovals" */ _4)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_uint256_of_address_4329(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:25145:25154  "_balances"
                let _4 := 0x03
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _5 := 0x20
                mstore(_5, /** @src 0:25145:25154  "_balances" */ _4)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _6 := 0x40
                let _7 := _3
                dataSlot := keccak256(_3, _6)
            }
            function mapping_index_access_mapping_address_uint256_of_address_4355(key) -> dataSlot
            {
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(key, _1)
                let _3 := 0
                mstore(_3, _2)
                /// @src 0:37676:37688  "_ownedTokens"
                let _4 := 0x06
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _5 := 0x20
                mstore(_5, /** @src 0:37676:37688  "_ownedTokens" */ _4)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
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
            function read_from_storage_split_offset_uint256(slot) -> value
            {
                let _1 := sload(slot)
                value := cleanup_uint256(_1)
            }
            /// @ast-id 1021 @src 0:24963:25168  "function balanceOf(address owner) public view virtual override returns (uint256) {..."
            function fun_balanceOf(var_owner) -> var
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:25062:25081  "owner != address(0)" */ var_owner, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:25062:25081  "owner != address(0)"
                let _3 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2)
                /// @src 0:25062:25081  "owner != address(0)"
                let _4 := iszero(_3)
                /// @src 0:25054:25128  "require(owner != address(0), \"ERC721: balance query for the zero address\")"
                require_helper_stringliteral_7395(/** @src 0:25062:25081  "owner != address(0)" */ _4)
                /// @src 0:25145:25161  "_balances[owner]"
                let _5 := mapping_index_access_mapping_address_uint256_of_address_4329(var_owner)
                /// @src 0:25138:25161  "return _balances[owner]"
                var := /** @src 0:25145:25161  "_balances[owner]" */ read_from_storage_split_offset_uint256(_5)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function mapping_index_access_mapping_uint256_address_of_uint256_4331(key) -> dataSlot
            {
                let _1 := 0
                mstore(_1, key)
                /// @src 0:25332:25339  "_owners"
                let _2 := 0x02
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := 0x20
                mstore(_3, /** @src 0:25332:25339  "_owners" */ _2)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := 0x40
                let _5 := _1
                dataSlot := keccak256(_1, _4)
            }
            function mapping_index_access_mapping_uint256_address_of_uint256_4336(key) -> dataSlot
            {
                let _1 := 0
                mstore(_1, key)
                /// @src 0:27219:27234  "_tokenApprovals"
                let _2 := 0x04
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := 0x20
                mstore(_3, /** @src 0:27219:27234  "_tokenApprovals" */ _2)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := 0x40
                let _5 := _1
                dataSlot := keccak256(_1, _4)
            }
            function mapping_index_access_mapping_uint256_address_of_uint256_4360(key) -> dataSlot
            {
                let _1 := 0
                mstore(_1, key)
                /// @src 0:39830:39847  "_ownedTokensIndex"
                let _2 := 0x07
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := 0x20
                mstore(_3, /** @src 0:39830:39847  "_ownedTokensIndex" */ _2)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := 0x40
                let _5 := _1
                dataSlot := keccak256(_1, _4)
            }
            function mapping_index_access_mapping_uint256_address_of_uint256_4361(key) -> dataSlot
            {
                let _1 := 0
                mstore(_1, key)
                /// @src 0:40143:40158  "_allTokensIndex"
                let _2 := 0x09
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := 0x20
                mstore(_3, /** @src 0:40143:40158  "_allTokensIndex" */ _2)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := 0x40
                let _5 := _1
                dataSlot := keccak256(_1, _4)
            }
            function mapping_index_access_mapping_uint256_address_of_uint256_4400(key) -> dataSlot
            {
                let _1 := 0
                mstore(_1, key)
                /// @src 0:43711:43721  "_tokenURIs"
                let _2 := 0x0a
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := 0x20
                mstore(_3, /** @src 0:43711:43721  "_tokenURIs" */ _2)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := 0x40
                let _5 := _1
                dataSlot := keccak256(_1, _4)
            }
            function mapping_index_access_mapping_uint256_address_of_uint256(slot, key) -> dataSlot
            {
                let _1 := 0
                mstore(_1, key)
                let _2 := 0x20
                mstore(_2, slot)
                let _3 := 0x40
                let _4 := _1
                dataSlot := keccak256(_1, _3)
            }
            function store_literal_in_memory_7481f3df2a424c0755a1ad2356614e9a5a358d461ea2eae1f89cb21cbad00397(memPtr)
            {
                let _1 := "ERC721: owner query for nonexist"
                mstore(memPtr, _1)
                let _2 := "ent token"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_7481(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4330(pos)
                store_literal_in_memory_7481f3df2a424c0755a1ad2356614e9a5a358d461ea2eae1f89cb21cbad00397(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_7481(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_7481(_3)
            }
            function require_helper_stringliteral_7481(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_7481(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 1049 @src 0:25225:25460  "function ownerOf(uint256 tokenId) public view virtual override returns (address) {..."
            function fun_ownerOf(var_tokenId) -> var
            {
                /// @src 0:25332:25348  "_owners[tokenId]"
                let _1 := mapping_index_access_mapping_uint256_address_of_uint256_4331(var_tokenId)
                let _2 := read_from_storage_split_offset_address(_1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := sub(shl(160, 1), 1)
                let _4 := and(/** @src 0:25366:25385  "owner != address(0)" */ _2, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _3)
                /// @src 0:25366:25385  "owner != address(0)"
                let _5 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:25366:25385  "owner != address(0)"
                let _6 := iszero(_5)
                /// @src 0:25358:25431  "require(owner != address(0), \"ERC721: owner query for nonexistent token\")"
                require_helper_stringliteral_7481(/** @src 0:25366:25385  "owner != address(0)" */ _6)
                /// @src 0:25441:25453  "return owner"
                var := _2
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function panic_error_0x22()
            {
                let _1 := shl(224, 0x4e487b71)
                let _2 := 0
                mstore(_2, _1)
                let _3 := 0x22
                let _4 := 4
                mstore(_4, _3)
                let _5 := 0x24
                let _6 := _2
                revert(_2, _5)
            }
            function extract_byte_array_length(data) -> length
            {
                let _1 := 1
                length := shr(_1, data)
                let _2 := _1
                let outOfPlaceEncoding := and(data, _1)
                let _3 := iszero(outOfPlaceEncoding)
                if _3
                {
                    let _4 := 0x7f
                    length := and(length, _4)
                }
                let _5 := 32
                let _6 := lt(length, _5)
                let _7 := eq(outOfPlaceEncoding, _6)
                if _7 { panic_error_0x22() }
            }
            function array_dataslot_string_storage_8816() -> data
            {
                /// @src 0:37867:37877  "_allTokens"
                let _1 := 0x08
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := 0
                mstore(_2, /** @src 0:37867:37877  "_allTokens" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                data := 110349606679412691172957834289542550319383271247755660854362242977991410020067
            }
            function array_dataslot_string_storage_12165() -> data
            {
                /// @src 0:46064:46096  "_baseTokenURI = _newbaseTokenURI"
                let _1 := 0x0d
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := 0
                mstore(_2, /** @src 0:46064:46096  "_baseTokenURI = _newbaseTokenURI" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                data := 97569884605916225051403212656556507955018248777258318895762758024193532305077
            }
            function array_dataslot_string_storage_15559() -> data
            {
                let _1 := 0
                let _2 := _1
                mstore(_1, _1)
                data := 18569430475105882587588266137607568536673111973893317399460219858819262702947
            }
            function array_dataslot_string_storage_15560() -> data
            {
                /// @src 0:25772:25779  "_symbol"
                let _1 := 0x01
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := 0
                mstore(_2, /** @src 0:25772:25779  "_symbol" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                data := 80084422859880547211683076133703299733277748156566366325829078699459944778998
            }
            function array_dataslot_string_storage(ptr) -> data
            {
                let _1 := 0
                mstore(_1, ptr)
                let _2 := 0x20
                let _3 := _1
                data := keccak256(_1, _2)
            }
            function abi_encode_string_storage_12154(pos) -> ret
            {
                let _1 := 0
                let slotValue := sload(_1)
                let length := extract_byte_array_length(slotValue)
                let pos_1 := array_storeLengthForEncoding_string(pos, length)
                let _2 := 1
                let _3 := _2
                let _4 := and(slotValue, _2)
                switch _4
                case 0 {
                    let _5 := not(255)
                    let _6 := and(slotValue, _5)
                    mstore(pos_1, _6)
                    let _7 := 0x20
                    ret := add(pos_1, _7)
                }
                case 1 {
                    let dataPos := array_dataslot_string_storage_15559()
                    let i := _1
                    for { }
                    lt(i, length)
                    {
                        let _8 := 0x20
                        i := add(i, _8)
                    }
                    {
                        let _9 := sload(dataPos)
                        let _10 := add(pos_1, i)
                        mstore(_10, _9)
                        dataPos := add(dataPos, _2)
                    }
                    ret := add(pos_1, i)
                }
            }
            function abi_encode_string_storage_12155(pos) -> ret
            {
                /// @src 0:25772:25779  "_symbol"
                let _1 := 0x01
                let _2 := _1
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let slotValue := sload(/** @src 0:25772:25779  "_symbol" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let length := extract_byte_array_length(slotValue)
                let pos_1 := array_storeLengthForEncoding_string(pos, length)
                /// @src 0:25772:25779  "_symbol"
                let _3 := _1
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := and(slotValue, /** @src 0:25772:25779  "_symbol" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                switch _4
                case 0 {
                    let _5 := not(255)
                    let _6 := and(slotValue, _5)
                    mstore(pos_1, _6)
                    let _7 := 0x20
                    ret := add(pos_1, _7)
                }
                case 1 {
                    let dataPos := array_dataslot_string_storage_15560()
                    let i := 0
                    for { }
                    lt(i, length)
                    {
                        let _8 := 0x20
                        i := add(i, _8)
                    }
                    {
                        let _9 := sload(dataPos)
                        let _10 := add(pos_1, i)
                        mstore(_10, _9)
                        dataPos := add(dataPos, /** @src 0:25772:25779  "_symbol" */ _1)
                    }
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    ret := add(pos_1, i)
                }
            }
            function abi_encode_string_storage_12156(pos) -> ret
            {
                /// @src 0:46193:46206  "_baseTokenURI"
                let _1 := 0x0d
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let slotValue := sload(/** @src 0:46193:46206  "_baseTokenURI" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let length := extract_byte_array_length(slotValue)
                let pos_1 := array_storeLengthForEncoding_string(pos, length)
                let _2 := 1
                let _3 := _2
                let _4 := and(slotValue, _2)
                switch _4
                case 0 {
                    let _5 := not(255)
                    let _6 := and(slotValue, _5)
                    mstore(pos_1, _6)
                    let _7 := 0x20
                    ret := add(pos_1, _7)
                }
                case 1 {
                    let dataPos := array_dataslot_string_storage_12165()
                    let i := 0
                    for { }
                    lt(i, length)
                    {
                        let _8 := 0x20
                        i := add(i, _8)
                    }
                    {
                        let _9 := sload(dataPos)
                        let _10 := add(pos_1, i)
                        mstore(_10, _9)
                        dataPos := add(dataPos, _2)
                    }
                    ret := add(pos_1, i)
                }
            }
            function abi_encode_string_storage(value, pos) -> ret
            {
                let slotValue := sload(value)
                let length := extract_byte_array_length(slotValue)
                let pos_1 := array_storeLengthForEncoding_string(pos, length)
                let _1 := 1
                let _2 := _1
                let _3 := and(slotValue, _1)
                switch _3
                case 0 {
                    let _4 := not(255)
                    let _5 := and(slotValue, _4)
                    mstore(pos_1, _5)
                    let _6 := 0x20
                    ret := add(pos_1, _6)
                }
                case 1 {
                    let dataPos := array_dataslot_string_storage(value)
                    let i := 0
                    for { }
                    lt(i, length)
                    {
                        let _7 := 0x20
                        i := add(i, _7)
                    }
                    {
                        let _8 := sload(dataPos)
                        let _9 := add(pos_1, i)
                        mstore(_9, _8)
                        dataPos := add(dataPos, _1)
                    }
                    ret := add(pos_1, i)
                }
            }
            function copy_array_from_storage_to_memory_string_8788() -> memPtr
            {
                let _1 := 64
                memPtr := mload(_1)
                let _2 := abi_encode_string_storage_12154(memPtr)
                let _3 := sub(_2, memPtr)
                finalize_allocation(memPtr, _3)
            }
            function copy_array_from_storage_to_memory_string_8790() -> memPtr
            {
                let _1 := 64
                memPtr := mload(_1)
                let _2 := abi_encode_string_storage_12155(memPtr)
                let _3 := sub(_2, memPtr)
                finalize_allocation(memPtr, _3)
            }
            function copy_array_from_storage_to_memory_string_8829() -> memPtr
            {
                let _1 := 64
                memPtr := mload(_1)
                let _2 := abi_encode_string_storage_12156(memPtr)
                let _3 := sub(_2, memPtr)
                finalize_allocation(memPtr, _3)
            }
            function copy_array_from_storage_to_memory_string(slot) -> memPtr
            {
                let _1 := 64
                memPtr := mload(_1)
                let _2 := abi_encode_string_storage(slot, memPtr)
                let _3 := sub(_2, memPtr)
                finalize_allocation(memPtr, _3)
            }
            function convert_array_string_storage_to_string(value) -> converted
            {
                converted := copy_array_from_storage_to_memory_string(value)
            }
            function store_literal_in_memory_b51b4875eede07862961e8f9365c6749f5fe55c6ee5d7a9e42b6912ad0b15942(memPtr)
            {
                let _1 := "ERC721: approval to current owne"
                mstore(memPtr, _1)
                let _2 := "r"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_b51b4875eede07862961e8f9365c6749f5fe55c6ee5d7a9e42b6912ad0b15942(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4332(pos)
                store_literal_in_memory_b51b4875eede07862961e8f9365c6749f5fe55c6ee5d7a9e42b6912ad0b15942(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_b51b(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_b51b4875eede07862961e8f9365c6749f5fe55c6ee5d7a9e42b6912ad0b15942(_3)
            }
            function require_helper_stringliteral_b51b(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_b51b(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function store_literal_in_memory_6d83cef3e0cb19b8320a9c5feb26b56bbb08f152a8e61b12eca3302d8d68b23d(memPtr)
            {
                let _1 := "ERC721: approve caller is not ow"
                mstore(memPtr, _1)
                let _2 := "ner nor approved for all"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_6d83(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4333(pos)
                store_literal_in_memory_6d83cef3e0cb19b8320a9c5feb26b56bbb08f152a8e61b12eca3302d8d68b23d(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_6d83(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_6d83(_3)
            }
            function require_helper_stringliteral_6d83(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_6d83(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 1163 @src 0:26571:26972  "function approve(address to, uint256 tokenId) public virtual override {..."
            function fun_approve(var_to, var_tokenId)
            {
                /// @src 0:26667:26690  "ERC721.ownerOf(tokenId)"
                let expr := fun_ownerOf(var_tokenId)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                /// @src 0:26708:26719  "to != owner"
                let _2 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ and(/** @src 0:26708:26719  "to != owner" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                let _3 := and(/** @src 0:26708:26719  "to != owner" */ var_to, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:26708:26719  "to != owner"
                let _4 := eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _3, /** @src 0:26708:26719  "to != owner" */ _2)
                let _5 := iszero(_4)
                /// @src 0:26700:26757  "require(to != owner, \"ERC721: approval to current owner\")"
                require_helper_stringliteral_b51b(/** @src 0:26708:26719  "to != owner" */ _5)
                /// @src 0:2148:2158  "msg.sender"
                let _6 := caller()
                /// @src 0:26789:26851  "_msgSender() == owner || isApprovedForAll(owner, _msgSender())"
                let expr_1 := /** @src 0:26789:26810  "_msgSender() == owner" */ eq(/** @src 0:2148:2158  "msg.sender" */ _6, /** @src 0:26789:26810  "_msgSender() == owner" */ _2)
                /// @src 0:26789:26851  "_msgSender() == owner || isApprovedForAll(owner, _msgSender())"
                let _7 := iszero(expr_1)
                if _7
                {
                    /// @src 0:2148:2158  "msg.sender"
                    let _8 := _6
                    /// @src 0:27793:27818  "_operatorApprovals[owner]"
                    let _9 := mapping_index_access_mapping_address_uint256_of_address_4320(/** @src 0:26814:26851  "isApprovedForAll(owner, _msgSender())" */ expr)
                    /// @src 0:27793:27828  "_operatorApprovals[owner][operator]"
                    let _10 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:27793:27818  "_operatorApprovals[owner]" */ _9, /** @src 0:2148:2158  "msg.sender" */ _6)
                    /// @src 0:26789:26851  "_msgSender() == owner || isApprovedForAll(owner, _msgSender())"
                    expr_1 := /** @src 0:27793:27828  "_operatorApprovals[owner][operator]" */ read_from_storage_split_offset_bool(_10)
                }
                /// @src 0:26768:26933  "require(..."
                require_helper_stringliteral_6d83(expr_1)
                /// @src 0:26957:26964  "tokenId"
                fun__approve(var_to, var_tokenId)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_9291e0f44949204f2e9b40e6be090924979d6047b2365868f4e9f027722eb89d(memPtr)
            {
                let _1 := "ERC721: approved query for nonex"
                mstore(memPtr, _1)
                let _2 := "istent token"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_9291e0f44949204f2e9b40e6be090924979d6047b2365868f4e9f027722eb89d(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4335(pos)
                store_literal_in_memory_9291e0f44949204f2e9b40e6be090924979d6047b2365868f4e9f027722eb89d(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_9291(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_9291e0f44949204f2e9b40e6be090924979d6047b2365868f4e9f027722eb89d(_3)
            }
            function require_helper_stringliteral_9291(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_9291(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 1184 @src 0:27033:27250  "function getApproved(uint256 tokenId) public view virtual override returns (address) {..."
            function fun_getApproved(var_tokenId) -> var
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _2 := mapping_index_access_mapping_uint256_address_of_uint256_4331(/** @src 0:27136:27152  "_exists(tokenId)" */ var_tokenId)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _3 := read_from_storage_split_offset_address(_2)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := and(/** @src 0:30410:30426  "_owners[tokenId]" */ _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:30410:30440  "_owners[tokenId] != address(0)"
                let _5 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:30410:30440  "_owners[tokenId] != address(0)"
                let _6 := iszero(_5)
                /// @src 0:27128:27201  "require(_exists(tokenId), \"ERC721: approved query for nonexistent token\")"
                require_helper_stringliteral_9291(/** @src 0:30410:30440  "_owners[tokenId] != address(0)" */ _6)
                /// @src 0:27219:27243  "_tokenApprovals[tokenId]"
                let _7 := mapping_index_access_mapping_uint256_address_of_uint256_4336(var_tokenId)
                /// @src 0:27212:27243  "return _tokenApprovals[tokenId]"
                var := /** @src 0:27219:27243  "_tokenApprovals[tokenId]" */ read_from_storage_split_offset_address(_7)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_45fe4329685be5ecd250fd0e6a25aea0ea4d0e30fb6a73c118b95749e6d70d05(memPtr)
            {
                let _1 := "ERC721: approve to caller"
                mstore(memPtr, _1)
            }
            function abi_encode_stringliteral_45fe4329685be5ecd250fd0e6a25aea0ea4d0e30fb6a73c118b95749e6d70d05(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4337(pos)
                store_literal_in_memory_45fe4329685be5ecd250fd0e6a25aea0ea4d0e30fb6a73c118b95749e6d70d05(pos_1)
                let _1 := 32
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_45fe(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_45fe4329685be5ecd250fd0e6a25aea0ea4d0e30fb6a73c118b95749e6d70d05(_3)
            }
            function require_helper_stringliteral_45fe(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_45fe(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function update_byte_slice_shift_0(value, toInsert) -> result
            {
                let _1 := 255
                let _2 := and(toInsert, _1)
                let _3 := not(255)
                let _4 := and(value, _3)
                result := or(_4, _2)
            }
            function update_storage_value_offsett_bool_to_bool(slot, value)
            {
                let _1 := iszero(value)
                let _2 := iszero(_1)
                let _3 := sload(slot)
                let _4 := update_byte_slice_shift_0(_3, _2)
                sstore(slot, _4)
            }
            /// @ast-id 1218 @src 0:27317:27607  "function setApprovalForAll(address operator, bool approved) public virtual override {..."
            function fun_setApprovalForAll(var_operator, var_approved)
            {
                /// @src 0:2148:2158  "msg.sender"
                let _1 := caller()
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sub(shl(160, 1), 1)
                let _3 := and(/** @src 0:27419:27443  "operator != _msgSender()" */ var_operator, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2)
                /// @src 0:27419:27443  "operator != _msgSender()"
                let _4 := eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _3, /** @src 0:2148:2158  "msg.sender" */ _1)
                /// @src 0:27419:27443  "operator != _msgSender()"
                let _5 := iszero(_4)
                /// @src 0:27411:27473  "require(operator != _msgSender(), \"ERC721: approve to caller\")"
                require_helper_stringliteral_45fe(/** @src 0:27419:27443  "operator != _msgSender()" */ _5)
                /// @src 0:2148:2158  "msg.sender"
                let _6 := _1
                /// @src 0:27484:27516  "_operatorApprovals[_msgSender()]"
                let _7 := mapping_index_access_mapping_address_uint256_of_address_4320(/** @src 0:2148:2158  "msg.sender" */ _1)
                /// @src 0:27484:27526  "_operatorApprovals[_msgSender()][operator]"
                let _8 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:27484:27516  "_operatorApprovals[_msgSender()]" */ _7, /** @src 0:27484:27526  "_operatorApprovals[_msgSender()][operator]" */ var_operator)
                /// @src 0:27484:27537  "_operatorApprovals[_msgSender()][operator] = approved"
                update_storage_value_offsett_bool_to_bool(/** @src 0:27484:27526  "_operatorApprovals[_msgSender()][operator]" */ _8, /** @src 0:27484:27537  "_operatorApprovals[_msgSender()][operator] = approved" */ var_approved)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _9 := 64
                /// @src 0:27552:27600  "ApprovalForAll(_msgSender(), operator, approved)"
                let _10 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ mload(_9)
                /// @src 0:2148:2158  "msg.sender"
                let _11 := _1
                /// @src 0:27552:27600  "ApprovalForAll(_msgSender(), operator, approved)"
                let _12 := 0x17307eab39ab6107e8899845ad3d59bd9653f200f220920489ca2b5937696c31
                let _13 := abi_encode_bool(_10, var_approved)
                let _14 := sub(_13, _10)
                log3(_10, _14, _12, /** @src 0:2148:2158  "msg.sender" */ _1, /** @src 0:27552:27600  "ApprovalForAll(_msgSender(), operator, approved)" */ var_operator)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function extract_from_storage_value_offsett_bool(slot_value) -> value
            {
                let _1 := 0xff
                value := and(slot_value, _1)
            }
            function read_from_storage_split_offset_bool(slot) -> value
            {
                let _1 := sload(slot)
                value := extract_from_storage_value_offsett_bool(_1)
            }
            function store_literal_in_memory_c8682f3ad98807db59a6ec6bb812b72fed0a66e3150fa8239699ee83885247f2(memPtr)
            {
                let _1 := "ERC721: transfer caller is not o"
                mstore(memPtr, _1)
                let _2 := "wner nor approved"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_c868(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4339(pos)
                store_literal_in_memory_c8682f3ad98807db59a6ec6bb812b72fed0a66e3150fa8239699ee83885247f2(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_c868(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_c868(_3)
            }
            function require_helper_stringliteral_c868(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_c868(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 1263 @src 0:27897:28227  "function transferFrom(..."
            function fun_transferFrom(var_from, var_to, var_tokenId)
            {
                /// @src 0:2148:2158  "msg.sender"
                let _1 := caller()
                /// @src 0:28086:28127  "_isApprovedOrOwner(_msgSender(), tokenId)"
                let _2 := fun_isApprovedOrOwner(/** @src 0:2148:2158  "msg.sender" */ _1, /** @src 0:28086:28127  "_isApprovedOrOwner(_msgSender(), tokenId)" */ var_tokenId)
                /// @src 0:28078:28181  "require(_isApprovedOrOwner(_msgSender(), tokenId), \"ERC721: transfer caller is not owner nor approved\")"
                require_helper_stringliteral_c868(/** @src 0:28086:28127  "_isApprovedOrOwner(_msgSender(), tokenId)" */ _2)
                /// @src 0:28212:28219  "tokenId"
                fun_transfer(var_from, var_to, var_tokenId)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function allocate_memory_array_string_4340() -> memPtr
            {
                memPtr := allocate_memory_12158()
                let _1 := 0
                mstore(memPtr, _1)
            }
            function allocate_memory_array_string_4404() -> memPtr
            {
                memPtr := allocate_memory_12158()
                /// @src 0:26112:26113  "0"
                let _1 := 0x00
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                mstore(memPtr, /** @src 0:26112:26113  "0" */ _1)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function allocate_memory_array_string_4405() -> memPtr
            {
                memPtr := allocate_memory_12160()
                let _1 := 1
                mstore(memPtr, _1)
            }
            function allocate_memory_array_string(length) -> memPtr
            {
                let _1 := array_allocation_size_string(length)
                memPtr := allocate_memory(_1)
                mstore(memPtr, length)
            }
            /// @ast-id 1282 @src 0:28293:28472  "function safeTransferFrom(..."
            function fun_safeTransferFrom_1282(var_from, var_to, var_tokenId)
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := allocate_memory_array_string_4340()
                /// @src 0:28426:28465  "safeTransferFrom(from, to, tokenId, \"\")"
                fun_safeTransferFrom(var_from, var_to, var_tokenId, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
            }
            /// @ast-id 1312 @src 0:28538:28850  "function safeTransferFrom(..."
            function fun_safeTransferFrom(var_from, var_to, var_tokenId, var_data_mpos)
            {
                /// @src 0:2148:2158  "msg.sender"
                let _1 := caller()
                /// @src 0:28699:28740  "_isApprovedOrOwner(_msgSender(), tokenId)"
                let _2 := fun_isApprovedOrOwner(/** @src 0:2148:2158  "msg.sender" */ _1, /** @src 0:28699:28740  "_isApprovedOrOwner(_msgSender(), tokenId)" */ var_tokenId)
                /// @src 0:28691:28794  "require(_isApprovedOrOwner(_msgSender(), tokenId), \"ERC721: transfer caller is not owner nor approved\")"
                require_helper_stringliteral_c868(/** @src 0:28699:28740  "_isApprovedOrOwner(_msgSender(), tokenId)" */ _2)
                /// @src 0:28837:28842  "_data"
                fun_safeTransfer(var_from, var_to, var_tokenId, var_data_mpos)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_1e766a06da43a53d0f4c380e06e5a342e14d5af1bf8501996c844905530ca84e(memPtr)
            {
                let _1 := "ERC721: transfer to non ERC721Re"
                mstore(memPtr, _1)
                let _2 := "ceiver implementer"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_1e76(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4341(pos)
                store_literal_in_memory_1e766a06da43a53d0f4c380e06e5a342e14d5af1bf8501996c844905530ca84e(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_1e76(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_1e76(_3)
            }
            function require_helper_stringliteral_1e76(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_1e76(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 1341 @src 0:29712:30019  "function _safeTransfer(..."
            function fun_safeTransfer(var_from, var_to, var_tokenId, var_data_1321_mpos)
            {
                /// @src 0:29883:29890  "tokenId"
                fun_transfer(var_from, var_to, var_tokenId)
                /// @src 0:29909:29957  "_checkOnERC721Received(from, to, tokenId, _data)"
                let _1 := fun_checkOnERC721Received(var_from, var_to, var_tokenId, var_data_1321_mpos)
                /// @src 0:29901:30012  "require(_checkOnERC721Received(from, to, tokenId, _data), \"ERC721: transfer to non ERC721Receiver implementer\")"
                require_helper_stringliteral_1e76(/** @src 0:29909:29957  "_checkOnERC721Received(from, to, tokenId, _data)" */ _1)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_5797d1ccb08b83980dd0c07ea40d8f6a64d35fff736a19bdd17522954cb0899c(memPtr)
            {
                let _1 := "ERC721: operator query for nonex"
                mstore(memPtr, _1)
                let _2 := "istent token"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_5797d1ccb08b83980dd0c07ea40d8f6a64d35fff736a19bdd17522954cb0899c(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4335(pos)
                store_literal_in_memory_5797d1ccb08b83980dd0c07ea40d8f6a64d35fff736a19bdd17522954cb0899c(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_5797d1ccb08b83980dd0c07ea40d8f6a64d35fff736a19bdd17522954cb0899c(_3)
            }
            function require_helper_stringliteral(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 1400 @src 0:30605:30949  "function _isApprovedOrOwner(address spender, uint256 tokenId) internal view virtual returns (bool) {..."
            function fun_isApprovedOrOwner(var_spender, var_tokenId) -> var
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _2 := mapping_index_access_mapping_uint256_address_of_uint256_4331(/** @src 0:30722:30738  "_exists(tokenId)" */ var_tokenId)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _3 := read_from_storage_split_offset_address(_2)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := and(/** @src 0:30410:30426  "_owners[tokenId]" */ _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:30410:30440  "_owners[tokenId] != address(0)"
                let _5 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:30410:30440  "_owners[tokenId] != address(0)"
                let _6 := iszero(_5)
                /// @src 0:30714:30787  "require(_exists(tokenId), \"ERC721: operator query for nonexistent token\")"
                require_helper_stringliteral(/** @src 0:30410:30440  "_owners[tokenId] != address(0)" */ _6)
                /// @src 0:30813:30836  "ERC721.ownerOf(tokenId)"
                let expr := fun_ownerOf(var_tokenId)
                /// @src 0:30854:30870  "spender == owner"
                let _7 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ and(/** @src 0:30854:30870  "spender == owner" */ var_spender, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                let _8 := and(/** @src 0:30854:30870  "spender == owner" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:30854:30905  "spender == owner || getApproved(tokenId) == spender"
                let expr_1 := /** @src 0:30854:30870  "spender == owner" */ eq(_7, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _8)
                /// @src 0:30854:30905  "spender == owner || getApproved(tokenId) == spender"
                let _9 := iszero(expr_1)
                if _9
                {
                    /// @src 0:30874:30894  "getApproved(tokenId)"
                    let _10 := fun_getApproved(var_tokenId)
                    /// @src 0:30874:30905  "getApproved(tokenId) == spender"
                    let _11 := cleanup_address(/** @src 0:30874:30894  "getApproved(tokenId)" */ _10)
                    /// @src 0:30854:30905  "spender == owner || getApproved(tokenId) == spender"
                    expr_1 := /** @src 0:30874:30905  "getApproved(tokenId) == spender" */ eq(_11, _7)
                }
                /// @src 0:30854:30941  "spender == owner || getApproved(tokenId) == spender || isApprovedForAll(owner, spender)"
                let expr_2 := expr_1
                let _12 := iszero(expr_1)
                if _12
                {
                    /// @src 0:27793:27818  "_operatorApprovals[owner]"
                    let _13 := mapping_index_access_mapping_address_uint256_of_address_4320(/** @src 0:30909:30941  "isApprovedForAll(owner, spender)" */ expr)
                    /// @src 0:27793:27828  "_operatorApprovals[owner][operator]"
                    let _14 := mapping_index_access_mapping_address_uint256_of_address(/** @src 0:27793:27818  "_operatorApprovals[owner]" */ _13, /** @src 0:30909:30941  "isApprovedForAll(owner, spender)" */ var_spender)
                    /// @src 0:30854:30941  "spender == owner || getApproved(tokenId) == spender || isApprovedForAll(owner, spender)"
                    expr_2 := /** @src 0:27793:27828  "_operatorApprovals[owner][operator]" */ read_from_storage_split_offset_bool(_14)
                }
                /// @src 0:30846:30942  "return (spender == owner || getApproved(tokenId) == spender || isApprovedForAll(owner, spender))"
                var := expr_2
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_a01073130a885d6c1c1af6ac75fc3b1c4f9403c235362962bbf528e2bd87d950(memPtr)
            {
                let _1 := "ERC721: transfer of token that i"
                mstore(memPtr, _1)
                let _2 := "s not own"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_a01073130a885d6c1c1af6ac75fc3b1c4f9403c235362962bbf528e2bd87d950(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4330(pos)
                store_literal_in_memory_a01073130a885d6c1c1af6ac75fc3b1c4f9403c235362962bbf528e2bd87d950(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_a010(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_a01073130a885d6c1c1af6ac75fc3b1c4f9403c235362962bbf528e2bd87d950(_3)
            }
            function require_helper_stringliteral_a010(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_a010(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function store_literal_in_memory_455fea98ea03c32d7dd1a6f1426917d80529bf47b3ccbde74e7206e889e709f4(memPtr)
            {
                let _1 := "ERC721: transfer to the zero add"
                mstore(memPtr, _1)
                let _2 := "ress"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_455f(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4346(pos)
                store_literal_in_memory_455fea98ea03c32d7dd1a6f1426917d80529bf47b3ccbde74e7206e889e709f4(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_455f(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_455f(_3)
            }
            function require_helper_stringliteral_455f(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_455f(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
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
            function checked_sub_uint256(x) -> diff
            {
                /// @src 0:33952:33953  "1"
                let _1 := 0x01
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := lt(x, /** @src 0:33952:33953  "1" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                if _2 { panic_error_0x11() }
                let _3 := not(0)
                diff := add(x, _3)
            }
            function update_byte_slice_shift(value, toInsert) -> result
            { result := toInsert }
            function update_storage_value_offsett_uint256_to_uint256_4358(value)
            {
                /// @src 0:45399:45421  "_startDate = startDate"
                let _1 := 0x0e
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:45399:45421  "_startDate = startDate" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := update_byte_slice_shift(_2, value)
                /// @src 0:45399:45421  "_startDate = startDate"
                let _4 := _1
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                sstore(/** @src 0:45399:45421  "_startDate = startDate" */ _1, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _3)
            }
            function update_storage_value_offsett_uint256_to_uint256_8828(value)
            {
                /// @src 0:47268:47277  "_tokenIds"
                let _1 := 0x0c
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:47268:47277  "_tokenIds" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := update_byte_slice_shift(_2, value)
                /// @src 0:47268:47277  "_tokenIds"
                let _4 := _1
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                sstore(/** @src 0:47268:47277  "_tokenIds" */ _1, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _3)
            }
            function update_storage_value_offsett_uint256_to_uint256(slot, value)
            {
                let _1 := sload(slot)
                let _2 := update_byte_slice_shift(_1, value)
                sstore(slot, _2)
            }
            function checked_add_uint256_4351(x) -> sum
            {
                let _1 := not(1)
                let _2 := gt(x, _1)
                if _2 { panic_error_0x11() }
                /// @src 0:33952:33953  "1"
                let _3 := 0x01
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                sum := add(x, /** @src 0:33952:33953  "1" */ _3)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function checked_add_uint256_4409(y) -> sum
            {
                let _1 := not(y)
                /// @src 0:7258:7260  "48"
                let _2 := 0x30
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := gt(/** @src 0:7258:7260  "48" */ _2, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                if _3 { panic_error_0x11() }
                /// @src 0:7258:7260  "48"
                let _4 := _2
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                sum := add(/** @src 0:7258:7260  "48" */ _2, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ y)
            }
            function checked_add_uint256(x, y) -> sum
            {
                let _1 := not(y)
                let _2 := gt(x, _1)
                if _2 { panic_error_0x11() }
                sum := add(x, y)
            }
            /// @ast-id 1621 @src 0:33502:34062  "function _transfer(..."
            function fun_transfer(var_from, var_to, var_tokenId)
            {
                /// @src 0:33629:33652  "ERC721.ownerOf(tokenId)"
                let expr := fun_ownerOf(var_tokenId)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:33629:33660  "ERC721.ownerOf(tokenId) == from" */ var_from, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                let _3 := and(/** @src 0:33629:33660  "ERC721.ownerOf(tokenId) == from" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:33629:33660  "ERC721.ownerOf(tokenId) == from"
                let _4 := eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _3, _2)
                /// @src 0:33621:33706  "require(ERC721.ownerOf(tokenId) == from, \"ERC721: transfer of token that is not own\")"
                require_helper_stringliteral_a010(/** @src 0:33629:33660  "ERC721.ownerOf(tokenId) == from" */ _4)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _5 := and(/** @src 0:33724:33740  "to != address(0)" */ var_to, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:33724:33740  "to != address(0)"
                let _6 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _5)
                /// @src 0:33724:33740  "to != address(0)"
                let _7 := iszero(_6)
                /// @src 0:33716:33781  "require(to != address(0), \"ERC721: transfer to the zero address\")"
                require_helper_stringliteral_455f(/** @src 0:33724:33740  "to != address(0)" */ _7)
                /// @src 0:33823:33830  "tokenId"
                fun_beforeTokenTransfer(var_from, var_to, var_tokenId)
                /// @src 0:33914:33921  "tokenId"
                fun_approve_4347(var_tokenId)
                /// @src 0:33933:33948  "_balances[from]"
                let _8 := mapping_index_access_mapping_address_uint256_of_address_4329(var_from)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _9 := sload(/** @src 0:33933:33953  "_balances[from] -= 1" */ _8)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _10 := cleanup_uint256(_9)
                /// @src 0:33933:33953  "_balances[from] -= 1"
                let _11 := checked_sub_uint256(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _10)
                /// @src 0:33933:33953  "_balances[from] -= 1"
                update_storage_value_offsett_uint256_to_uint256(_8, _11)
                /// @src 0:33963:33976  "_balances[to]"
                let _12 := mapping_index_access_mapping_address_uint256_of_address_4329(var_to)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _13 := sload(/** @src 0:33963:33981  "_balances[to] += 1" */ _12)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _14 := cleanup_uint256(_13)
                /// @src 0:33963:33981  "_balances[to] += 1"
                let _15 := checked_add_uint256_4351(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _14)
                /// @src 0:33963:33981  "_balances[to] += 1"
                update_storage_value_offsett_uint256_to_uint256(_12, _15)
                /// @src 0:33991:34007  "_owners[tokenId]"
                let _16 := mapping_index_access_mapping_uint256_address_of_uint256_4331(var_tokenId)
                /// @src 0:33991:34012  "_owners[tokenId] = to"
                update_storage_value_offsett_address_to_address(/** @src 0:33991:34007  "_owners[tokenId]" */ _16, /** @src 0:33991:34012  "_owners[tokenId] = to" */ var_to)
                /// @src 0:34028:34055  "Transfer(from, to, tokenId)"
                let _17 := 0xddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef
                /// @src 0:33738:33739  "0"
                let _18 := 0x00
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _19 := 64
                let _20 := mload(_19)
                /// @src 0:34028:34055  "Transfer(from, to, tokenId)"
                log4(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _20, /** @src 0:33738:33739  "0" */ _18, /** @src 0:34028:34055  "Transfer(from, to, tokenId)" */ _17, var_from, var_to, var_tokenId)
            }
            /// @ast-id 1645 @src 0:34173:34344  "function _approve(address to, uint256 tokenId) internal virtual {..."
            function fun_approve_4347(var_tokenId)
            {
                /// @src 0:34247:34271  "_tokenApprovals[tokenId]"
                let _1 := mapping_index_access_mapping_uint256_address_of_uint256_4336(var_tokenId)
                /// @src 0:34247:34276  "_tokenApprovals[tokenId] = to"
                update_storage_value_offsett_address_to_address_8815(/** @src 0:34247:34271  "_tokenApprovals[tokenId]" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := 0
                /// @src 0:34300:34323  "ERC721.ownerOf(tokenId)"
                let _3 := fun_ownerOf(var_tokenId)
                /// @src 0:34291:34337  "Approval(ERC721.ownerOf(tokenId), to, tokenId)"
                let _4 := 0x8c5be1e5ebec7d5bd14f71427d1e84f3dd0314c0f7b2291e5b200ac8c7c3b925
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _5 := _2
                let _6 := 64
                let _7 := mload(_6)
                /// @src 0:34291:34337  "Approval(ERC721.ownerOf(tokenId), to, tokenId)"
                log4(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _7, _2, /** @src 0:34291:34337  "Approval(ERC721.ownerOf(tokenId), to, tokenId)" */ _4, /** @src 0:34300:34323  "ERC721.ownerOf(tokenId)" */ _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2, /** @src 0:34291:34337  "Approval(ERC721.ownerOf(tokenId), to, tokenId)" */ var_tokenId)
            }
            /// @ast-id 1645 @src 0:34173:34344  "function _approve(address to, uint256 tokenId) internal virtual {..."
            function fun__approve(var_to, var_tokenId)
            {
                /// @src 0:34247:34271  "_tokenApprovals[tokenId]"
                let _1 := mapping_index_access_mapping_uint256_address_of_uint256_4336(var_tokenId)
                /// @src 0:34247:34276  "_tokenApprovals[tokenId] = to"
                update_storage_value_offsett_address_to_address(/** @src 0:34247:34271  "_tokenApprovals[tokenId]" */ _1, /** @src 0:34247:34276  "_tokenApprovals[tokenId] = to" */ var_to)
                /// @src 0:34300:34323  "ERC721.ownerOf(tokenId)"
                let _2 := fun_ownerOf(var_tokenId)
                /// @src 0:34291:34337  "Approval(ERC721.ownerOf(tokenId), to, tokenId)"
                let _3 := 0x8c5be1e5ebec7d5bd14f71427d1e84f3dd0314c0f7b2291e5b200ac8c7c3b925
                let _4 := 0
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _5 := 64
                let _6 := mload(_5)
                /// @src 0:34291:34337  "Approval(ERC721.ownerOf(tokenId), to, tokenId)"
                log4(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _6, /** @src 0:34291:34337  "Approval(ERC721.ownerOf(tokenId), to, tokenId)" */ _4, _3, /** @src 0:34300:34323  "ERC721.ownerOf(tokenId)" */ _2, /** @src 0:34291:34337  "Approval(ERC721.ownerOf(tokenId), to, tokenId)" */ var_to, var_tokenId)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function abi_decode_bytes4_fromMemory(offset) -> value
            {
                value := mload(offset)
                validator_revert_bytes4(value)
            }
            function abi_decode_tuple_bytes4_fromMemory(headStart, dataEnd) -> value0
            {
                let _1 := 32
                let _2 := sub(dataEnd, headStart)
                let _3 := slt(_2, _1)
                if _3
                {
                    revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                }
                value0 := abi_decode_bytes4_fromMemory(headStart)
            }
            function abi_encode_address_address_uint256_bytes(headStart, value0, value1, value2, value3) -> tail
            {
                abi_encode_address(value0, headStart)
                let _1 := 32
                let _2 := add(headStart, _1)
                abi_encode_address(value1, _2)
                let _3 := 64
                let _4 := add(headStart, _3)
                abi_encode_uint256_to_uint256(value2, _4)
                let _5 := 128
                let _6 := 96
                let _7 := add(headStart, _6)
                mstore(_7, _5)
                let _8 := _5
                let _9 := add(headStart, _5)
                tail := abi_encode_string_to_string(value3, _9)
            }
            function extract_returndata() -> data
            {
                let _1 := returndatasize()
                switch _1
                case 0 { data := 96 }
                default {
                    let _2 := returndatasize()
                    data := allocate_memory_array_string(_2)
                    let _3 := returndatasize()
                    let _4 := 0
                    let _5 := 0x20
                    let _6 := add(data, _5)
                    returndatacopy(_6, _4, _3)
                }
            }
            /// @ast-id 1709 @src 0:34897:35679  "function _checkOnERC721Received(..."
            function fun_checkOnERC721Received(var_from, var_to, var_tokenId, var__data_mpos) -> var
            {
                /// @src 0:35047:35051  "bool"
                var := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ 0
                /// @src 0:9433:9494  "assembly {..."
                let _1 := extcodesize(/** @src 0:35067:35082  "to.isContract()" */ var_to)
                /// @src 0:9510:9518  "size > 0"
                let _2 := iszero(/** @src 0:9433:9494  "assembly {..." */ _1)
                /// @src 0:9510:9518  "size > 0"
                let _3 := iszero(_2)
                /// @src 0:35063:35673  "if (to.isContract()) {..."
                switch /** @src 0:9510:9518  "size > 0" */ _3
                case /** @src 0:35063:35673  "if (to.isContract()) {..." */ 0 {
                    /// @src 0:35651:35662  "return true"
                    var := /** @src 0:35658:35662  "true" */ 0x01
                    /// @src 0:35651:35662  "return true"
                    leave
                }
                default /// @src 0:35063:35673  "if (to.isContract()) {..."
                {
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _4 := sub(shl(160, 1), 1)
                    let _5 := and(/** @src 0:35102:35121  "IERC721Receiver(to)" */ var_to, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                    /// @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)"
                    let _6 := extcodesize(_5)
                    let _7 := iszero(_6)
                    if _7
                    {
                        revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
                    }
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _8 := 64
                    /// @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)"
                    let _9 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ mload(_8)
                    let _10 := shl(225, 0x0a85bd01)
                    /// @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)"
                    mstore(_9, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _10)
                    /// @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)"
                    let _11 := 32
                    /// @src 0:2148:2158  "msg.sender"
                    let _12 := caller()
                    /// @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)"
                    let _13 := 4
                    let _14 := add(_9, _13)
                    let _15 := abi_encode_address_address_uint256_bytes(_14, /** @src 0:2148:2158  "msg.sender" */ _12, /** @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)" */ var_from, var_tokenId, var__data_mpos)
                    let _16 := sub(_15, _9)
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _17 := 0
                    /// @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)"
                    let _18 := gas()
                    let trySuccessCondition := call(_18, _5, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _17, /** @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)" */ _9, _16, _9, _11)
                    let expr := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _17
                    /// @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)"
                    if trySuccessCondition
                    {
                        let _19 := returndatasize()
                        finalize_allocation(_9, _19)
                        let _20 := returndatasize()
                        let _21 := add(_9, _20)
                        expr := abi_decode_tuple_bytes4_fromMemory(_9, _21)
                    }
                    /// @src 0:35098:35621  "try IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data) returns (bytes4 retval) {..."
                    let _22 := iszero(trySuccessCondition)
                    switch _22
                    case 0 {
                        /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                        let _23 := shl(224, 0xffffffff)
                        let _24 := and(/** @src 0:35224:35279  "retval == IERC721Receiver(to).onERC721Received.selector" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _23)
                        /// @src 0:35217:35279  "return retval == IERC721Receiver(to).onERC721Received.selector"
                        var := /** @src 0:35224:35279  "retval == IERC721Receiver(to).onERC721Received.selector" */ eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _24, _10)
                        /// @src 0:35217:35279  "return retval == IERC721Receiver(to).onERC721Received.selector"
                        leave
                    }
                    default /// @src 0:35098:35621  "try IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data) returns (bytes4 retval) {..."
                    {
                        /// @src 0:35295:35621  "catch (bytes memory reason) {..."
                        let var_reason_mpos := extract_returndata()
                        /// @src 0:35345:35358  "reason.length"
                        let expr_1 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ mload(/** @src 0:35345:35358  "reason.length" */ var_reason_mpos)
                        /// @src 0:35345:35363  "reason.length == 0"
                        let _25 := iszero(expr_1)
                        /// @src 0:35341:35607  "if (reason.length == 0) {..."
                        switch /** @src 0:35345:35363  "reason.length == 0" */ _25
                        case /** @src 0:35341:35607  "if (reason.length == 0) {..." */ 0 {
                            /// @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)"
                            let _26 := _11
                            /// @src 0:35494:35589  "assembly {..."
                            let _27 := add(/** @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)" */ _11, /** @src 0:35494:35589  "assembly {..." */ var_reason_mpos)
                            revert(_27, expr_1)
                        }
                        default /// @src 0:35341:35607  "if (reason.length == 0) {..."
                        {
                            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                            let _28 := _8
                            /// @src 0:35387:35447  "revert(\"ERC721: transfer to non ERC721Receiver implementer\")"
                            let _29 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ mload(_8)
                            /// @src 0:35387:35447  "revert(\"ERC721: transfer to non ERC721Receiver implementer\")"
                            let _30 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ shl(229, 4594637)
                            /// @src 0:35387:35447  "revert(\"ERC721: transfer to non ERC721Receiver implementer\")"
                            mstore(_29, _30)
                            /// @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)"
                            let _31 := _13
                            /// @src 0:35387:35447  "revert(\"ERC721: transfer to non ERC721Receiver implementer\")"
                            let _32 := add(_29, /** @src 0:35102:35174  "IERC721Receiver(to).onERC721Received(_msgSender(), from, tokenId, _data)" */ _13)
                            /// @src 0:35387:35447  "revert(\"ERC721: transfer to non ERC721Receiver implementer\")"
                            let _33 := abi_encode_tuple_stringliteral_1e76(_32)
                            let _34 := sub(_33, _29)
                            revert(_29, _34)
                        }
                    }
                }
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_1d7f5dcf03a65f41ee49b0ab593e3851cfbe3fd7da53b6cf4eddd83c7df5734c(memPtr)
            {
                let _1 := "ERC721Enumerable: owner index ou"
                mstore(memPtr, _1)
                let _2 := "t of bounds"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_1d7f5dcf03a65f41ee49b0ab593e3851cfbe3fd7da53b6cf4eddd83c7df5734c(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4354(pos)
                store_literal_in_memory_1d7f5dcf03a65f41ee49b0ab593e3851cfbe3fd7da53b6cf4eddd83c7df5734c(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_1d7f(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_1d7f5dcf03a65f41ee49b0ab593e3851cfbe3fd7da53b6cf4eddd83c7df5734c(_3)
            }
            function require_helper_stringliteral_1d7f(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_1d7f(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 1795 @src 0:37456:37709  "function tokenOfOwnerByIndex(address owner, uint256 index) public view virtual override returns (uint256) {..."
            function fun_tokenOfOwnerByIndex(var_owner, var_index) -> var
            {
                /// @src 0:37588:37611  "ERC721.balanceOf(owner)"
                let _1 := fun_balanceOf(var_owner)
                /// @src 0:37580:37611  "index < ERC721.balanceOf(owner)"
                let _2 := cleanup_uint256(/** @src 0:37588:37611  "ERC721.balanceOf(owner)" */ _1)
                /// @src 0:37580:37611  "index < ERC721.balanceOf(owner)"
                let _3 := lt(var_index, _2)
                /// @src 0:37572:37659  "require(index < ERC721.balanceOf(owner), \"ERC721Enumerable: owner index out of bounds\")"
                require_helper_stringliteral_1d7f(/** @src 0:37580:37611  "index < ERC721.balanceOf(owner)" */ _3)
                /// @src 0:37676:37695  "_ownedTokens[owner]"
                let _4 := mapping_index_access_mapping_address_uint256_of_address_4355(var_owner)
                /// @src 0:37676:37702  "_ownedTokens[owner][index]"
                let _5 := mapping_index_access_mapping_uint256_address_of_uint256(/** @src 0:37676:37695  "_ownedTokens[owner]" */ _4, /** @src 0:37676:37702  "_ownedTokens[owner][index]" */ var_index)
                /// @src 0:37669:37702  "return _ownedTokens[owner][index]"
                var := /** @src 0:37676:37702  "_ownedTokens[owner][index]" */ read_from_storage_split_offset_uint256(_5)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_d269a4e9f5820dcdb69ea21f528512eb9b927c8d846d48aa51c9219f461d4dcc(memPtr)
            {
                let _1 := "ERC721Enumerable: global index o"
                mstore(memPtr, _1)
                let _2 := "ut of bounds"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_d269a4e9f5820dcdb69ea21f528512eb9b927c8d846d48aa51c9219f461d4dcc(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4335(pos)
                store_literal_in_memory_d269a4e9f5820dcdb69ea21f528512eb9b927c8d846d48aa51c9219f461d4dcc(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_d269(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_d269a4e9f5820dcdb69ea21f528512eb9b927c8d846d48aa51c9219f461d4dcc(_3)
            }
            function require_helper_stringliteral_d269(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_d269(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
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
            function storage_array_index_access_uint256_dyn(index) -> slot, offset
            {
                /// @src 0:37867:37877  "_allTokens"
                let _1 := 0x08
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:37867:37877  "_allTokens" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := lt(index, _2)
                let _4 := iszero(_3)
                if _4 { panic_error_0x32() }
                let _5 := array_dataslot_string_storage_8816()
                slot := add(_5, index)
                offset := 0
            }
            /// @ast-id 1829 @src 0:37963:38193  "function tokenByIndex(uint256 index) public view virtual override returns (uint256) {..."
            function fun_tokenByIndex(var_index) -> var
            {
                /// @src 0:37867:37877  "_allTokens"
                let _1 := 0x08
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:37867:37877  "_allTokens" */ _1)
                /// @src 0:38065:38103  "index < ERC721Enumerable.totalSupply()"
                let _3 := cleanup_uint256(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2)
                /// @src 0:38065:38103  "index < ERC721Enumerable.totalSupply()"
                let _4 := lt(var_index, _3)
                /// @src 0:38057:38152  "require(index < ERC721Enumerable.totalSupply(), \"ERC721Enumerable: global index out of bounds\")"
                require_helper_stringliteral_d269(/** @src 0:38065:38103  "index < ERC721Enumerable.totalSupply()" */ _4)
                /// @src 0:38169:38186  "_allTokens[index]"
                let _5, _6 := storage_array_index_access_uint256_dyn(var_index)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _7 := sload(/** @src 0:38169:38186  "_allTokens[index]" */ _5)
                /// @src 0:38162:38186  "return _allTokens[index]"
                var := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ extract_from_storage_value_dynamict_uint256(_7, /** @src 0:38169:38186  "_allTokens[index]" */ _6)
            }
            /// @ast-id 138 @src 0:3357:3474  "modifier onlyOwner() {..."
            function modifier_onlyOwner(var_startDate)
            {
                /// @src 0:3256:3262  "_owner"
                let _1 := 0x0b
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:3256:3262  "_owner" */ _1)
                /// @src 0:3396:3403  "owner()"
                let expr := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ cleanup_address(_2)
                /// @src 0:2148:2158  "msg.sender"
                let _3 := caller()
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := sub(shl(160, 1), 1)
                let _5 := and(/** @src 0:3396:3419  "owner() == _msgSender()" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:3396:3419  "owner() == _msgSender()"
                let _6 := eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _5, /** @src 0:2148:2158  "msg.sender" */ _3)
                /// @src 0:3388:3456  "require(owner() == _msgSender(), \"Ownable: caller is not the owner\")"
                require_helper_stringliteral_9924(/** @src 0:3396:3419  "owner() == _msgSender()" */ _6)
                /// @src 0:3466:3467  "_"
                fun_setStartDate_inner(var_startDate)
            }
            /// @src 0:45331:45428  "function setStartDate(uint256 startDate) public onlyOwner {..."
            function fun_setStartDate_inner(var_startDate)
            {
                /// @src 0:45399:45421  "_startDate = startDate"
                update_storage_value_offsett_uint256_to_uint256_4358(var_startDate)
            }
            /// @ast-id 2225 @src 0:45331:45428  "function setStartDate(uint256 startDate) public onlyOwner {..."
            function fun_setStartDate(var_startDate)
            {
                modifier_onlyOwner(var_startDate)
            }
            /// @ast-id 2246 @src 0:45435:45644  "function _beforeTokenTransfer(..."
            function fun_beforeTokenTransfer_4395(var_to, var_tokenId)
            {
                /// @src 0:45629:45636  "tokenId"
                fun_beforeTokenTransfer_8819(var_to, var_tokenId)
            }
            /// @ast-id 2246 @src 0:45435:45644  "function _beforeTokenTransfer(..."
            function fun_beforeTokenTransfer(var_from, var_to, var_tokenId)
            {
                /// @src 0:45629:45636  "tokenId"
                fun_beforeTokenTransfer_1893(var_from, var_to, var_tokenId)
            }
            /// @ast-id 1893 @src 0:38789:39361  "function _beforeTokenTransfer(..."
            function fun_beforeTokenTransfer_8819(var_to, var_tokenId)
            {
                /// @src 0:39054:39061  "tokenId"
                fun_addTokenToAllTokensEnumeration(var_tokenId)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:39180:39196  "to == address(0)" */ var_to, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:39180:39196  "to == address(0)"
                let _3 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2)
                /// @src 0:39176:39355  "if (to == address(0)) {..."
                switch /** @src 0:39180:39196  "to == address(0)" */ _3
                case /** @src 0:39176:39355  "if (to == address(0)) {..." */ 0 {
                    /// @src 0:39336:39343  "tokenId"
                    fun_addTokenToOwnerEnumeration(var_to, var_tokenId)
                }
                default /// @src 0:39176:39355  "if (to == address(0)) {..."
                {
                    /// @src 0:39249:39256  "tokenId"
                    fun_removeTokenFromAllTokensEnumeration(var_tokenId)
                }
            }
            /// @ast-id 1893 @src 0:38789:39361  "function _beforeTokenTransfer(..."
            function fun_beforeTokenTransfer_1893(var_from, var_to, var_tokenId)
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                /// @src 0:38988:39006  "from == address(0)"
                let _2 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ and(/** @src 0:38988:39006  "from == address(0)" */ var_from, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:38988:39006  "from == address(0)"
                let _3 := iszero(_2)
                /// @src 0:38984:39167  "if (from == address(0)) {..."
                switch /** @src 0:38988:39006  "from == address(0)" */ _3
                case /** @src 0:38984:39167  "if (from == address(0)) {..." */ 0 {
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _4 := and(/** @src 0:39083:39093  "from != to" */ var_to, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                    /// @src 0:39083:39093  "from != to"
                    let _5 := eq(_2, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                    /// @src 0:39083:39093  "from != to"
                    let _6 := iszero(_5)
                    /// @src 0:39079:39167  "if (from != to) {..."
                    if /** @src 0:39083:39093  "from != to" */ _6
                    /// @src 0:39079:39167  "if (from != to) {..."
                    {
                        /// @src 0:39148:39155  "tokenId"
                        fun_removeTokenFromOwnerEnumeration(var_from, var_tokenId)
                    }
                }
                default /// @src 0:38984:39167  "if (from == address(0)) {..."
                {
                    /// @src 0:39054:39061  "tokenId"
                    fun_addTokenToAllTokensEnumeration(var_tokenId)
                }
                /// @src 0:39180:39196  "to == address(0)"
                let _7 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ and(/** @src 0:39180:39196  "to == address(0)" */ var_to, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:39180:39196  "to == address(0)"
                let _8 := iszero(_7)
                /// @src 0:39176:39355  "if (to == address(0)) {..."
                switch /** @src 0:39180:39196  "to == address(0)" */ _8
                case /** @src 0:39176:39355  "if (to == address(0)) {..." */ 0 {
                    /// @src 0:39278:39288  "to != from"
                    let _9 := eq(_7, _2)
                    let _10 := iszero(_9)
                    /// @src 0:39274:39355  "if (to != from) {..."
                    if /** @src 0:39278:39288  "to != from" */ _10
                    /// @src 0:39274:39355  "if (to != from) {..."
                    {
                        /// @src 0:39336:39343  "tokenId"
                        fun_addTokenToOwnerEnumeration(var_to, var_tokenId)
                    }
                }
                default /// @src 0:39176:39355  "if (to == address(0)) {..."
                {
                    /// @src 0:39249:39256  "tokenId"
                    fun_removeTokenFromAllTokensEnumeration(var_tokenId)
                }
            }
            /// @ast-id 1923 @src 0:39655:39872  "function _addTokenToOwnerEnumeration(address to, uint256 tokenId) private {..."
            function fun_addTokenToOwnerEnumeration(var_to, var_tokenId)
            {
                /// @src 0:39756:39776  "ERC721.balanceOf(to)"
                let expr := fun_balanceOf(var_to)
                /// @src 0:39786:39802  "_ownedTokens[to]"
                let _1 := mapping_index_access_mapping_address_uint256_of_address_4355(var_to)
                /// @src 0:39786:39810  "_ownedTokens[to][length]"
                let _2 := mapping_index_access_mapping_uint256_address_of_uint256(/** @src 0:39786:39802  "_ownedTokens[to]" */ _1, /** @src 0:39786:39810  "_ownedTokens[to][length]" */ expr)
                /// @src 0:39786:39820  "_ownedTokens[to][length] = tokenId"
                update_storage_value_offsett_uint256_to_uint256(/** @src 0:39786:39810  "_ownedTokens[to][length]" */ _2, /** @src 0:39786:39820  "_ownedTokens[to][length] = tokenId" */ var_tokenId)
                /// @src 0:39830:39856  "_ownedTokensIndex[tokenId]"
                let _3 := mapping_index_access_mapping_uint256_address_of_uint256_4360(var_tokenId)
                /// @src 0:39830:39865  "_ownedTokensIndex[tokenId] = length"
                update_storage_value_offsett_uint256_to_uint256(/** @src 0:39830:39856  "_ownedTokensIndex[tokenId]" */ _3, /** @src 0:39830:39865  "_ownedTokensIndex[tokenId] = length" */ expr)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function update_byte_slice_dynamic32_12163(value) -> result
            {
                result := /** @src 0:41724:41757  "delete _ownedTokensIndex[tokenId]" */ 0
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function update_byte_slice_dynamic32_8820(value, shiftBytes) -> result
            {
                let _1 := not(0)
                let _2 := 3
                let _3 := shl(_2, shiftBytes)
                let _4 := shl(_3, _1)
                let _5 := not(_4)
                result := and(value, _5)
            }
            function update_byte_slice_dynamic32(value, shiftBytes, toInsert) -> result
            {
                let _1 := 3
                let shiftBits := shl(_1, shiftBytes)
                let _2 := not(0)
                let mask := shl(shiftBits, _2)
                let _3 := shl(shiftBits, toInsert)
                let _4 := and(_3, mask)
                let _5 := not(mask)
                let _6 := and(value, _5)
                result := or(_6, _4)
            }
            function update_storage_value_uint256_to_uint256_8822(slot)
            {
                let _1 := sload(slot)
                let _2 := update_byte_slice_dynamic32_12163(_1)
                sstore(slot, _2)
            }
            function update_storage_value_uint256_to_uint256_4363(slot, offset)
            {
                let _1 := sload(slot)
                let _2 := update_byte_slice_dynamic32_8820(_1, offset)
                sstore(slot, _2)
            }
            function update_storage_value_uint256_to_uint256(slot, offset, value)
            {
                let _1 := sload(slot)
                let _2 := update_byte_slice_dynamic32(_1, offset, value)
                sstore(slot, _2)
            }
            function array_push_from_uint256_to_array_uint256_dyn_storage_ptr(value0)
            {
                /// @src 0:40170:40180  "_allTokens"
                let _1 := 0x08
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let oldLen := sload(/** @src 0:40170:40180  "_allTokens" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := 18446744073709551616
                let _3 := lt(oldLen, _2)
                let _4 := iszero(_3)
                if _4 { panic_error_0x41() }
                let _5 := 1
                let _6 := add(oldLen, _5)
                /// @src 0:40170:40180  "_allTokens"
                let _7 := _1
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                sstore(/** @src 0:40170:40180  "_allTokens" */ _1, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _6)
                let slot, offset := storage_array_index_access_uint256_dyn(oldLen)
                update_storage_value_uint256_to_uint256(slot, offset, value0)
            }
            /// @ast-id 1943 @src 0:40067:40228  "function _addTokenToAllTokensEnumeration(uint256 tokenId) private {..."
            function fun_addTokenToAllTokensEnumeration(var_tokenId)
            {
                /// @src 0:40170:40180  "_allTokens"
                let _1 := 0x08
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:40170:40180  "_allTokens" */ _1)
                /// @src 0:40143:40167  "_allTokensIndex[tokenId]"
                let _3 := mapping_index_access_mapping_uint256_address_of_uint256_4361(var_tokenId)
                /// @src 0:40143:40187  "_allTokensIndex[tokenId] = _allTokens.length"
                update_storage_value_offsett_uint256_to_uint256(/** @src 0:40143:40167  "_allTokensIndex[tokenId]" */ _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2)
                /// @src 0:40197:40221  "_allTokens.push(tokenId)"
                array_push_from_uint256_to_array_uint256_dyn_storage_ptr(var_tokenId)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function storage_set_to_zero_uint256_4370(slot)
            {
                update_storage_value_uint256_to_uint256_8822(slot)
            }
            function storage_set_to_zero_uint256(slot, offset)
            {
                update_storage_value_uint256_to_uint256_4363(slot, offset)
            }
            /// @ast-id 2006 @src 0:40845:41815  "function _removeTokenFromOwnerEnumeration(address from, uint256 tokenId) private {..."
            function fun_removeTokenFromOwnerEnumeration(var_from, var_tokenId)
            {
                /// @src 0:41132:41154  "ERC721.balanceOf(from)"
                let _1 := fun_balanceOf(var_from)
                /// @src 0:41132:41158  "ERC721.balanceOf(from) - 1"
                let expr := checked_sub_uint256(/** @src 0:41132:41154  "ERC721.balanceOf(from)" */ _1)
                /// @src 0:41189:41215  "_ownedTokensIndex[tokenId]"
                let _2 := mapping_index_access_mapping_uint256_address_of_uint256_4360(var_tokenId)
                let _3 := read_from_storage_split_offset_uint256(_2)
                /// @src 0:41319:41347  "tokenIndex != lastTokenIndex"
                let _4 := eq(_3, expr)
                let _5 := iszero(_4)
                /// @src 0:41315:41638  "if (tokenIndex != lastTokenIndex) {..."
                if /** @src 0:41319:41347  "tokenIndex != lastTokenIndex" */ _5
                /// @src 0:41315:41638  "if (tokenIndex != lastTokenIndex) {..."
                {
                    /// @src 0:41385:41403  "_ownedTokens[from]"
                    let _6 := mapping_index_access_mapping_address_uint256_of_address_4355(var_from)
                    /// @src 0:41385:41419  "_ownedTokens[from][lastTokenIndex]"
                    let _7 := mapping_index_access_mapping_uint256_address_of_uint256(/** @src 0:41385:41403  "_ownedTokens[from]" */ _6, /** @src 0:41385:41419  "_ownedTokens[from][lastTokenIndex]" */ expr)
                    let _8 := read_from_storage_split_offset_uint256(_7)
                    /// @src 0:41434:41452  "_ownedTokens[from]"
                    let _9 := mapping_index_access_mapping_address_uint256_of_address_4355(var_from)
                    /// @src 0:41434:41464  "_ownedTokens[from][tokenIndex]"
                    let _10 := mapping_index_access_mapping_uint256_address_of_uint256(/** @src 0:41434:41452  "_ownedTokens[from]" */ _9, /** @src 0:41434:41464  "_ownedTokens[from][tokenIndex]" */ _3)
                    /// @src 0:41434:41478  "_ownedTokens[from][tokenIndex] = lastTokenId"
                    update_storage_value_offsett_uint256_to_uint256(/** @src 0:41434:41464  "_ownedTokens[from][tokenIndex]" */ _10, /** @src 0:41434:41478  "_ownedTokens[from][tokenIndex] = lastTokenId" */ _8)
                    /// @src 0:41550:41580  "_ownedTokensIndex[lastTokenId]"
                    let _11 := mapping_index_access_mapping_uint256_address_of_uint256_4360(_8)
                    /// @src 0:41550:41593  "_ownedTokensIndex[lastTokenId] = tokenIndex"
                    update_storage_value_offsett_uint256_to_uint256(/** @src 0:41550:41580  "_ownedTokensIndex[lastTokenId]" */ _11, /** @src 0:41550:41593  "_ownedTokensIndex[lastTokenId] = tokenIndex" */ _3)
                }
                /// @src 0:41731:41757  "_ownedTokensIndex[tokenId]"
                let _12 := mapping_index_access_mapping_uint256_address_of_uint256_4360(var_tokenId)
                /// @src 0:41724:41757  "delete _ownedTokensIndex[tokenId]"
                storage_set_to_zero_uint256_4370(/** @src 0:41731:41757  "_ownedTokensIndex[tokenId]" */ _12)
                /// @src 0:41774:41792  "_ownedTokens[from]"
                let _13 := mapping_index_access_mapping_address_uint256_of_address_4355(var_from)
                /// @src 0:41774:41808  "_ownedTokens[from][lastTokenIndex]"
                let _14 := mapping_index_access_mapping_uint256_address_of_uint256(/** @src 0:41774:41792  "_ownedTokens[from]" */ _13, /** @src 0:41774:41808  "_ownedTokens[from][lastTokenIndex]" */ expr)
                /// @src 0:41767:41808  "delete _ownedTokens[from][lastTokenIndex]"
                storage_set_to_zero_uint256_4370(/** @src 0:41774:41808  "_ownedTokens[from][lastTokenIndex]" */ _14)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function panic_error_0x31()
            {
                let _1 := shl(224, 0x4e487b71)
                let _2 := 0
                mstore(_2, _1)
                let _3 := 0x31
                let _4 := 4
                mstore(_4, _3)
                let _5 := 0x24
                let _6 := _2
                revert(_2, _5)
            }
            function array_pop_array_uint256_dyn_storage_ptr()
            {
                /// @src 0:42377:42387  "_allTokens"
                let _1 := 0x08
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let oldLen := sload(/** @src 0:42377:42387  "_allTokens" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := iszero(oldLen)
                if _2 { panic_error_0x31() }
                let _3 := not(0)
                let newLen := add(oldLen, _3)
                let slot, offset := storage_array_index_access_uint256_dyn(newLen)
                storage_set_to_zero_uint256(slot, offset)
                /// @src 0:42377:42387  "_allTokens"
                let _4 := _1
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                sstore(/** @src 0:42377:42387  "_allTokens" */ _1, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ newLen)
            }
            /// @ast-id 2054 @src 0:42103:43164  "function _removeTokenFromAllTokensEnumeration(uint256 tokenId) private {..."
            function fun_removeTokenFromAllTokensEnumeration(var_tokenId)
            {
                /// @src 0:42377:42387  "_allTokens"
                let _1 := 0x08
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:42377:42387  "_allTokens" */ _1)
                /// @src 0:42377:42398  "_allTokens.length - 1"
                let expr := checked_sub_uint256(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2)
                /// @src 0:42429:42453  "_allTokensIndex[tokenId]"
                let _3 := mapping_index_access_mapping_uint256_address_of_uint256_4361(var_tokenId)
                let _4 := read_from_storage_split_offset_uint256(_3)
                /// @src 0:42797:42823  "_allTokens[lastTokenIndex]"
                let _5, _6 := storage_array_index_access_uint256_dyn(expr)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _7 := sload(/** @src 0:42797:42823  "_allTokens[lastTokenIndex]" */ _5)
                let _8 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ extract_from_storage_value_dynamict_uint256(_7, /** @src 0:42797:42823  "_allTokens[lastTokenIndex]" */ _6)
                /// @src 0:42834:42856  "_allTokens[tokenIndex]"
                let _9, _10 := storage_array_index_access_uint256_dyn(_4)
                /// @src 0:42834:42870  "_allTokens[tokenIndex] = lastTokenId"
                update_storage_value_uint256_to_uint256(_9, _10, _8)
                /// @src 0:42938:42966  "_allTokensIndex[lastTokenId]"
                let _11 := mapping_index_access_mapping_uint256_address_of_uint256_4361(_8)
                /// @src 0:42938:42979  "_allTokensIndex[lastTokenId] = tokenIndex"
                update_storage_value_offsett_uint256_to_uint256(/** @src 0:42938:42966  "_allTokensIndex[lastTokenId]" */ _11, /** @src 0:42938:42979  "_allTokensIndex[lastTokenId] = tokenIndex" */ _4)
                /// @src 0:43107:43131  "_allTokensIndex[tokenId]"
                let _12 := mapping_index_access_mapping_uint256_address_of_uint256_4361(var_tokenId)
                /// @src 0:43100:43131  "delete _allTokensIndex[tokenId]"
                storage_set_to_zero_uint256_4370(/** @src 0:43107:43131  "_allTokensIndex[tokenId]" */ _12)
                /// @src 0:43141:43155  "_allTokens.pop"
                array_pop_array_uint256_dyn_storage_ptr()
            }
            /// @ast-id 2277 @src 0:45773:45978  "function supportsInterface(bytes4 interfaceId)..."
            function fun_supportsInterface_2277(var_interfaceId) -> var
            {
                /// @src 0:45928:45971  "return super.supportsInterface(interfaceId)"
                var := /** @src 0:45935:45971  "super.supportsInterface(interfaceId)" */ fun_supportsInterface(var_interfaceId)
            }
            /// @ast-id 1767 @src 0:37155:37377  "function supportsInterface(bytes4 interfaceId) public view virtual override(IERC165, ERC721) returns (bool) {..."
            function fun_supportsInterface(var_interfaceId) -> var
            {
                /// @src 0:37295:37330  "type(IERC721Enumerable).interfaceId"
                let _1 := shl(224, 0x780e9d63)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := shl(224, 0xffffffff)
                let _3 := and(/** @src 0:37280:37330  "interfaceId == type(IERC721Enumerable).interfaceId" */ var_interfaceId, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2)
                /// @src 0:37280:37370  "interfaceId == type(IERC721Enumerable).interfaceId || super.supportsInterface(interfaceId)"
                let expr := /** @src 0:37280:37330  "interfaceId == type(IERC721Enumerable).interfaceId" */ eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _3, /** @src 0:37295:37330  "type(IERC721Enumerable).interfaceId" */ _1)
                /// @src 0:37280:37370  "interfaceId == type(IERC721Enumerable).interfaceId || super.supportsInterface(interfaceId)"
                let _4 := iszero(expr)
                if _4
                {
                    expr := /** @src 0:37334:37370  "super.supportsInterface(interfaceId)" */ fun_supportsInterface_997(var_interfaceId)
                }
                /// @src 0:37273:37370  "return interfaceId == type(IERC721Enumerable).interfaceId || super.supportsInterface(interfaceId)"
                var := expr
            }
            /// @ast-id 997 @src 0:24604:24904  "function supportsInterface(bytes4 interfaceId) public view virtual override(ERC165, IERC165) returns (bool) {..."
            function fun_supportsInterface_997(var_interfaceId) -> var
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := shl(224, 0xffffffff)
                /// @src 0:24741:24781  "interfaceId == type(IERC721).interfaceId"
                let _2 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ and(/** @src 0:24741:24781  "interfaceId == type(IERC721).interfaceId" */ var_interfaceId, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:24756:24781  "type(IERC721).interfaceId"
                let _3 := shl(224, 0x80ac58cd)
                /// @src 0:24741:24845  "interfaceId == type(IERC721).interfaceId ||..."
                let expr := /** @src 0:24741:24781  "interfaceId == type(IERC721).interfaceId" */ eq(_2, /** @src 0:24756:24781  "type(IERC721).interfaceId" */ _3)
                /// @src 0:24741:24845  "interfaceId == type(IERC721).interfaceId ||..."
                let _4 := iszero(expr)
                if _4
                {
                    /// @src 0:24812:24845  "type(IERC721Metadata).interfaceId"
                    let _5 := shl(224, 0x5b5e139f)
                    /// @src 0:24741:24845  "interfaceId == type(IERC721).interfaceId ||..."
                    expr := /** @src 0:24797:24845  "interfaceId == type(IERC721Metadata).interfaceId" */ eq(_2, /** @src 0:24812:24845  "type(IERC721Metadata).interfaceId" */ _5)
                }
                /// @src 0:24741:24897  "interfaceId == type(IERC721).interfaceId ||..."
                let expr_1 := expr
                let _6 := iszero(expr)
                if _6
                {
                    /// @src 0:6324:6349  "type(IERC165).interfaceId"
                    let _7 := shl(224, 0x01ffc9a7)
                    /// @src 0:24741:24897  "interfaceId == type(IERC721).interfaceId ||..."
                    expr_1 := /** @src 0:6309:6349  "interfaceId == type(IERC165).interfaceId" */ eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2, /** @src 0:6324:6349  "type(IERC165).interfaceId" */ _7)
                }
                /// @src 0:24722:24897  "return..."
                var := expr_1
            }
            /// @ast-id 138 @src 0:3357:3474  "modifier onlyOwner() {..."
            function modifier_onlyOwner_2282(var_newbaseTokenURI_2279_mpos)
            {
                /// @src 0:3256:3262  "_owner"
                let _1 := 0x0b
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:3256:3262  "_owner" */ _1)
                /// @src 0:3396:3403  "owner()"
                let expr := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ cleanup_address(_2)
                /// @src 0:2148:2158  "msg.sender"
                let _3 := caller()
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := sub(shl(160, 1), 1)
                let _5 := and(/** @src 0:3396:3419  "owner() == _msgSender()" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:3396:3419  "owner() == _msgSender()"
                let _6 := eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _5, /** @src 0:2148:2158  "msg.sender" */ _3)
                /// @src 0:3388:3456  "require(owner() == _msgSender(), \"Ownable: caller is not the owner\")"
                require_helper_stringliteral_9924(/** @src 0:3396:3419  "owner() == _msgSender()" */ _6)
                /// @src 0:3466:3467  "_"
                fun_setBaseURI_inner(var_newbaseTokenURI_2279_mpos)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function clear_storage_range_bytes1(start, end)
            {
                for { }
                lt(start, end)
                {
                    let _1 := 1
                    start := add(start, _1)
                }
                {
                    storage_set_to_zero_uint256_4370(start)
                }
            }
            function clean_up_bytearray_end_slots_string_storage(len, startIndex)
            {
                let _1 := 31
                let _2 := gt(len, _1)
                if _2
                {
                    let dataArea := array_dataslot_string_storage_12165()
                    let _3 := _1
                    let _4 := add(startIndex, _1)
                    let _5 := 5
                    let _6 := shr(_5, _4)
                    let deleteStart := add(dataArea, _6)
                    let _7 := 32
                    let _8 := lt(startIndex, _7)
                    if _8 { deleteStart := dataArea }
                    let _9 := _1
                    let _10 := add(len, _1)
                    let _11 := _5
                    let _12 := shr(_5, _10)
                    let _13 := add(dataArea, _12)
                    clear_storage_range_bytes1(deleteStart, _13)
                }
            }
            function extract_used_part_and_set_length_of_short_byte_array(data, len) -> used
            {
                let _1 := 1
                let _2 := shl(_1, len)
                let _3 := not(0)
                let _4 := 3
                let _5 := shl(_4, len)
                let _6 := shr(_5, _3)
                let _7 := not(_6)
                let _8 := and(data, _7)
                used := or(_8, _2)
            }
            function copy_byte_array_to_storage_from_string_to_string(src)
            {
                let newLen := mload(src)
                let _1 := 0xffffffffffffffff
                let _2 := gt(newLen, _1)
                if _2 { panic_error_0x41() }
                /// @src 0:46064:46096  "_baseTokenURI = _newbaseTokenURI"
                let _3 := 0x0d
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := sload(/** @src 0:46064:46096  "_baseTokenURI = _newbaseTokenURI" */ _3)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _5 := extract_byte_array_length(_4)
                clean_up_bytearray_end_slots_string_storage(_5, newLen)
                let srcOffset := 0
                let srcOffset_1 := 0x20
                srcOffset := srcOffset_1
                let _6 := 31
                let _7 := gt(newLen, _6)
                switch _7
                case 1 {
                    let _8 := not(31)
                    let loopEnd := and(newLen, _8)
                    let dstPtr := array_dataslot_string_storage_12165()
                    let i := 0
                    for { } lt(i, loopEnd) { i := add(i, srcOffset_1) }
                    {
                        let _9 := add(src, srcOffset)
                        let _10 := mload(_9)
                        sstore(dstPtr, _10)
                        let _11 := 1
                        dstPtr := add(dstPtr, _11)
                        srcOffset := add(srcOffset, srcOffset_1)
                    }
                    let _12 := lt(loopEnd, newLen)
                    if _12
                    {
                        let _13 := add(src, srcOffset)
                        let lastValue := mload(_13)
                        let _14 := not(0)
                        let _15 := 248
                        let _16 := 3
                        let _17 := shl(_16, newLen)
                        let _18 := and(_17, _15)
                        let _19 := shr(_18, _14)
                        let _20 := not(_19)
                        let _21 := and(lastValue, _20)
                        sstore(dstPtr, _21)
                    }
                    let _22 := 1
                    let _23 := _22
                    let _24 := shl(_22, newLen)
                    let _25 := add(_24, _22)
                    /// @src 0:46064:46096  "_baseTokenURI = _newbaseTokenURI"
                    let _26 := _3
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    sstore(/** @src 0:46064:46096  "_baseTokenURI = _newbaseTokenURI" */ _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _25)
                }
                default {
                    let value := 0
                    if newLen
                    {
                        let _27 := add(src, srcOffset)
                        value := mload(_27)
                    }
                    let _28 := extract_used_part_and_set_length_of_short_byte_array(value, newLen)
                    /// @src 0:46064:46096  "_baseTokenURI = _newbaseTokenURI"
                    let _29 := _3
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    sstore(/** @src 0:46064:46096  "_baseTokenURI = _newbaseTokenURI" */ _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _28)
                }
            }
            function update_storage_value_offsett_string_to_string(value)
            {
                copy_byte_array_to_storage_from_string_to_string(value)
            }
            /// @src 0:45985:46103  "function setBaseURI(string memory _newbaseTokenURI) public onlyOwner {..."
            function fun_setBaseURI_inner(var_newbaseTokenURI_mpos)
            {
                /// @src 0:46064:46096  "_baseTokenURI = _newbaseTokenURI"
                update_storage_value_offsett_string_to_string(var_newbaseTokenURI_mpos)
            }
            /// @ast-id 2289 @src 0:45985:46103  "function setBaseURI(string memory _newbaseTokenURI) public onlyOwner {..."
            function fun_setBaseURI(var__newbaseTokenURI_mpos)
            {
                modifier_onlyOwner_2282(var__newbaseTokenURI_mpos)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function convert_rational_by_to_uint64(value) -> converted
            {
                let _1 := 0xffffffffffffffff
                converted := and(value, _1)
            }
            function store_literal_in_memory_c4b7d92cf2022b4aea219c2caac2262f0bce2743285a6b3f95ae579d77285653(memPtr)
            {
                let _1 := "Sale is not open"
                mstore(memPtr, _1)
            }
            function abi_encode_stringliteral_c4b7(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4384(pos)
                store_literal_in_memory_c4b7d92cf2022b4aea219c2caac2262f0bce2743285a6b3f95ae579d77285653(pos_1)
                let _1 := 32
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_c4b7(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_c4b7(_3)
            }
            function require_helper_stringliteral_c4b7(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_c4b7(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function store_literal_in_memory_bd1c3d5fabe63b2b94f9d7e98339f036d265768801de724e34399173f5040a27(memPtr)
            {
                let _1 := "Must mint at least 1"
                mstore(memPtr, _1)
            }
            function abi_encode_stringliteral_bd1c(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4385(pos)
                store_literal_in_memory_bd1c3d5fabe63b2b94f9d7e98339f036d265768801de724e34399173f5040a27(pos_1)
                let _1 := 32
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_bd1c(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_bd1c(_3)
            }
            function require_helper_stringliteral_bd1c(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_bd1c(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function store_literal_in_memory_3e5a3407ed8eb5333a5f521def8c9808a7d71dfbb338fc83ef364a892a9cc575(memPtr)
            {
                let _1 := "Maximum current buy limit for in"
                mstore(memPtr, _1)
                let _2 := "dividual transaction exceeded"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_3e5a(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4386(pos)
                store_literal_in_memory_3e5a3407ed8eb5333a5f521def8c9808a7d71dfbb338fc83ef364a892a9cc575(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_3e5a(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_3e5a(_3)
            }
            function require_helper_stringliteral_3e5a(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_3e5a(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function store_literal_in_memory_b83e72630929d78477fef4cca5c963cb5d623236248c325d9816c0b16266bfe6(memPtr)
            {
                let _1 := "Exceeds maximum supply"
                mstore(memPtr, _1)
            }
            function abi_encode_stringliteral_b83e(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4387(pos)
                store_literal_in_memory_b83e72630929d78477fef4cca5c963cb5d623236248c325d9816c0b16266bfe6(pos_1)
                let _1 := 32
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_b83e(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_b83e(_3)
            }
            function require_helper_stringliteral_b83e(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_b83e(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function checked_mul_uint64(y) -> product
            {
                let _1 := 0xffffffffffffffff
                let y_1 := and(y, _1)
                let _2 := 368
                let _3 := gt(y_1, _2)
                let _4 := 1
                let _5 := and(_4, _3)
                if _5 { panic_error_0x11() }
                let _6 := 0xb1a2bc2ec50000
                product := mul(_6, y_1)
            }
            function store_literal_in_memory_1db8aaffc36b67a4f4234783f53ec89d9eed23e4c4e0896fc7658fa69271585d(memPtr)
            {
                let _1 := "Ether submitted does not match c"
                mstore(memPtr, _1)
                let _2 := "urrent price"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_1db8aaffc36b67a4f4234783f53ec89d9eed23e4c4e0896fc7658fa69271585d(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4335(pos)
                store_literal_in_memory_1db8aaffc36b67a4f4234783f53ec89d9eed23e4c4e0896fc7658fa69271585d(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_1db8(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_1db8aaffc36b67a4f4234783f53ec89d9eed23e4c4e0896fc7658fa69271585d(_3)
            }
            function require_helper_stringliteral_1db8(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_1db8(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function increment_uint8(value) -> ret
            {
                let _1 := 0xff
                let value_1 := and(value, _1)
                let _2 := _1
                let _3 := eq(value_1, _1)
                if _3 { panic_error_0x11() }
                let _4 := 1
                ret := add(value_1, _4)
            }
            /// @ast-id 2395 @src 0:46582:47402  "function mint(uint8 _quantityToMint) public payable {..."
            function fun_mint(var_quantityToMint)
            {
                /// @src 0:46652:46662  "_startDate"
                let _1 := 0x0e
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:46652:46662  "_startDate" */ _1)
                let _3 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ cleanup_uint256(_2)
                /// @src 0:46666:46681  "block.timestamp"
                let _4 := timestamp()
                /// @src 0:46652:46681  "_startDate <= block.timestamp"
                let _5 := gt(_3, /** @src 0:46666:46681  "block.timestamp" */ _4)
                /// @src 0:46652:46681  "_startDate <= block.timestamp"
                let _6 := iszero(_5)
                /// @src 0:46644:46702  "require(_startDate <= block.timestamp, \"Sale is not open\")"
                require_helper_stringliteral_c4b7(/** @src 0:46652:46681  "_startDate <= block.timestamp" */ _6)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _7 := 0xff
                let _8 := _7
                /// @src 0:46720:46740  "_quantityToMint >= 1"
                let _9 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ and(/** @src 0:46720:46740  "_quantityToMint >= 1" */ var_quantityToMint, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _7)
                /// @src 0:46739:46740  "1"
                let _10 := 0x01
                /// @src 0:46720:46740  "_quantityToMint >= 1"
                let _11 := lt(_9, /** @src 0:46739:46740  "1" */ _10)
                /// @src 0:46720:46740  "_quantityToMint >= 1"
                let _12 := iszero(_11)
                /// @src 0:46712:46765  "require(_quantityToMint >= 1, \"Must mint at least 1\")"
                require_helper_stringliteral_bd1c(/** @src 0:46720:46740  "_quantityToMint >= 1" */ _12)
                /// @src 0:46377:46379  "30"
                let _13 := 0x1e
                /// @src 0:46796:46836  "_quantityToMint <= getCurrentMintLimit()"
                let _14 := gt(_9, /** @src 0:46377:46379  "30" */ _13)
                /// @src 0:46796:46836  "_quantityToMint <= getCurrentMintLimit()"
                let _15 := iszero(_14)
                /// @src 0:46775:46923  "require(..."
                require_helper_stringliteral_3e5a(/** @src 0:46796:46836  "_quantityToMint <= getCurrentMintLimit()" */ _15)
                /// @src 0:45167:45171  "5000"
                let _16 := 0x1388
                /// @src 0:37867:37877  "_allTokens"
                let _17 := 0x08
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _18 := sload(/** @src 0:37867:37877  "_allTokens" */ _17)
                /// @src 0:46955:46986  "_quantityToMint + totalSupply()"
                let _19 := checked_add_uint256(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _9, _18)
                /// @src 0:46954:47000  "(_quantityToMint + totalSupply()) <= maxSupply"
                let _20 := gt(/** @src 0:46955:46986  "_quantityToMint + totalSupply()" */ _19, /** @src 0:45167:45171  "5000" */ _16)
                /// @src 0:46954:47000  "(_quantityToMint + totalSupply()) <= maxSupply"
                let _21 := iszero(_20)
                /// @src 0:46933:47048  "require(..."
                require_helper_stringliteral_b83e(/** @src 0:46954:47000  "(_quantityToMint + totalSupply()) <= maxSupply" */ _21)
                /// @src 0:47093:47128  "getCurrentPrice() * _quantityToMint"
                let _22 := checked_mul_uint64(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _9)
                /// @src 0:47079:47129  "msg.value == (getCurrentPrice() * _quantityToMint)"
                let _23 := convert_rational_by_to_uint64(/** @src 0:47093:47128  "getCurrentPrice() * _quantityToMint" */ _22)
                /// @src 0:47079:47088  "msg.value"
                let _24 := callvalue()
                /// @src 0:47079:47129  "msg.value == (getCurrentPrice() * _quantityToMint)"
                let _25 := eq(/** @src 0:47079:47088  "msg.value" */ _24, /** @src 0:47079:47129  "msg.value == (getCurrentPrice() * _quantityToMint)" */ _23)
                /// @src 0:47058:47199  "require(..."
                require_helper_stringliteral_1db8(/** @src 0:47079:47129  "msg.value == (getCurrentPrice() * _quantityToMint)" */ _25)
                /// @src 0:47215:47226  "uint8 i = 0"
                let var_i := /** @src 0:47225:47226  "0" */ 0x00
                /// @src 0:47210:47396  "for (uint8 i = 0; i < _quantityToMint; i++) {..."
                for { }
                /** @src 0:47228:47247  "i < _quantityToMint" */ lt(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ and(/** @src 0:47228:47247  "i < _quantityToMint" */ var_i, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _7), /** @src 0:47228:47247  "i < _quantityToMint" */ _9)
                /// @src 0:47215:47226  "uint8 i = 0"
                {
                    /// @src 0:47249:47252  "i++"
                    var_i := increment_uint8(var_i)
                }
                {
                    /// @src 0:47268:47287  "_tokenIds.increment"
                    fun_increment()
                    /// @src 0:47268:47277  "_tokenIds"
                    let _26 := 0x0c
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _27 := sload(/** @src 0:47268:47277  "_tokenIds" */ _26)
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _28 := cleanup_uint256(_27)
                    /// @src 0:47363:47373  "msg.sender"
                    let _29 := caller()
                    /// @src 0:47375:47384  "newItemId"
                    fun__mint(/** @src 0:47363:47373  "msg.sender" */ _29, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _28)
                }
            }
            function wrapping_add_uint256(x) -> sum
            {
                /// @src 0:1116:1117  "1"
                let _1 := 0x01
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                sum := add(x, /** @src 0:1116:1117  "1" */ _1)
            }
            /// @ast-id 31 @src 0:1011:1134  "function increment(Counter storage counter) internal {..."
            function fun_increment()
            {
                /// @src 0:47268:47277  "_tokenIds"
                let _1 := 0x0c
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:47268:47277  "_tokenIds" */ _1)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _3 := cleanup_uint256(_2)
                /// @src 0:1098:1117  "counter._value += 1"
                let _4 := wrapping_add_uint256(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _3)
                /// @src 0:1098:1117  "counter._value += 1"
                update_storage_value_offsett_uint256_to_uint256_8828(_4)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_8a66f4bb6512ffbfcc3db9b42318eb65f26ac15163eaa9a1e5cfa7bee9d1c7c6(memPtr)
            {
                let _1 := "ERC721: mint to the zero address"
                mstore(memPtr, _1)
            }
            function abi_encode_stringliteral_8a66f4bb6512ffbfcc3db9b42318eb65f26ac15163eaa9a1e5cfa7bee9d1c7c6(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4324(pos)
                store_literal_in_memory_8a66f4bb6512ffbfcc3db9b42318eb65f26ac15163eaa9a1e5cfa7bee9d1c7c6(pos_1)
                let _1 := 32
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_8a66(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_8a66f4bb6512ffbfcc3db9b42318eb65f26ac15163eaa9a1e5cfa7bee9d1c7c6(_3)
            }
            function require_helper_stringliteral_8a66(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_8a66(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function store_literal_in_memory_2a63ce106ef95058ed21fd07c42a10f11dc5c32ac13a4e847923f7759f635d57(memPtr)
            {
                let _1 := "ERC721: token already minted"
                mstore(memPtr, _1)
            }
            function abi_encode_stringliteral_2a63ce106ef95058ed21fd07c42a10f11dc5c32ac13a4e847923f7759f635d57(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4394(pos)
                store_literal_in_memory_2a63ce106ef95058ed21fd07c42a10f11dc5c32ac13a4e847923f7759f635d57(pos_1)
                let _1 := 32
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_2a63(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_2a63ce106ef95058ed21fd07c42a10f11dc5c32ac13a4e847923f7759f635d57(_3)
            }
            function require_helper_stringliteral_2a63(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_2a63(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 1501 @src 0:32241:32613  "function _mint(address to, uint256 tokenId) internal virtual {..."
            function fun__mint(var_to, var_tokenId)
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                let _2 := and(/** @src 0:32320:32336  "to != address(0)" */ var_to, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:32320:32336  "to != address(0)"
                let _3 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _2)
                /// @src 0:32320:32336  "to != address(0)"
                let _4 := iszero(_3)
                /// @src 0:32312:32373  "require(to != address(0), \"ERC721: mint to the zero address\")"
                require_helper_stringliteral_8a66(/** @src 0:32320:32336  "to != address(0)" */ _4)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _5 := mapping_index_access_mapping_uint256_address_of_uint256_4331(/** @src 0:32392:32408  "_exists(tokenId)" */ var_tokenId)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _6 := read_from_storage_split_offset_address(_5)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _7 := and(/** @src 0:30410:30426  "_owners[tokenId]" */ _6, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:30410:30440  "_owners[tokenId] != address(0)"
                let _8 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _7)
                /// @src 0:32391:32408  "!_exists(tokenId)"
                let _9 := cleanup_bool(/** @src 0:30410:30440  "_owners[tokenId] != address(0)" */ _8)
                /// @src 0:32383:32441  "require(!_exists(tokenId), \"ERC721: token already minted\")"
                require_helper_stringliteral_2a63(/** @src 0:32391:32408  "!_exists(tokenId)" */ _9)
                /// @src 0:32489:32496  "tokenId"
                fun_beforeTokenTransfer_4395(var_to, var_tokenId)
                /// @src 0:32508:32521  "_balances[to]"
                let _10 := mapping_index_access_mapping_address_uint256_of_address_4329(var_to)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _11 := sload(/** @src 0:32508:32526  "_balances[to] += 1" */ _10)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _12 := cleanup_uint256(_11)
                /// @src 0:32508:32526  "_balances[to] += 1"
                let _13 := checked_add_uint256_4351(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _12)
                /// @src 0:32508:32526  "_balances[to] += 1"
                update_storage_value_offsett_uint256_to_uint256(_10, _13)
                /// @src 0:32536:32552  "_owners[tokenId]"
                let _14 := mapping_index_access_mapping_uint256_address_of_uint256_4331(var_tokenId)
                /// @src 0:32536:32557  "_owners[tokenId] = to"
                update_storage_value_offsett_address_to_address(/** @src 0:32536:32552  "_owners[tokenId]" */ _14, /** @src 0:32536:32557  "_owners[tokenId] = to" */ var_to)
                /// @src 0:32334:32335  "0"
                let _15 := 0x00
                /// @src 0:32573:32606  "Transfer(address(0), to, tokenId)"
                let _16 := 0xddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef
                /// @src 0:32334:32335  "0"
                let _17 := _15
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _18 := 64
                let _19 := mload(_18)
                /// @src 0:32573:32606  "Transfer(address(0), to, tokenId)"
                log4(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _19, /** @src 0:32334:32335  "0" */ _15, /** @src 0:32573:32606  "Transfer(address(0), to, tokenId)" */ _16, /** @src 0:32334:32335  "0" */ _15, /** @src 0:32573:32606  "Transfer(address(0), to, tokenId)" */ var_to, var_tokenId)
            }
            /// @ast-id 2411 @src 0:47412:47601  "function tokenURI(uint256 tokenId)..."
            function fun_tokenURI_2411(var_tokenId) -> var_mpos
            {
                /// @src 0:47564:47594  "return super.tokenURI(tokenId)"
                var_mpos := /** @src 0:47571:47594  "super.tokenURI(tokenId)" */ fun_tokenURI_2128(var_tokenId)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_8e9ed1638ba7e2d59e03d0957c9339381732ac84d73f65c86c45db1467eafa2a(memPtr)
            {
                let _1 := "ERC721URIStorage: URI query for "
                mstore(memPtr, _1)
                let _2 := "nonexistent token"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_8e9e(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4339(pos)
                store_literal_in_memory_8e9ed1638ba7e2d59e03d0957c9339381732ac84d73f65c86c45db1467eafa2a(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_8e9e(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_8e9e(_3)
            }
            function require_helper_stringliteral_8e9e(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_8e9e(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function abi_encode_string_memory_ptr(value, pos) -> end
            {
                let length := mload(value)
                let _1 := 0x20
                let _2 := add(value, _1)
                copy_memory_to_memory(_2, pos, length)
                end := add(pos, length)
            }
            /// @ast-id 2128 @src 0:43498:44161  "function tokenURI(uint256 tokenId) public view virtual override returns (string memory) {..."
            function fun_tokenURI_2128(var_tokenId) -> var_2073_mpos
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _2 := mapping_index_access_mapping_uint256_address_of_uint256_4331(/** @src 0:43604:43620  "_exists(tokenId)" */ var_tokenId)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _3 := read_from_storage_split_offset_address(_2)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := and(/** @src 0:30410:30426  "_owners[tokenId]" */ _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:30410:30440  "_owners[tokenId] != address(0)"
                let _5 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:30410:30440  "_owners[tokenId] != address(0)"
                let _6 := iszero(_5)
                /// @src 0:43596:43674  "require(_exists(tokenId), \"ERC721URIStorage: URI query for nonexistent token\")"
                require_helper_stringliteral_8e9e(/** @src 0:30410:30440  "_owners[tokenId] != address(0)" */ _6)
                /// @src 0:43711:43730  "_tokenURIs[tokenId]"
                let _7 := mapping_index_access_mapping_uint256_address_of_uint256_4400(var_tokenId)
                /// @src 0:43685:43730  "string memory _tokenURI = _tokenURIs[tokenId]"
                let var_tokenURI_mpos := convert_array_string_storage_to_string(/** @src 0:43711:43730  "_tokenURIs[tokenId]" */ _7)
                /// @src 0:43761:43771  "_baseURI()"
                let expr_2091_mpos := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ copy_array_from_storage_to_memory_string_8829()
                let _8 := mload(/** @src 0:43844:43855  "bytes(base)" */ expr_2091_mpos)
                /// @src 0:43844:43867  "bytes(base).length == 0"
                let _9 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _8)
                /// @src 0:43840:43910  "if (bytes(base).length == 0) {..."
                if /** @src 0:43844:43867  "bytes(base).length == 0" */ _9
                /// @src 0:43840:43910  "if (bytes(base).length == 0) {..."
                {
                    /// @src 0:43883:43899  "return _tokenURI"
                    var_2073_mpos := var_tokenURI_mpos
                    leave
                }
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _10 := mload(/** @src 0:44012:44028  "bytes(_tokenURI)" */ var_tokenURI_mpos)
                /// @src 0:44012:44039  "bytes(_tokenURI).length > 0"
                let _11 := cleanup_uint256(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _10)
                /// @src 0:44012:44039  "bytes(_tokenURI).length > 0"
                let _12 := iszero(_11)
                let _13 := iszero(_12)
                /// @src 0:44008:44114  "if (bytes(_tokenURI).length > 0) {..."
                if /** @src 0:44012:44039  "bytes(_tokenURI).length > 0" */ _13
                /// @src 0:44008:44114  "if (bytes(_tokenURI).length > 0) {..."
                {
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _14 := 64
                    /// @src 0:44069:44102  "abi.encodePacked(base, _tokenURI)"
                    let expr_mpos := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ mload(_14)
                    /// @src 0:44069:44102  "abi.encodePacked(base, _tokenURI)"
                    let _15 := 0x20
                    let _16 := add(expr_mpos, _15)
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _17 := abi_encode_string_memory_ptr(/** @src 0:44069:44102  "abi.encodePacked(base, _tokenURI)" */ expr_2091_mpos, _16)
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _18 := abi_encode_string_memory_ptr(/** @src 0:44069:44102  "abi.encodePacked(base, _tokenURI)" */ var_tokenURI_mpos, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _17)
                    /// @src 0:44069:44102  "abi.encodePacked(base, _tokenURI)"
                    let _19 := sub(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _18, /** @src 0:44069:44102  "abi.encodePacked(base, _tokenURI)" */ expr_mpos)
                    let _20 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ not(31)
                    /// @src 0:44069:44102  "abi.encodePacked(base, _tokenURI)"
                    let _21 := add(_19, _20)
                    mstore(expr_mpos, _21)
                    finalize_allocation(expr_mpos, _19)
                    /// @src 0:44055:44103  "return string(abi.encodePacked(base, _tokenURI))"
                    var_2073_mpos := expr_mpos
                    leave
                }
                /// @src 0:44124:44154  "return super.tokenURI(tokenId)"
                var_2073_mpos := /** @src 0:44131:44154  "super.tokenURI(tokenId)" */ fun_tokenURI(var_tokenId)
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_a2d45c0fba603d40d82d590051761ca952d1ab9d78cca6d0d464d7b6e961a9cb(memPtr)
            {
                let _1 := "ERC721Metadata: URI query for no"
                mstore(memPtr, _1)
                let _2 := "nexistent token"
                let _3 := 32
                let _4 := add(memPtr, _3)
                mstore(_4, _2)
            }
            function abi_encode_stringliteral_a2d45c0fba603d40d82d590051761ca952d1ab9d78cca6d0d464d7b6e961a9cb(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4402(pos)
                store_literal_in_memory_a2d45c0fba603d40d82d590051761ca952d1ab9d78cca6d0d464d7b6e961a9cb(pos_1)
                let _1 := 64
                end := add(pos_1, _1)
            }
            function abi_encode_stringliteral_a2d4(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_a2d45c0fba603d40d82d590051761ca952d1ab9d78cca6d0d464d7b6e961a9cb(_3)
            }
            function require_helper_stringliteral_a2d4(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_stringliteral_a2d4(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @ast-id 1111 @src 0:25852:26181  "function tokenURI(uint256 tokenId) public view virtual override returns (string memory) {..."
            function fun_tokenURI(var_tokenId) -> var_1076_mpos
            {
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _1 := sub(shl(160, 1), 1)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _2 := mapping_index_access_mapping_uint256_address_of_uint256_4331(/** @src 0:25958:25974  "_exists(tokenId)" */ var_tokenId)
                /// @src 0:30410:30426  "_owners[tokenId]"
                let _3 := read_from_storage_split_offset_address(_2)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := and(/** @src 0:30410:30426  "_owners[tokenId]" */ _3, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _1)
                /// @src 0:30410:30440  "_owners[tokenId] != address(0)"
                let _5 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:30410:30440  "_owners[tokenId] != address(0)"
                let _6 := iszero(_5)
                /// @src 0:25950:26026  "require(_exists(tokenId), \"ERC721Metadata: URI query for nonexistent token\")"
                require_helper_stringliteral_a2d4(/** @src 0:30410:30440  "_owners[tokenId] != address(0)" */ _6)
                /// @src 0:26061:26071  "_baseURI()"
                let expr_1088_mpos := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ copy_array_from_storage_to_memory_string_8829()
                let _7 := mload(/** @src 0:26088:26102  "bytes(baseURI)" */ expr_1088_mpos)
                /// @src 0:26088:26113  "bytes(baseURI).length > 0"
                let _8 := iszero(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _7)
                /// @src 0:26088:26113  "bytes(baseURI).length > 0"
                let expr := iszero(_8)
                /// @src 0:26088:26174  "bytes(baseURI).length > 0 ? string(abi.encodePacked(baseURI, tokenId.toString())) : \"\""
                let expr_1108_mpos := /** @src 0:26112:26113  "0" */ 0x00
                /// @src 0:26088:26174  "bytes(baseURI).length > 0 ? string(abi.encodePacked(baseURI, tokenId.toString())) : \"\""
                switch expr
                case 0 {
                    expr_1108_mpos := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ allocate_memory_array_string_4404()
                }
                default /// @src 0:26088:26174  "bytes(baseURI).length > 0 ? string(abi.encodePacked(baseURI, tokenId.toString())) : \"\""
                {
                    /// @src 0:26149:26167  "tokenId.toString()"
                    let expr_1104_mpos := fun_toString(var_tokenId)
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _9 := 64
                    /// @src 0:26123:26168  "abi.encodePacked(baseURI, tokenId.toString())"
                    let expr_1105_mpos := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ mload(_9)
                    /// @src 0:26123:26168  "abi.encodePacked(baseURI, tokenId.toString())"
                    let _10 := 0x20
                    let _11 := add(expr_1105_mpos, _10)
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _12 := abi_encode_string_memory_ptr(/** @src 0:26123:26168  "abi.encodePacked(baseURI, tokenId.toString())" */ expr_1088_mpos, _11)
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _13 := abi_encode_string_memory_ptr(/** @src 0:26123:26168  "abi.encodePacked(baseURI, tokenId.toString())" */ expr_1104_mpos, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _12)
                    /// @src 0:26123:26168  "abi.encodePacked(baseURI, tokenId.toString())"
                    let _14 := sub(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _13, /** @src 0:26123:26168  "abi.encodePacked(baseURI, tokenId.toString())" */ expr_1105_mpos)
                    let _15 := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ not(31)
                    /// @src 0:26123:26168  "abi.encodePacked(baseURI, tokenId.toString())"
                    let _16 := add(_14, _15)
                    mstore(expr_1105_mpos, _16)
                    finalize_allocation(expr_1105_mpos, _14)
                    /// @src 0:26088:26174  "bytes(baseURI).length > 0 ? string(abi.encodePacked(baseURI, tokenId.toString())) : \"\""
                    expr_1108_mpos := expr_1105_mpos
                }
                /// @src 0:26081:26174  "return bytes(baseURI).length > 0 ? string(abi.encodePacked(baseURI, tokenId.toString())) : \"\""
                var_1076_mpos := expr_1108_mpos
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d(memPtr)
            {
                let _1 := "0"
                mstore(memPtr, _1)
            }
            function copy_literal_to_memory_044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d() -> memPtr
            {
                memPtr := allocate_memory_array_string_4405()
                let _1 := 32
                let _2 := add(memPtr, _1)
                store_literal_in_memory_044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d(_2)
            }
            function increment_uint256(value) -> ret
            {
                let _1 := not(0)
                let _2 := eq(value, _1)
                if _2 { panic_error_0x11() }
                let _3 := 1
                ret := add(value, _3)
            }
            function zero_memory_chunk_bytes1(dataStart, dataSizeInBytes)
            {
                let _1 := calldatasize()
                calldatacopy(dataStart, _1, dataSizeInBytes)
            }
            function allocate_and_zero_memory_array_bytes(length) -> memPtr
            {
                memPtr := allocate_memory_array_string(length)
                let _1 := not(31)
                let _2 := array_allocation_size_string(length)
                let _3 := add(_2, _1)
                let _4 := 32
                let _5 := add(memPtr, _4)
                zero_memory_chunk_bytes1(_5, _3)
            }
            function convert_uint8_to_bytes1(value) -> converted
            {
                let _1 := shl(248, 255)
                let _2 := 248
                let _3 := shl(_2, value)
                converted := and(_3, _1)
            }
            function memory_array_index_access_bytes(baseRef, index) -> addr
            {
                let _1 := mload(baseRef)
                let _2 := lt(index, _1)
                let _3 := iszero(_2)
                if _3 { panic_error_0x32() }
                let _4 := 32
                let _5 := add(baseRef, index)
                addr := add(_5, _4)
            }
            /// @ast-id 313 @src 0:6654:7357  "function toString(uint256 value) internal pure returns (string memory) {..."
            function fun_toString(var_value) -> var_240_mpos
            {
                /// @src 0:6927:6937  "value == 0"
                let _1 := iszero(var_value)
                /// @src 0:6923:6974  "if (value == 0) {..."
                if /** @src 0:6927:6937  "value == 0" */ _1
                /// @src 0:6923:6974  "if (value == 0) {..."
                {
                    /// @src 0:6953:6963  "return \"0\""
                    var_240_mpos := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ copy_literal_to_memory_044852b2a670ade5407e78fb2863c51de9fcb96542a07186fe3aeda6bb8a116d()
                    /// @src 0:6953:6963  "return \"0\""
                    leave
                }
                /// @src 0:6983:7003  "uint256 temp = value"
                let var_temp := var_value
                /// @src 0:7013:7027  "uint256 digits"
                let var_digits := /** @src 0:6936:6937  "0" */ 0x00
                /// @src 0:7013:7027  "uint256 digits"
                let var_digits_1 := /** @src 0:6936:6937  "0" */ var_digits
                /// @src 0:7037:7112  "while (temp != 0) {..."
                for { }
                /** @src 0:7044:7053  "temp != 0" */ var_temp
                /// @src 0:7037:7112  "while (temp != 0) {..."
                { }
                {
                    /// @src 0:7069:7077  "digits++"
                    var_digits_1 := increment_uint256(var_digits_1)
                    /// @src 0:7099:7101  "10"
                    let _2 := 0x0a
                    /// @src 0:7091:7101  "temp /= 10"
                    var_temp := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ div(/** @src 0:7091:7101  "temp /= 10" */ var_temp, /** @src 0:7099:7101  "10" */ _2)
                }
                /// @src 0:7121:7160  "bytes memory buffer = new bytes(digits)"
                let var_buffer_mpos := /** @src 0:7143:7160  "new bytes(digits)" */ allocate_and_zero_memory_array_bytes(var_digits_1)
                /// @src 0:7170:7320  "while (value != 0) {..."
                for { }
                /** @src 0:7177:7187  "value != 0" */ var_value
                /// @src 0:7170:7320  "while (value != 0) {..."
                { }
                {
                    /// @src 0:7203:7214  "digits -= 1"
                    var_digits_1 := checked_sub_uint256(var_digits_1)
                    /// @src 0:7099:7101  "10"
                    let _3 := 0x0a
                    /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                    let _4 := mod(/** @src 0:7271:7281  "value % 10" */ var_value, /** @src 0:7099:7101  "10" */ _3)
                    /// @src 0:7258:7282  "48 + uint256(value % 10)"
                    let _5 := checked_add_uint256_4409(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                    /// @src 0:7252:7283  "uint8(48 + uint256(value % 10))"
                    let _6 := extract_from_storage_value_offsett_bool(/** @src 0:7258:7282  "48 + uint256(value % 10)" */ _5)
                    /// @src 0:7245:7284  "bytes1(uint8(48 + uint256(value % 10)))"
                    let _7 := convert_uint8_to_bytes1(/** @src 0:7252:7283  "uint8(48 + uint256(value % 10))" */ _6)
                    /// @src 0:7228:7284  "buffer[digits] = bytes1(uint8(48 + uint256(value % 10)))"
                    let _8 := byte(/** @src 0:6936:6937  "0" */ var_digits, /** @src 0:7245:7284  "bytes1(uint8(48 + uint256(value % 10)))" */ _7)
                    /// @src 0:7228:7284  "buffer[digits] = bytes1(uint8(48 + uint256(value % 10)))"
                    let _9 := memory_array_index_access_bytes(var_buffer_mpos, var_digits_1)
                    mstore8(_9, _8)
                    /// @src 0:7298:7309  "value /= 10"
                    var_value := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ div(/** @src 0:7298:7309  "value /= 10" */ var_value, /** @src 0:7099:7101  "10" */ _3)
                }
                /// @src 0:7329:7350  "return string(buffer)"
                var_240_mpos := var_buffer_mpos
            }
            /// @ast-id 138 @src 0:3357:3474  "modifier onlyOwner() {..."
            function modifier_onlyOwner_2414()
            {
                /// @src 0:3256:3262  "_owner"
                let _1 := 0x0b
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _2 := sload(/** @src 0:3256:3262  "_owner" */ _1)
                /// @src 0:3396:3403  "owner()"
                let expr := /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ cleanup_address(_2)
                /// @src 0:2148:2158  "msg.sender"
                let _3 := caller()
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _4 := sub(shl(160, 1), 1)
                let _5 := and(/** @src 0:3396:3419  "owner() == _msgSender()" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _4)
                /// @src 0:3396:3419  "owner() == _msgSender()"
                let _6 := eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _5, /** @src 0:2148:2158  "msg.sender" */ _3)
                /// @src 0:3388:3456  "require(owner() == _msgSender(), \"Ownable: caller is not the owner\")"
                require_helper_stringliteral_9924(/** @src 0:3396:3419  "owner() == _msgSender()" */ _6)
                /// @src 0:3466:3467  "_"
                fun_withdraw_inner()
            }
            /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
            function store_literal_in_memory_340afe6947da449d67e81dc123ad935e96abad6e36a90276f86359ba7bdeb815(memPtr)
            {
                let _1 := "Balance must be positive"
                mstore(memPtr, _1)
            }
            function abi_encode_stringliteral_340a(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4411(pos)
                store_literal_in_memory_340afe6947da449d67e81dc123ad935e96abad6e36a90276f86359ba7bdeb815(pos_1)
                let _1 := 32
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_340a(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_340a(_3)
            }
            function require_helper_stringliteral_340a(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_340a(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            function store_literal_in_memory_a391ff13fec38280e4a0da2ec9fe53b79b4b2682d21f374332e53e3c8f569243(memPtr)
            {
                let _1 := "Failed to withdraw ether"
                mstore(memPtr, _1)
            }
            function abi_encode_stringliteral_a391(pos) -> end
            {
                let pos_1 := array_storeLengthForEncoding_string_4411(pos)
                store_literal_in_memory_a391ff13fec38280e4a0da2ec9fe53b79b4b2682d21f374332e53e3c8f569243(pos_1)
                let _1 := 32
                end := add(pos_1, _1)
            }
            function abi_encode_tuple_stringliteral_a391(headStart) -> tail
            {
                let _1 := 32
                mstore(headStart, _1)
                let _2 := _1
                let _3 := add(headStart, _1)
                tail := abi_encode_stringliteral_a391(_3)
            }
            function require_helper_stringliteral_a391(condition)
            {
                let _1 := iszero(condition)
                if _1
                {
                    let _2 := 64
                    let memPtr := mload(_2)
                    let _3 := shl(229, 4594637)
                    mstore(memPtr, _3)
                    let _4 := 4
                    let _5 := add(memPtr, _4)
                    let _6 := abi_encode_tuple_stringliteral_a391(_5)
                    let _7 := sub(_6, memPtr)
                    revert(memPtr, _7)
                }
            }
            /// @src 0:47643:47899  "function withdraw() public onlyOwner {..."
            function fun_withdraw_inner()
            {
                /// @src 0:47698:47719  "address(this).balance"
                let _1 := selfbalance()
                /// @src 0:47698:47723  "address(this).balance > 0"
                let _2 := iszero(/** @src 0:47698:47719  "address(this).balance" */ _1)
                /// @src 0:47698:47723  "address(this).balance > 0"
                let _3 := iszero(_2)
                /// @src 0:47690:47752  "require(address(this).balance > 0, \"Balance must be positive\")"
                require_helper_stringliteral_340a(/** @src 0:47698:47723  "address(this).balance > 0" */ _3)
                /// @src 0:47804:47825  "address(this).balance"
                let expr := selfbalance()
                /// @src 0:47722:47723  "0"
                let _4 := 0x00
                let _5 := _4
                let _6 := _4
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _7 := 64
                let _8 := mload(_7)
                /// @src 0:47781:47791  "msg.sender"
                let _9 := caller()
                /// @src 0:47781:47830  "msg.sender.call{value: address(this).balance}(\"\")"
                let _10 := gas()
                let expr_component := call(_10, /** @src 0:47781:47791  "msg.sender" */ _9, /** @src 0:47781:47830  "msg.sender.call{value: address(this).balance}(\"\")" */ expr, /** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _8, /** @src 0:47722:47723  "0" */ _4, _4, _4)
                /// @src 0:47781:47830  "msg.sender.call{value: address(this).balance}(\"\")"
                let _11 := extract_returndata()
                pop(_11)
                /// @src 0:47859:47863  "true"
                let _12 := 0x01
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _13 := iszero(/** @src 0:47848:47863  "success == true" */ expr_component)
                /// @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..."
                let _14 := iszero(_13)
                /// @src 0:47848:47863  "success == true"
                let _15 := eq(/** @src 0:44969:47901  "contract KongsNFT is ERC721, ERC721Enumerable,ERC721URIStorage, Ownable {..." */ _14, /** @src 0:47859:47863  "true" */ _12)
                /// @src 0:47840:47892  "require(success == true, \"Failed to withdraw ether\")"
                require_helper_stringliteral_a391(/** @src 0:47848:47863  "success == true" */ _15)
            }
            /// @ast-id 2449 @src 0:47643:47899  "function withdraw() public onlyOwner {..."
            function fun_withdraw()
            { modifier_onlyOwner_2414() }
        }
        data ".metadata" hex"a36469706673582212204cac0c5a142aa705abffc83e6662fe6b0ca50ae02208a53b167a8f72b758f08c6c6578706572696d656e74616cf564736f6c63430008080041"
    }
}

Optimized IR:

Optimized IR:
/*=====================================================*
 *                       WARNING                       *
 *  Solidity to Yul compilation is still EXPERIMENTAL  *
 *       It can result in LOSS OF FUNDS or worse       *
 *                !USE AT YOUR OWN RISK!               *
 *=====================================================*/

/// @use-src 0:"KongNFT.sol"
object "Strings_431" {
    code {
        {
            /// @src 0:6472:8357  "library Strings {..."
            let _1 := 128
            let _2 := 64
            mstore(_2, _1)
            let _3 := callvalue()
            if _3
            {
                revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
            }
            let _4 := datasize("Strings_431_deployed")
            let _5 := dataoffset("Strings_431_deployed")
            let _6 := _1
            codecopy(_1, _5, _4)
            let _7 := address()
            let _8 := _1
            setimmutable(_1, "library_deploy_address", _7)
            let _9 := _1
            return(_1, _4)
        }
        function revert_error_ca66f745a3ce8ff40e2ccaf1ad45db7774001b90d25810abd9040049be7bf4bb()
        {
            let _1 := 0
            let _2 := _1
            revert(_1, _1)
        }
    }
    /// @use-src 0:"KongNFT.sol"
    object "Strings_431_deployed" {
        code {
            {
                /// @src 0:6472:8357  "library Strings {..."
                let _1 := 128
                let _2 := 64
                mstore(_2, _1)
                revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
            }
            function revert_error_42b3090547df1d2001c96683413b8cf91c1b902ef5e3cb8d9f6f304cf7446f74()
            {
                let _1 := 0
                let _2 := _1
                revert(_1, _1)
            }
        }
        data ".metadata" hex"a36469706673582212208ec76ff66bf64e5850ff9865ecf8bdefe914d97cc5c01dd503915b4bd83745546c6578706572696d656e74616cf564736f6c63430008080041"
    }
}

