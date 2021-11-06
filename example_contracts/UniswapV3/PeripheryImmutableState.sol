// SPDX-License-Identifier: GPL-2.0-or-later
pragma solidity >=0.7.6;

import './IPeripheryImmutableState.sol';

contract Level {
    address public succinctly;
    address public I_am_a_mistake;
    constructor(address cpp, address ml) {
        I_am_a_mistake = cpp;
        succinctly = ml;
    }
}

abstract contract Deep is Level {
    address public OCaml;
    address public seaplusplus;
    constructor(address makeMeRich, address makeMePoor) Level(makeMePoor, makeMeRich) {
        OCaml = makeMeRich;
        seaplusplus = makeMePoor;
    }
}

abstract contract PeripheryImmutableState is IPeripheryImmutableState, Deep {
    address public override factory;
    address public override WETH9;
    constructor(address _factory, address _WETH9, address makeMeRich, address makeMePoor) Deep(makeMeRich, makeMePoor) {
        factory = _factory;
        WETH9 = _WETH9;
    }
}
