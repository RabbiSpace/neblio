#include "blockindexcatalog.h"

#include <boost/make_shared.hpp>
#include <utility>

CBlockIndexSmartPtr BlockIndexCatalog::insertBlockIndex_unsafe(uint256 hash)
{
    if (hash == 0)
        return nullptr;

    // Return existing
    BlockIndexMapType::iterator mi = blockIndexMap.find(hash);
    if (mi != blockIndexMap.end())
        return mi->second;

    // Create new
    CBlockIndexSmartPtr pindexNew = boost::make_shared<CBlockIndex>();
    if (!pindexNew)
        throw std::runtime_error("LoadBlockIndex() : new CBlockIndex failed");
    mi = blockIndexMap.insert(std::make_pair(hash, pindexNew)).first;

    pindexNew->setBlockHashPtr(&((*mi).first));

    return pindexNew;
}

BlockIndexCatalog::BlockIndexCatalog() {}

[[nodiscard]] boost::shared_ptr<boost::lock_guard<boost::recursive_mutex>>
BlockIndexCatalog::get_lock() const
{
    return boost::make_shared<boost::lock_guard<boost::recursive_mutex>>(mtx);
}

[[nodiscard]] boost::shared_ptr<boost::unique_lock<boost::recursive_mutex>>
BlockIndexCatalog::get_try_lock() const
{
    auto lock = boost::make_shared<boost::unique_lock<boost::recursive_mutex>>(mtx, boost::defer_lock);
    if (mtx.try_lock()) {
        return lock;
    } else {
        return nullptr;
    }
}
