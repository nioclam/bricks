/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_OBJECTPOOL_OBJECTPOOLADAPTER_H__
#define __BRICKS_OBJECTPOOL_OBJECTPOOLADAPTER_H__ 1

#include <new>
#include "objectpool.h"

namespace bricks
{

class ObjectPoolAdapter
{
public:
    static void *operator new(size_t size);
    static void *operator new(size_t size, const std::nothrow_t &tag) noexcept;
    static void  operator delete(void *ptr) noexcept;
    static void *operator new(size_t size, ObjectPool *pool) noexcept;
    static void  operator delete(void *ptr, ObjectPool *pool) noexcept;
};

}

#endif /* #ifndef __BRICKS_OBJECTPOOL_OBJECTPOOLADAPTER_H__ */
