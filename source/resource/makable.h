/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_MAKABLE_H__
#define __BRICKS_RESOURCE_MAKABLE_H__ 1

#include "frozen.h"

namespace bricks
{

/**
 * 接口：可以默认构造VirtualResource的
 */
template <typename VirtualResource>
class Makable
{
public:
    virtual Frozen<VirtualResource> make() = 0;
};

}

#endif /* #ifndef __BRICKS_RESOURCE_MAKABLE_H__ */
