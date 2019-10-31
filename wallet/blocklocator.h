#ifndef BLOCKLOCATOR_H
#define BLOCKLOCATOR_H

#include "boost/foreach.hpp"
#include "globals.h"
#include "serialize.h"
#include "uint256.h"
#include <vector>

class CBlockIndex;

/** Describes a place in the block chain to another node such that if the
 * other node doesn't have the same branch, it can find a recent common trunk.
 * The further back it is, the further before the fork it may be.
 */
class CBlockLocator
{
protected:
    std::vector<uint256> vHave;

public:
    CBlockLocator() {}

    explicit CBlockLocator(ConstCBlockIndexSmartPtr pindex);

    explicit CBlockLocator(uint256 hashBlock);

    CBlockLocator(const std::vector<uint256>& vHaveIn);

    IMPLEMENT_SERIALIZE(if (!(nType & SER_GETHASH)) READWRITE(nVersion); READWRITE(vHave);)

    void SetNull();

    bool IsNull();

    void Set(ConstCBlockIndexSmartPtr pindex);

    int GetDistanceBack();

    CBlockIndexSmartPtr GetBlockIndex();

    uint256 GetBlockHash();

    int GetHeight();
};

#endif // BLOCKLOCATOR_H
