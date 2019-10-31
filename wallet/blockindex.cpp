#include "blockindex.h"

#include "bignum.h"
#include "block.h"
#include "boost/shared_ptr.hpp"
#include "util.h"

CBlockIndexSmartPtr CBlockIndex::getNextBlockIndex() const
{
    auto lg = lock_full();
    return getNextBlockIndex_unsafe();
}

CBlockIndexSmartPtr CBlockIndex::getNextBlockIndex_unsafe() const { return contents.pnext; }

void CBlockIndex::setNextBlockIndex(const CBlockIndexSmartPtr& value)
{
    auto lg = lock_full();
    setNextBlockIndex_unsafe(value);
}

void CBlockIndex::setNextBlockIndex_unsafe(const CBlockIndexSmartPtr& value) { contents.pnext = value; }

CBlockIndexSmartPtr CBlockIndex::getPrevBlockIndex() const
{
    auto lg = lock_full();
    return getPrevBlockIndex_unsafe();
}

CBlockIndexSmartPtr CBlockIndex::getPrevBlockIndex_unsafe() const { return contents.pprev; }

void CBlockIndex::setPrevBlockIndex(const CBlockIndexSmartPtr& value)
{
    auto lg = lock_full();
    setPrevBlockIndex_unsafe(value);
}

void CBlockIndex::setPrevBlockIndex_unsafe(const CBlockIndexSmartPtr& value) { contents.pprev = value; }

const uint256* CBlockIndex::getBlockHashPtr() const
{
    auto lg = lock_full();
    return getBlockHashPtr_unsafe();
}

const uint256* CBlockIndex::getBlockHashPtr_unsafe() const { return contents.phashBlock; }

void CBlockIndex::setBlockHashPtr(const uint256* value)
{
    auto lg = lock_full();
    setBlockHashPtr_unsafe(value);
}

void CBlockIndex::setBlockHashPtr_unsafe(const uint256* value) { contents.phashBlock = value; }

uint256 CBlockIndex::getBlockKeyInDB() const
{
    auto lg = lock_full();
    return getBlockKeyInDB_unsafe();
}

uint256 CBlockIndex::getBlockKeyInDB_unsafe() const { return contents.blockKeyInDB; }

void CBlockIndex::setBlockKeyInDB(const uint256& value)
{
    auto lg = lock_full();
    setBlockKeyInDB_unsafe(value);
}

void CBlockIndex::setBlockKeyInDB_unsafe(const uint256& value) { contents.blockKeyInDB = value; }

uint256 CBlockIndex::getChainTrust() const
{
    auto lg = lock_full();
    return getChainTrust_unsafe();
}

uint256 CBlockIndex::getChainTrust_unsafe() const { return contents.nChainTrust; }

void CBlockIndex::setChainTrust(const uint256& value)
{
    auto lg = lock_full();
    setChainTrust_unsafe(value);
}

void CBlockIndex::setChainTrust_unsafe(const uint256& value) { contents.nChainTrust = value; }

int CBlockIndex::getHeight() const
{
    auto lg = lock_full();
    return getHeight_unsafe();
}

int CBlockIndex::getHeight_unsafe() const { return contents.nHeight; }

void CBlockIndex::setHeight(int value)
{
    auto lg = lock_full();
    setHeight_unsafe(value);
}

void CBlockIndex::setHeight_unsafe(int value) { contents.nHeight = value; }

int64_t CBlockIndex::getMintCount() const
{
    auto lg = lock_full();
    return getMintCount_unsafe();
}

int64_t CBlockIndex::getMintCount_unsafe() const { return contents.nMint; }

void CBlockIndex::setMintCount(const int64_t& value)
{
    auto lg = lock_full();
    setMintCount_unsafe(value);
}

void CBlockIndex::setMintCount_unsafe(const int64_t& value) { contents.nMint = value; }

int64_t CBlockIndex::getMoneySupply() const
{
    auto lg = lock_full();
    return getMoneySupply_unsafe();
}

int64_t CBlockIndex::getMoneySupply_unsafe() const { return contents.nMoneySupply; }

void CBlockIndex::setMoneySupply(const int64_t& value)
{
    auto lg = lock_full();
    setMoneySupply_unsafe(value);
}

void CBlockIndex::setMoneySupply_unsafe(const int64_t& value) { contents.nMoneySupply = value; }

unsigned int CBlockIndex::getFlags() const
{
    auto lg = lock_full();
    return getFlags_unsafe();
}

