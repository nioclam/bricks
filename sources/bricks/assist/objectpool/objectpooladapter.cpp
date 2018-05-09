/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#include <bricks/common.h>
#include "objectpooladapter.h"
#include "objectreserved.h"
#include "objectpoolrouter.h"

namespace bricks {

void *ObjectPoolAdapter::operator new(size_t size)
{
    auto router = singleton<ObjectPoolRouter>();
    auto pool   = router->route(size);

    if (nullptr == pool)
    {
        throw std::bad_alloc();
    }

    auto object = pool->fire();

    if (nullptr == object)
    {
        throw std::bad_alloc();
    }

    return object;
}

void *ObjectPoolAdapter::operator new(size_t size, const std::nothrow_t &tag) noexcept
{
    auto router = singleton<ObjectPoolRouter>();
    auto pool   = router->route(size);

    if (nullptr == pool)
    {
        return nullptr;
    }

    auto object = pool->fire();

    if (nullptr == object)
    {
        return nullptr;
    }

    return object;
}

void ObjectPoolAdapter::operator delete(void *ptr) noexcept
{
    auto data = (AlignData<ObjectReserved, ObjectPoolRouter::Alignment> *)ptr;
    auto stub = data->stub();
    auto pool = stub->pool();

    pool->hire(ptr);
}

void *ObjectPoolAdapter::operator new(size_t size, ObjectPool *pool) noexcept
{
    return pool->fire();
}

void ObjectPoolAdapter::operator delete(void *ptr, ObjectPool *pool) noexcept
{
    pool->hire(ptr);
}

}
