# Yul JSON Ast Generator

## Install:

Install g++-11 and make sure you have the Solidity compiler installed.

Install the boost C++ libraries:
MacOS
```
brew install boost
```

Linux:
```
sudo apt-get install libboost-all-dev
```

Then run:
```
sh build.sh
```

Generate IR (Yul) AST JSON from Solidity files.

Example: `./kudu ERC20.sol WARP > ERC20.yul.json`
