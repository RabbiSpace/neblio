#ifndef BLOCKINDEX_H
#define BLOCKINDEX_H

#include "globals.h"
#include "outpoint.h"
#include "uint256.h"

class CBlock;

struct CBlockIndexContents
{
    const uint256*      phashBlock;
    CBlockIndexSmartPtr pprev;
    CBlockIndexSmartPtr pnext;
    uint256             blockKeyInDB;
    uint256             nChainTrust; // ppcoin: trust score of block chain
    int                 nHeight;

    int64_t nMint;
    int64_t nMoneySupply;

    unsigned int nFlags; // ppcoin: block index flags

    uint64_t     nStakeModifier;         // hash modifier for proof-of-stake
    unsigned int nStakeModifierChecksum; // checksum of index; in-memeory only

    // proof-of-stake specific fields
    COutPoint    prevoutStake;
    unsigned int nStakeTime;

    uint256 hashProof;

    // block header
    int          nVersion;
    uint256      hashMerkleRoot;
    unsigned int nTime;
    unsigned int nBits;
    unsigned int nNonce;
};

/** The block chain is a tree shaped structure starting with the
 * genesis block at the root, with each block potentially having multiple
 * candidates to be the next block.  pprev and pnext link a path through the
 * main/longest chain.  A blockindex may have multiple pprev pointing back
 * to it, but pnext will only point forward to the longest branch, or will
 * be null if the block is not part of the longest chain.
 */
class CBlockIndex : public boost::enable_shared_from_this<CBlockIndex>
{
public:
    enum
    {
        BLOCK_PROOF_OF_STAKE = (1 << 0), // is proof-of-stake block
        BLOCK_STAKE_ENTROPY  = (1 << 1), // entropy bit for stake modifier
        BLOCK_STAKE_MODIFIER = (1 << 2), // regenerated stake modifier
    };

protected:
    mutable boost::recursive_mutex mtx;
    using LG  = boost::lock_guard<boost::recursive_mutex>;
    using LGP = std::unique_ptr<boost::lock_guard<boost::recursive_mutex>>;
    using UL  = boost::unique_lock<boost::recursive_mutex>;
    using ULP = std::unique_ptr<boost::unique_lock<boost::recursive_mutex>>;

    CBlockIndexContents contents;

public:
    CBlockIndex();

    CBlockIndex(const CBlockIndex& other);

    CBlockIndex(uint256 nBlockPosIn, CBlock& block);

    CBlock GetBlockHeader() const;

    CBlock GetBlockHeader_unsafe() const;

    uint256 GetBlockHash() const;

    uint256 GetBlockHash_unsafe() const;

    int64_t GetBlockTime() const;

    int64_t GetBlockTime_unsafe() const;

    uint256 GetBlockTrust() const;

    bool IsInMainChain() const;

    bool IsInMainChain_unsafe() const;

    bool CheckIndex() const { return true; }

    int64_t GetPastTimeLimit() const;

    int64_t GetPastTimeLimit_unsafe() const;

    enum
    {
        nMedianTimeSpan = 11
    };

    int64_t GetMedianTimePast() const;

    int64_t GetMedianTimePast_unsafe() const;

    /**
     * Returns true if there are nRequired or more blocks of minVersion or above
     * in the last nToCheck blocks, starting at pstart and going backwards.
     */
    static bool IsSuperMajority(int minVersion, const CBlockIndex* pstart, unsigned int nRequired,
                                unsigned int nToCheck);

    bool IsProofOfWork() const
    {
        auto lg = lock_full();
        return IsProofOfWork_unsafe();
    }

    bool IsProofOfWork_unsafe() const { return !(contents.nFlags & BLOCK_PROOF_OF_STAKE); }

    bool IsProofOfStake() const
    {
        auto lg = lock_full();
        return IsProofOfStake_unsafe();
    }

    bool IsProofOfStake_unsafe() const { return (contents.nFlags & BLOCK_PROOF_OF_STAKE); }

    void SetProofOfStake()
    {
        auto lg = lock_full();
        SetProofOfStake_unsafe();
    }

    void SetProofOfStake_unsafe() { contents.nFlags |= BLOCK_PROOF_OF_STAKE; }

    unsigned int GetStakeEntropyBit() const
    {
        auto lg = lock_full();
        return GetStakeEntropyBit_unsafe();
    }

    unsigned int GetStakeEntropyBit_unsafe() const
    {
        return ((contents.nFlags & BLOCK_STAKE_ENTROPY) >> 1);
    }

    bool SetStakeEntropyBit(unsigned int nEntropyBit)
    {
        auto lg = lock_full();
        return SetStakeEntropyBit_unsafe(nEntropyBit);
    }

    bool SetStakeEntropyBit_unsafe(unsigned int nEntropyBit)
    {
        if (nEntropyBit > 1)
            return false;
        contents.nFlags |= (nEntropyBit ? BLOCK_STAKE_ENTROPY : 0);
        return true;
    }

    bool GeneratedStakeModifier() const
    {
        auto lg = lock_full();
        return GeneratedStakeModifier_unsafe();
    }

