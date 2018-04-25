/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_POOL_H__
#define __BRICKS_POOL_POOL_H__ 1

namespace bricks
{

template <typename Resource>
class Pool
{
public:
    virtual void hire(Resource *resource) = 0;
    virtual Resource *fire() = 0;
};

}

#endif /* #ifndef __BRICKS_POOL_POOL_H__ */
