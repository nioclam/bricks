/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_OBJECTPOOL_OBJECTPOOLROUTER_H__
#define __BRICKS_OBJECTPOOL_OBJECTPOOLROUTER_H__ 1

#include <cstddef>
#include <new>
#include "objectpool.h"

namespace bricks
{

/**
 * 对象池适配器
 */
class ObjectPoolRouter
{
public:
    enum {
        Alignment = 8192,
    };

public:
	ObjectPoolRouter();

public:
    ObjectPool *route(size_t size);
};

}

#endif /* #ifndef __BRICKS_OBJECTPOOL_OBJECTPOOLROUTER_H__ */
