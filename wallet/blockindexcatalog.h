#ifndef BLOCKINDEXCATALOG_H
#define BLOCKINDEXCATALOG_H

#include "blockindex.h"
#include "globals.h"
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <map>
#include <uint256.h>

class CBlockIndex;

class BlockIndexCatalog
{
    mutable boost::recursive_mutex mtx;

    BlockIndexMapType blockIndexMap;

public:
    BlockIndexCatalog();

    [[nodiscard]] boost::shared_ptr<boost::lock_guard<boost::recursive_mutex>> get_lock() const;

    [[nodiscard]] boost::shared_ptr<boost::unique_lock<boost::recursive_mutex>> get_try_lock() const;

    CBlockIndexSmartPtr insertBlockIndex_unsafe(uint256 hash);
};

#endif // BLOCKINDEXCATALOG_H