    bool GeneratedStakeModifier_unsafe() const { return (contents.nFlags & BLOCK_STAKE_MODIFIER); }

    void SetStakeModifier(uint64_t nModifier, bool fGeneratedStakeModifier)
    {
        auto lg = lock_full();
        SetStakeModifier_unsafe(nModifier, fGeneratedStakeModifier);
    }

    void SetStakeModifier_unsafe(uint64_t nModifier, bool fGeneratedStakeModifier)
    {
        contents.nStakeModifier = nModifier;
        if (fGeneratedStakeModifier)
            contents.nFlags |= BLOCK_STAKE_MODIFIER;
    }

    std::string ToString() const;

    void print() const { printf("%s\n", ToString().c_str()); }

    [[nodiscard]] std::tuple<LGP, LGP, LGP> lock_full() const;

    [[nodiscard]] LGP lock_only_this() const;

    CBlockIndexSmartPtr getPrevBlockIndex() const;
    CBlockIndexSmartPtr getPrevBlockIndex_unsafe() const;
    void                setPrevBlockIndex(const CBlockIndexSmartPtr& value);
    void                setPrevBlockIndex_unsafe(const CBlockIndexSmartPtr& value);

    CBlockIndexSmartPtr getNextBlockIndex() const;
    CBlockIndexSmartPtr getNextBlockIndex_unsafe() const;
    void                setNextBlockIndex(const CBlockIndexSmartPtr& value);
    void                setNextBlockIndex_unsafe(const CBlockIndexSmartPtr& value);

    const uint256* getBlockHashPtr() const;
    const uint256* getBlockHashPtr_unsafe() const;
    void           setBlockHashPtr(const uint256* value);
    void           setBlockHashPtr_unsafe(const uint256* value);

    uint256 getBlockKeyInDB() const;
    uint256 getBlockKeyInDB_unsafe() const;
    void    setBlockKeyInDB(const uint256& value);
    void    setBlockKeyInDB_unsafe(const uint256& value);

    uint256 getChainTrust() const;
    uint256 getChainTrust_unsafe() const;
    void    setChainTrust(const uint256& value);
    void    setChainTrust_unsafe(const uint256& value);

    int  getHeight() const;
    int  getHeight_unsafe() const;
    void setHeight(int value);
    void setHeight_unsafe(int value);

    int64_t getMintCount() const;
    int64_t getMintCount_unsafe() const;
    void    setMintCount(const int64_t& value);
    void    setMintCount_unsafe(const int64_t& value);

    int64_t getMoneySupply() const;
    int64_t getMoneySupply_unsafe() const;
    void    setMoneySupply(const int64_t& value);
    void    setMoneySupply_unsafe(const int64_t& value);

    unsigned int getFlags() const;
    unsigned int getFlags_unsafe() const;
    void         setFlags(unsigned int value);
    void         setFlags_unsafe(unsigned int value);

    uint64_t getStakeModifier() const;
    uint64_t getStakeModifier_unsafe() const;
    void     setStakeModifier(const uint64_t& value);
    void     setStakeModifier_unsafe(const uint64_t& value);

    unsigned int getStakeModifierChecksum() const;
    unsigned int getStakeModifierChecksum_unsafe() const;
    void         setStakeModifierChecksum(unsigned int value);
    void         setStakeModifierChecksum_unsafe(unsigned int value);

    COutPoint getPOSPrevoutStake() const;
    COutPoint getPOSPrevoutStake_unsafe() const;
    void      setPOSPrevoutStake(const COutPoint& value);
    void      setPOSPrevoutStake_unsafe(const COutPoint& value);

    unsigned int getPOSStakeTime() const;
    unsigned int getPOSStakeTime_unsafe() const;
    void         setPOSStakeTime(unsigned int value);
    void         setPOSStakeTime_unsafe(unsigned int value);

    uint256 getHashProof() const;
    uint256 getHashProof_unsafe() const;
    void    setHashProof(const uint256& value);
    void    setHashProof_unsafe(const uint256& value);

    int          getHeader_NVersion() const;
    int          getHeader_NVersion_unsafe() const;
    void         setHeader_NVersion(int value);
    void         setHeader_NVersion_unsafe(int value);
    uint256      getHeader_HashMerkleRoot() const;
    uint256      getHeader_HashMerkleRoot_unsafe() const;
    void         setHeader_HashMerkleRoot(const uint256& value);
    void         setHeader_HashMerkleRoot_unsafe(const uint256& value);
    unsigned int getHeader_NTime() const;
    unsigned int getHeader_NTime_unsafe() const;
    void         setHeader_NTime(unsigned int value);
    void         setHeader_NTime_unsafe(unsigned int value);
    unsigned int getHeader_NBits() const;
    unsigned int getHeader_NBits_unsafe() const;
    void         setHeader_NBits(unsigned int value);
    void         setHeader_NBits_unsafe(unsigned int value);
    unsigned int getHeader_Nonce() const;
    unsigned int getHeader_Nonce_unsafe() const;
    void         setHeader_Nonce(unsigned int value);
    void         setHeader_Nonce_unsafe(unsigned int value);
};

#endif // BLOCKINDEX_H
