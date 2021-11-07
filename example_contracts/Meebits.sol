/**
 *Submitted for verification at Etherscan.io on 2021-05-05
*/

pragma solidity ^0.8.1;

/**
 *  __  __           _     _ _
 * |  \/  |         | |   (_) |
 * | \  / | ___  ___| |__  _| |_ ___
 * | |\/| |/ _ \/ _ \ '_ \| | __/ __|
 * | |  | |  __/  __/ |_) | | |_\__ \
 * |_|  |_|\___|\___|_.__/|_|\__|___/
 *
 * An NFT project from Larva Labs.
 *
 */
interface IERC165 {
    function supportsInterface(bytes4 interfaceId) external view returns (bool);
}

interface IERC721 is IERC165 {
    event Transfer(address indexed from, address indexed to, uint256 indexed tokenId);
    event Approval(address indexed owner, address indexed approved, uint256 indexed tokenId);
    event ApprovalForAll(address indexed owner, address indexed operator, bool approved);
    function balanceOf(address owner) external view returns (uint256 balance);
    function ownerOf(uint256 tokenId) external view returns (address owner);
    function safeTransferFrom(address from, address to, uint256 tokenId) external;
    function transferFrom(address from, address to, uint256 tokenId) external;
    function approve(address to, uint256 tokenId) external;
    function getApproved(uint256 tokenId) external view returns (address operator);
    function setApprovalForAll(address operator, bool _approved) external;
    function isApprovedForAll(address owner, address operator) external view returns (bool);
}

/**
 * Minimal interface to Cryptopunks for verifying ownership during Community Grant.
 */
interface Cryptopunks {
    function punkIndexToAddress(uint index) external view returns(address);
}

interface ERC721TokenReceiver
{
    function onERC721Received(address _operator, address _from, uint256 _tokenId, bytes calldata _data) external returns(bytes4);
}

library SafeMath {

    /**
    * @dev Multiplies two numbers, throws on overflow.
    */
    function mul(uint256 a, uint256 b) internal pure returns (uint256 c) {
        if (a == 0) {
            return 0;
        }
        c = a * b;
        require(c / a == b);
        return c;
    }

    /**
    * @dev Integer division of two numbers, truncating the quotient.
    */
    function div(uint256 a, uint256 b) internal pure returns (uint256) {
        // assert(b > 0); // Solidity automatically throws when dividing by 0
        // uint256 c = a / b;
        // assert(a == b * c + a % b); // There is no case in which this doesn't hold
        return a / b;
    }

    /**
    * @dev Subtracts two numbers, throws on overflow (i.e. if subtrahend is greater than minuend).
    */
    function sub(uint256 a, uint256 b) internal pure returns (uint256) {
        require(b <= a);
        return a - b;
    }

    /**
    * @dev Adds two numbers, throws on overflow.
    */
    function add(uint256 a, uint256 b) internal pure returns (uint256 c) {
        c = a + b;
        require(c >= a);
        return c;
    }
}

