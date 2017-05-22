/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_RELEASABLE_H__
#define __BRICKS_RESOURCE_RELEASABLE_H__ 1

#include <cstddef>

namespace bricks
{

/**
 * 接口：可以释放虚拟资源的
 */
template <typename VirtualResource>
class Releasable
{
public:
    virtual void *release(VirtualResource *resource)
    {
        // 默认实现
        delete resource;
        return NULL;
    }
};

}

#endif /* #ifndef __BRICKS_RESOURCE_RELEASABLE_H__ */