unsigned int CBlockIndex::getFlags_unsafe() const { return contents.nFlags; }

void CBlockIndex::setFlags(unsigned int value)
{
    auto lg = lock_full();
    setFlags_unsafe(value);
}

void CBlockIndex::setFlags_unsafe(unsigned int value) { contents.nFlags = value; }

uint64_t CBlockIndex::getStakeModifier() const
{
    auto lg = lock_full();
    return getStakeModifier_unsafe();
}

uint64_t CBlockIndex::getStakeModifier_unsafe() const { return contents.nStakeModifier; }

void CBlockIndex::setStakeModifier(const uint64_t& value)
{
    auto lg = lock_full();
    setStakeModifier_unsafe(value);
}

void CBlockIndex::setStakeModifier_unsafe(const uint64_t& value) { contents.nStakeModifier = value; }

unsigned int CBlockIndex::getStakeModifierChecksum() const
{
    auto lg = lock_full();
    return getStakeModifierChecksum_unsafe();
}

unsigned int CBlockIndex::getStakeModifierChecksum_unsafe() const
{
    return contents.nStakeModifierChecksum;
}

void CBlockIndex::setStakeModifierChecksum(unsigned int value)
{
    auto lg = lock_full();
    setStakeModifierChecksum_unsafe(value);
}

void CBlockIndex::setStakeModifierChecksum_unsafe(unsigned int value)
{
    contents.nStakeModifierChecksum = value;
}

COutPoint CBlockIndex::getPOSPrevoutStake() const
{
    auto lg = lock_full();
    return getPOSPrevoutStake_unsafe();
}

COutPoint CBlockIndex::getPOSPrevoutStake_unsafe() const { return contents.prevoutStake; }

void CBlockIndex::setPOSPrevoutStake(const COutPoint& value)
{
    auto lg = lock_full();
    setPOSPrevoutStake_unsafe(value);
}

void CBlockIndex::setPOSPrevoutStake_unsafe(const COutPoint& value) { contents.prevoutStake = value; }

unsigned int CBlockIndex::getPOSStakeTime() const
{
    auto lg = lock_full();
    return getPOSStakeTime_unsafe();
}

unsigned int CBlockIndex::getPOSStakeTime_unsafe() const { return contents.nStakeTime; }

void CBlockIndex::setPOSStakeTime(unsigned int value)
{
    auto lg = lock_full();
    setPOSStakeTime_unsafe(value);
}

void CBlockIndex::setPOSStakeTime_unsafe(unsigned int value) { contents.nStakeTime = value; }

uint256 CBlockIndex::getHashProof() const
{
    auto lg = lock_full();
    return getHashProof_unsafe();
}

uint256 CBlockIndex::getHashProof_unsafe() const { return contents.hashProof; }

void CBlockIndex::setHashProof(const uint256& value)
{
    auto lg = lock_full();
    setHashProof_unsafe(value);
}

void CBlockIndex::setHashProof_unsafe(const uint256& value) { contents.hashProof = value; }

int CBlockIndex::getHeader_NVersion() const
{
    auto lg = lock_full();
    return getHeader_NVersion_unsafe();
}

int CBlockIndex::getHeader_NVersion_unsafe() const { return contents.nVersion; }

void CBlockIndex::setHeader_NVersion(int value)
{
    auto lg = lock_full();
    setHeader_NVersion_unsafe(value);
}

void CBlockIndex::setHeader_NVersion_unsafe(int value) { contents.nVersion = value; }

uint256 CBlockIndex::getHeader_HashMerkleRoot() const
{
    auto lg = lock_full();
    return getHeader_HashMerkleRoot_unsafe();
}

uint256 CBlockIndex::getHeader_HashMerkleRoot_unsafe() const { return contents.hashMerkleRoot; }

void CBlockIndex::setHeader_HashMerkleRoot(const uint256& value)
{
    auto lg = lock_full();
    setHeader_HashMerkleRoot_unsafe(value);
}

void CBlockIndex::setHeader_HashMerkleRoot_unsafe(const uint256& value)
{

    contents.hashMerkleRoot = value;
}

unsigned int CBlockIndex::getHeader_NTime() const
{
    auto lg = lock_full();
    return getHeader_NTime_unsafe();
}

unsigned int CBlockIndex::getHeader_NTime_unsafe() const { return contents.nTime; }