contract Meebits is IERC721 {

    using SafeMath for uint256;

    uint public constant TOKEN_LIMIT = 20000;
    uint public constant SALE_LIMIT = 9000;

    mapping(bytes4 => bool) internal supportedInterfaces;

    mapping (uint256 => address) internal idToOwner;

    mapping (uint256 => uint256) public creatorNftMints;

    mapping (uint256 => address) internal idToApproval;

    mapping (address => mapping (address => bool)) internal ownerToOperators;

    mapping(address => uint256[]) internal ownerToIds;

    mapping(uint256 => uint256) internal idToOwnerIndex;

    uint internal numTokens = 0;
    uint internal numSales = 0;

    // Cryptopunks contract
    address internal punks;

    // Autoglyphs contract
    address internal glyphs;

    address payable internal deployer;
    address payable internal beneficiary;
    bool public communityGrant = true;
    bool public publicSale = false;
    uint private price;
    uint public saleStartTime;
    uint public saleDuration;

    //// Random index assignment
    uint internal nonce = 0;
    uint[TOKEN_LIMIT] internal indices;

    //// Market
    bool public marketPaused;
    bool public contractSealed;
    mapping (address => uint256) public ethBalance;
    mapping (bytes32 => bool) public cancelledOffers;

    modifier onlyDeployer() {
        require(msg.sender == deployer);
        _;
    }

    bool private reentrancyLock = false;

    /* Prevent a contract function from being reentrant-called. */
    modifier reentrancyGuard {
        if (reentrancyLock) {
            revert();
        }
        reentrancyLock = true;
        _;
        reentrancyLock = false;
    }

    modifier canOperate(uint256 _tokenId) {
        address tokenOwner = idToOwner[_tokenId];
        require(tokenOwner == msg.sender || ownerToOperators[tokenOwner][msg.sender]);
        _;
    }

    modifier canTransfer(uint256 _tokenId) {
        address tokenOwner = idToOwner[_tokenId];
        require(
            tokenOwner == msg.sender
            || idToApproval[_tokenId] == msg.sender
            || ownerToOperators[tokenOwner][msg.sender] 
        );
        _;
    }

    modifier validNFToken(uint256 _tokenId) {
        require(idToOwner[_tokenId] != address(0) );
        _;
    }

    constructor(address _punks, address _glyphs, address payable _beneficiary) {
        supportedInterfaces[0x01ffc9a7] = true; // ERC165
        supportedInterfaces[0x80ac58cd] = true; // ERC721
        supportedInterfaces[0x780e9d63] = true; // ERC721 Enumerable
        supportedInterfaces[0x5b5e139f] = true; // ERC721 Metadata
        deployer = payable(msg.sender);
        punks = _punks;
        glyphs = _glyphs;
        beneficiary = _beneficiary;
    }

    function startSale(uint _price, uint _saleDuration) external onlyDeployer {
        require(!publicSale);
        price = _price;
        saleDuration = _saleDuration;
        saleStartTime = block.timestamp;
        publicSale = true;
    }

    function endCommunityGrant() external onlyDeployer {
        require(communityGrant);
        communityGrant = false;
    }

    function pauseMarket(bool _paused) external onlyDeployer {
        require(!contractSealed );
        marketPaused = _paused;
    }

    function sealContract() external onlyDeployer {
        contractSealed = true;
    }

    //////////////////////////
    //// ERC 721 and 165  ////
    //////////////////////////

    function isContract(address _addr) internal view returns (bool addressCheck) {
        uint256 size;
        assembly { size := extcodesize(_addr) } // solhint-disable-line
        addressCheck = size > 0;
    }

    function supportsInterface(bytes4 _interfaceID) external view override returns (bool) {
        return supportedInterfaces[_interfaceID];
    }

    function safeTransferFrom(address _from, address _to, uint256 _tokenId) external override {
        _safeTransferFrom(_from, _to, _tokenId );
    }

    function transferFrom(address _from, address _to, uint256 _tokenId) external override canTransfer(_tokenId) validNFToken(_tokenId) {
        address tokenOwner = idToOwner[_tokenId];
        require(tokenOwner == _from );
        require(_to != address(0) );
        _transfer(_to, _tokenId);
    }

    function approve(address _approved, uint256 _tokenId) external override canOperate(_tokenId) validNFToken(_tokenId) {
        address tokenOwner = idToOwner[_tokenId];
        require(_approved != tokenOwner);
        idToApproval[_tokenId] = _approved;
    }

    function setApprovalForAll(address _operator, bool _approved) external override {
        ownerToOperators[msg.sender][_operator] = _approved;
    }

    function balanceOf(address _owner) external view override returns (uint256) {
        require(_owner != address(0));
        return _getOwnerNFTCount(_owner);
    }

    function ownerOf(uint256 _tokenId) external view override returns (address _owner) {
        require(idToOwner[_tokenId] != address(0));
        _owner = idToOwner[_tokenId];
    }

    function getApproved(uint256 _tokenId) external view override validNFToken(_tokenId) returns (address) {
        return idToApproval[_tokenId];
    }

    function isApprovedForAll(address _owner, address _operator) external override view returns (bool) {
        return ownerToOperators[_owner][_operator];
    }

    function _transfer(address _to, uint256 _tokenId) internal {
        address from = idToOwner[_tokenId];
        _clearApproval(_tokenId);

        _removeNFToken(from, _tokenId);
        _addNFToken(_to, _tokenId);

    }

    function randomIndex() internal returns (uint) {
        uint totalSize = TOKEN_LIMIT - numTokens;
        uint index = uint(keccak256(abi.encodePacked(nonce, msg.sender, block.difficulty, block.timestamp))) % totalSize;
        uint value = 0;
        if (indices[index] != 0) {
            value = indices[index];
        } else {
            value = index;
        }

        // Move last value to selected position
        if (indices[totalSize - 1] == 0) {
            // Array position not initialized, so use position
            indices[index] = totalSize - 1;
        } else {
            // Array position holds a value so use that
            indices[index] = indices[totalSize - 1];
        }
        nonce++;
        // Don't allow a zero index, start counting at 1
        return value.add(1);
    }

    // Calculate the mint price
    function getPrice() public view returns (uint) {
        require(publicSale );
        uint elapsed = block.timestamp.sub(saleStartTime);
        if (elapsed >= saleDuration) {
            return 0;
        } else {
            return saleDuration.sub(elapsed).mul(price).div(saleDuration);
        }
    }

    // The deployer can mint in bulk without paying
    function devMint(uint quantity, address recipient) external onlyDeployer {
        for (uint i = 0; i < quantity; i++) {
            _mint(recipient, 0);
        }
    }

    function mintsRemaining() external view returns (uint) {
        return SALE_LIMIT.sub(numSales);
    }

    /**
     * Community grant minting.
     */
    function mintWithPunkOrGlyph(uint _createVia) external reentrancyGuard returns (uint) {
        require(communityGrant);
        require(!marketPaused);
        require(_createVia > 0 && _createVia <= 10512 );
        require(creatorNftMints[_createVia] == 0 );
        if (_createVia > 10000) {
            // It's a glyph
            // Compute the glyph ID
            uint glyphId = _createVia.sub(10000);
            // Make sure the sender owns the glyph
            require(IERC721(glyphs).ownerOf(glyphId) == msg.sender );
        } else {
            // It's a punk
            // Compute the punk ID
            uint punkId = _createVia.sub(1);
            // Make sure the sender owns the punk
            require(Cryptopunks(punks).punkIndexToAddress(punkId) == msg.sender );
        }
        creatorNftMints[_createVia]++;
        return _mint(msg.sender, _createVia);
    }

    /**
     * Public sale minting.
     */
    function mint() external payable reentrancyGuard returns (uint) {
        require(publicSale );
        require(!marketPaused);
        require(numSales < SALE_LIMIT );
        uint salePrice = getPrice();
        require(msg.value >= salePrice );
        if (msg.value > salePrice) {
            payable(msg.sender).transfer(msg.value.sub(salePrice));
        }
        beneficiary.transfer(salePrice);
        numSales++;
        return _mint(msg.sender, 0);
    }

    function _mint(address _to, uint createdVia) internal returns (uint) {
        require(_to != address(0) );
        require(numTokens < TOKEN_LIMIT );
        uint id = randomIndex();

        numTokens = numTokens + 1;
        _addNFToken(_to, id);

        return id;
    }

    function _addNFToken(address _to, uint256 _tokenId) internal {
        require(idToOwner[_tokenId] == address(0) );
        idToOwner[_tokenId] = _to;

        ownerToIds[_to].push(_tokenId);
        idToOwnerIndex[_tokenId] = ownerToIds[_to].length.sub(1);
    }

    function _removeNFToken(address _from, uint256 _tokenId) internal {
        require(idToOwner[_tokenId] == _from );
        delete idToOwner[_tokenId];

        uint256 tokenToRemoveIndex = idToOwnerIndex[_tokenId];
        uint256 lastTokenIndex = ownerToIds[_from].length.sub(1);

        if (lastTokenIndex != tokenToRemoveIndex) {
            uint256 lastToken = ownerToIds[_from][lastTokenIndex];
            ownerToIds[_from][tokenToRemoveIndex] = lastToken;
            idToOwnerIndex[lastToken] = tokenToRemoveIndex;
        }

        ownerToIds[_from].pop();
    }

    function _getOwnerNFTCount(address _owner) internal view returns (uint256) {
        return ownerToIds[_owner].length;
    }

    function _safeTransferFrom(address _from,  address _to,  uint256 _tokenId) private canTransfer(_tokenId) validNFToken(_tokenId) {
        address tokenOwner = idToOwner[_tokenId];
        require(tokenOwner == _from );
        require(_to != address(0));

        _transfer(_to, _tokenId);

        if (isContract(_to)) {
            bytes4 retval = ERC721TokenReceiver(_to).onERC721Received(msg.sender, _from, _tokenId, "");
        }
    }

    function _clearApproval(uint256 _tokenId) private {
        if (idToApproval[_tokenId] != address(0)) {
            delete idToApproval[_tokenId];
        }
    }

    //// Enumerable

    function totalSupply() public view returns (uint256) {
        return numTokens;
    }

    function tokenByIndex(uint256 index) public pure returns (uint256) {
        require(index >= 0 && index < TOKEN_LIMIT);
        return index + 1;
    }

    function tokenOfOwnerByIndex(address _owner, uint256 _index) external view returns (uint256) {
        require(_index < ownerToIds[_owner].length);
        return ownerToIds[_owner][_index];
    }

    //// MARKET

    struct Offer {
        address maker;
        address taker;
        uint256 makerWei;
        uint256[] makerIds;
        uint256 takerWei;
        uint256[] takerIds;
        uint256 expiry;
        uint256 salt;
    }

    function hashOffer(Offer memory offer) private pure returns (bytes32){
        return keccak256(abi.encode(
                    offer.maker,
                    offer.taker,
                    offer.makerWei,
                    keccak256(abi.encodePacked(offer.makerIds)),
                    offer.takerWei,
                    keccak256(abi.encodePacked(offer.takerIds)),
                    offer.expiry,
                    offer.salt
                ));
    }

    function hashToSign(address maker, address taker, uint256 makerWei, uint256[] memory makerIds, uint256 takerWei, uint256[] memory takerIds, uint256 expiry, uint256 salt) public pure returns (bytes32) {
        Offer memory offer = Offer(maker, taker, makerWei, makerIds, takerWei, takerIds, expiry, salt);
        return hashOffer(offer);
    }

    function hashToVerify(Offer memory offer) private pure returns (bytes32) {
        return keccak256(abi.encodePacked(hashOffer(offer)));
    }

    function verify(address signer, bytes32 hash, bytes memory signature) internal pure returns (bool) {
        require(signer != address(0));
        require(signature.length == 65);

        bytes32 r;
        bytes32 s;
        uint8 v;

        assembly {
            r := mload(add(signature, 32))
            s := mload(add(signature, 64))
            v := byte(0, mload(add(signature, 96)))
        }

        if (v < 27) {
            v += 27;
        }

        require(v == 27 || v == 28);

        return signer == ecrecover(hash, v, r, s);
    }

    function tradeValid(address maker, address taker, uint256 makerWei, uint256[] memory makerIds, uint256 takerWei, uint256[] memory takerIds, uint256 expiry, uint256 salt, bytes memory signature) view public returns (bool) {
        Offer memory offer = Offer(maker, taker, makerWei, makerIds, takerWei, takerIds, expiry, salt);
        // Check for cancellation
        bytes32 hash = hashOffer(offer);
        require(cancelledOffers[hash] == false );
        // Verify signature
        bytes32 verifyHash = hashToVerify(offer);
        require(verify(offer.maker, verifyHash, signature) );
        // Check for expiry
        require(block.timestamp < offer.expiry );
        // Only one side should ever have to pay, not both
        require(makerWei == 0 || takerWei == 0 );
        // At least one side should offer tokens
        require(makerIds.length > 0 || takerIds.length > 0 );
        // Make sure the maker has funded the trade
        require(ethBalance[offer.maker] >= offer.makerWei );
        // Ensure the maker owns the maker tokens
        for (uint i = 0; i < offer.makerIds.length; i++) {
            require(idToOwner[offer.makerIds[i]] == offer.maker );
        }
        // If the taker can be anybody, then there can be no taker tokens
        if (offer.taker == address(0)) {
            // If taker not specified, then can't specify IDs
            require(offer.takerIds.length == 0 );
        } else {
            // Ensure the taker owns the taker tokens
            for (uint i = 0; i < offer.takerIds.length; i++) {
                require(idToOwner[offer.takerIds[i]] == offer.taker );
            }
        }
        return true;
    }

    function cancelOffer(address maker, address taker, uint256 makerWei, uint256[] memory makerIds, uint256 takerWei, uint256[] memory takerIds, uint256 expiry, uint256 salt) external {
        require(maker == msg.sender );
        Offer memory offer = Offer(maker, taker, makerWei, makerIds, takerWei, takerIds, expiry, salt);
        bytes32 hash = hashOffer(offer);
        cancelledOffers[hash] = true;
    }

    function acceptTrade(address maker, address taker, uint256 makerWei, uint256[] memory makerIds, uint256 takerWei, uint256[] memory takerIds, uint256 expiry, uint256 salt, bytes memory signature) external payable reentrancyGuard {
        require(!marketPaused );
        require(msg.sender != maker );
        Offer memory offer = Offer(maker, taker, makerWei, makerIds, takerWei, takerIds, expiry, salt);
        if (msg.value > 0) {
            ethBalance[msg.sender] = ethBalance[msg.sender].add(msg.value);
        }
        require(offer.taker == address(0) || offer.taker == msg.sender );
        require(tradeValid(maker, taker, makerWei, makerIds, takerWei, takerIds, expiry, salt, signature) );
        require(ethBalance[msg.sender] >= offer.takerWei );
        // Transfer ETH
        ethBalance[offer.maker] = ethBalance[offer.maker].sub(offer.makerWei);
        ethBalance[msg.sender] = ethBalance[msg.sender].add(offer.makerWei);
        ethBalance[msg.sender] = ethBalance[msg.sender].sub(offer.takerWei);
        ethBalance[offer.maker] = ethBalance[offer.maker].add(offer.takerWei);
        // Transfer maker ids to taker (msg.sender)
        for (uint i = 0; i < makerIds.length; i++) {
            _transfer(msg.sender, makerIds[i]);
        }
        // Transfer taker ids to maker
        for (uint i = 0; i < takerIds.length; i++) {
            _transfer(maker, takerIds[i]);
        }
        // Prevent a replay attack on this offer
        bytes32 hash = hashOffer(offer);
        cancelledOffers[hash] = true;
    }

    function withdraw(uint amount) external reentrancyGuard {
        require(amount <= ethBalance[msg.sender]);
        ethBalance[msg.sender] = ethBalance[msg.sender].sub(amount);
        (bool success, ) = msg.sender.call{value:amount}("");
        require(success);
    }

    function deposit() external payable {
        ethBalance[msg.sender] = ethBalance[msg.sender].add(msg.value);
    }

}