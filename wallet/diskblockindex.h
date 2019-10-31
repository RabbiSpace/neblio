#ifndef DISKBLOCKINDEX_H
#define DISKBLOCKINDEX_H

#include "blockindex.h"
#include "uint256.h"

/** Used to marshal pointers into hashes for db storage. */
class CDiskBlockIndex : public CBlockIndex
{
private:
    uint256 blockHash;

public:
    uint256 hashPrev;
    uint256 hashNext;

    CDiskBlockIndex()
    {
        hashPrev  = 0;
        hashNext  = 0;
        blockHash = 0;
    }

    explicit CDiskBlockIndex(CBlockIndex* pindex) : CBlockIndex(*pindex)
    {
        auto lg1 = lock_full();
        auto lg2 = pindex->lock_full();

        hashPrev = (contents.pprev ? contents.pprev->GetBlockHash() : 0);
        hashNext = (contents.pnext ? contents.pnext->GetBlockHash() : 0);
    }

    // clang-format off
    IMPLEMENT_SERIALIZE (
        auto lg = lock_full();
        if (!(nType & SER_GETHASH)) { READWRITE(nVersion); }
        READWRITE(hashNext);
        READWRITE(contents.blockKeyInDB);
        READWRITE(contents.nHeight);
        READWRITE(contents.nMint);
        READWRITE(contents.nMoneySupply);
        READWRITE(contents.nFlags);
        READWRITE(contents.nStakeModifier);
        if (IsProofOfStake()) {
            READWRITE(contents.prevoutStake);
            READWRITE(contents.nStakeTime);
        } else if (fRead) {
            const_cast<CDiskBlockIndex*>(this)->contents.prevoutStake.SetNull();
            const_cast<CDiskBlockIndex*>(this)->contents.nStakeTime = 0;
        }
        READWRITE(contents.hashProof);

        // block header
        READWRITE(this->contents.nVersion);
        READWRITE(hashPrev);
        READWRITE(contents.hashMerkleRoot);
        READWRITE(contents.nTime);
        READWRITE(contents.nBits);
        READWRITE(contents.nNonce);
        READWRITE(blockHash);
    )
    // clang-format on

    void SetBlockHash(const uint256& hash) { blockHash = hash; }

    uint256 GetBlockHash() const;

    std::string ToString() const;

    void print() const { printf("%s\n", ToString().c_str()); }
};

#endif // DISKBLOCKINDEX_H