void CBlockIndex::setHeader_NTime(unsigned int value)
{
    auto lg = lock_full();
    setHeader_NTime_unsafe(value);
}

void CBlockIndex::setHeader_NTime_unsafe(unsigned int value) { contents.nTime = value; }

unsigned int CBlockIndex::getHeader_NBits() const
{
    auto lg = lock_full();
    return getHeader_NBits_unsafe();
}

unsigned int CBlockIndex::getHeader_NBits_unsafe() const { return contents.nBits; }

void CBlockIndex::setHeader_NBits(unsigned int value)
{
    auto lg = lock_full();
    setHeader_NBits_unsafe(value);
}

void CBlockIndex::setHeader_NBits_unsafe(unsigned int value) { contents.nBits = value; }

unsigned int CBlockIndex::getHeader_Nonce() const
{
    auto lg = lock_full();
    return getHeader_Nonce_unsafe();
}

unsigned int CBlockIndex::getHeader_Nonce_unsafe() const { return contents.nNonce; }

void CBlockIndex::setHeader_Nonce(unsigned int value)
{
    auto lg = lock_full();
    setHeader_Nonce_unsafe(value);
}

void CBlockIndex::setHeader_Nonce_unsafe(unsigned int value) { contents.nNonce = value; }

CBlockIndex::CBlockIndex()
{
    auto lg                         = lock_full();
    contents.phashBlock             = NULL;
    contents.pprev                  = NULL;
    contents.pnext                  = NULL;
    contents.blockKeyInDB           = 0;
    contents.nHeight                = 0;
    contents.nChainTrust            = 0;
    contents.nMint                  = 0;
    contents.nMoneySupply           = 0;
    contents.nFlags                 = 0;
    contents.nStakeModifier         = 0;
    contents.nStakeModifierChecksum = 0;
    contents.hashProof              = 0;
    contents.prevoutStake.SetNull();
    contents.nStakeTime = 0;

    contents.nVersion       = 0;
    contents.hashMerkleRoot = 0;
    contents.nTime          = 0;
    contents.nBits          = 0;
    contents.nNonce         = 0;
}

CBlockIndex::CBlockIndex(const CBlockIndex& other)
{
    if (&other == this) {
        return;
    }
    auto lg1 = lock_full();
    auto lg2 = other.lock_full();

    contents = other.contents;
}

CBlockIndex::CBlockIndex(uint256 nBlockPosIn, CBlock& block)
{
    auto lg                         = lock_full();
    contents.phashBlock             = NULL;
    contents.pprev                  = NULL;
    contents.pnext                  = NULL;
    contents.blockKeyInDB           = nBlockPosIn;
    contents.nHeight                = 0;
    contents.nChainTrust            = 0;
    contents.nMint                  = 0;
    contents.nMoneySupply           = 0;
    contents.nFlags                 = 0;
    contents.nStakeModifier         = 0;
    contents.nStakeModifierChecksum = 0;
    contents.hashProof              = 0;
    if (block.IsProofOfStake()) {
        SetProofOfStake();
        contents.prevoutStake = block.vtx[1].vin[0].prevout;
        contents.nStakeTime   = block.vtx[1].nTime;
    } else {
        contents.prevoutStake.SetNull();
        contents.nStakeTime = 0;
    }

    contents.nVersion       = block.nVersion;
    contents.hashMerkleRoot = block.hashMerkleRoot;
    contents.nTime          = block.nTime;
    contents.nBits          = block.nBits;
    contents.nNonce         = block.nNonce;
}

CBlock CBlockIndex::GetBlockHeader() const
{
    auto lg = lock_full();
    return GetBlockHeader_unsafe();
}

CBlock CBlockIndex::GetBlockHeader_unsafe() const
{
    CBlock block;
    {
        block.nVersion = contents.nVersion;
        if (contents.pprev) {
            block.hashPrevBlock = contents.pprev->GetBlockHash_unsafe();
        }
    }
    block.hashMerkleRoot = contents.hashMerkleRoot;
    block.nTime          = contents.nTime;
    block.nBits          = contents.nBits;
    block.nNonce         = contents.nNonce;
    return block;
}

uint256 CBlockIndex::GetBlockHash() const
{
    auto lg = lock_full();
    return GetBlockHash_unsafe();
}

uint256 CBlockIndex::GetBlockHash_unsafe() const { return *contents.phashBlock; }

int64_t CBlockIndex::GetBlockTime() const
{
    auto lg = lock_full();
    return GetBlockTime_unsafe();
}

