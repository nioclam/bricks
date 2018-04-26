/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_STACK_H__
#define __BRICKS_POOL_STACK_H__ 1

#include "resource.h"
#include "pool.h"

namespace bricks
{

class Stack : public Pool<Resource>
{
public:
    Stack();
    Stack(Resource *head);

public:
    virtual void hire(Resource *resource);
    virtual Resource *fire();

protected:
    Resource m_singularity;
};

}

#endif /* #ifndef __BRICKS_POOL_STACK_H__ */