int64_t CBlockIndex::GetBlockTime_unsafe() const { return (int64_t)contents.nTime; }

std::string CBlockIndex::ToString() const
{
    auto lg = lock_full();
    return strprintf("CBlockIndex(nprev=%p, pnext=%p, nBlockPos=%s nHeight=%d, "
                     "nMint=%s, nMoneySupply=%s, nFlags=(%s)(%d)(%s), nStakeModifier=%016" PRIx64
                     ", nStakeModifierChecksum=%08x, hashProof=%s, prevoutStake=(%s), nStakeTime=%d "
                     "merkle=%s, hashBlock=%s)",
                     contents.pprev.get(), contents.pnext.get(),
                     contents.blockKeyInDB.ToString().c_str(), contents.nHeight,
                     FormatMoney(contents.nMint).c_str(), FormatMoney(contents.nMoneySupply).c_str(),
                     GeneratedStakeModifier() ? "MOD" : "-", GetStakeEntropyBit(),
                     IsProofOfStake() ? "PoS" : "PoW", contents.nStakeModifier,
                     contents.nStakeModifierChecksum, contents.hashProof.ToString().c_str(),
                     contents.prevoutStake.ToString().c_str(), contents.nStakeTime,
                     contents.hashMerkleRoot.ToString().c_str(), GetBlockHash().ToString().c_str());
}

[[nodiscard]] std::tuple<CBlockIndex::LGP, CBlockIndex::LGP, CBlockIndex::LGP>
CBlockIndex::lock_full() const
{
    CBlockIndex::LGP lg1;
    CBlockIndex::LGP lg3;
    // always lock in order to avoid deadlocks
    if (contents.pprev)
        lg1 = contents.pprev->lock_only_this();
    CBlockIndex::LGP lg2 = this->lock_only_this();
    if (contents.pnext)
        lg3 = contents.pnext->lock_only_this();
    return std::make_tuple(std::move(lg1), std::move(lg2), std::move(lg3));
    //    return std::make_tuple(nullptr, nullptr, nullptr);
}

[[nodiscard]] CBlockIndex::LGP CBlockIndex::lock_only_this() const
{
    return std::unique_ptr<LG>(new LG(mtx));
    //    return nullptr;
}

uint256 CBlockIndex::GetBlockTrust() const
{
    auto lg = lock_full();

    CBigNum bnTarget;
    bnTarget.SetCompact(contents.nBits);

    if (bnTarget <= 0)
        return 0;

    return ((CBigNum(1) << 256) / (bnTarget + 1)).getuint256();
}

bool CBlockIndex::IsInMainChain() const
{
    auto lg = lock_full();
    return IsInMainChain_unsafe();
}

bool CBlockIndex::IsInMainChain_unsafe() const
{
    return (contents.pnext || this == boost::atomic_load(&pindexBest).get());
}

int64_t CBlockIndex::GetPastTimeLimit() const
{
    auto lg = lock_full();
    return GetPastTimeLimit_unsafe();
}

int64_t CBlockIndex::GetPastTimeLimit_unsafe() const { return GetMedianTimePast(); }

int64_t CBlockIndex::GetMedianTimePast() const
{
    auto lg = lock_full();
    return GetMedianTimePast_unsafe();
}

int64_t CBlockIndex::GetMedianTimePast_unsafe() const
{
    int64_t  pmedian[nMedianTimeSpan];
    int64_t* pbegin = &pmedian[nMedianTimeSpan];
    int64_t* pend   = &pmedian[nMedianTimeSpan];

    const CBlockIndex* pindex = this;
    for (int i = 0; i < nMedianTimeSpan && pindex;
         i++, pindex = boost::atomic_load(&pindex->contents.pprev).get())
        *(--pbegin) = pindex->GetBlockTime_unsafe();

    std::sort(pbegin, pend);
    return pbegin[(pend - pbegin) / 2];
}

bool CBlockIndex::IsSuperMajority(int minVersion, const CBlockIndex* pstart, unsigned int nRequired,
                                  unsigned int nToCheck)
{
    unsigned int nFound = 0;
    for (unsigned int i = 0; i < nToCheck && nFound < nRequired && pstart != NULL; i++) {
        auto lg = pstart->lock_full();
        if (pstart->contents.nVersion >= minVersion) {
            ++nFound;
        }
        pstart = boost::atomic_load(&pstart->contents.pprev).get();
    }
    return (nFound >= nRequired);
}
