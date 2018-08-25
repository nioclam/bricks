/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_STACK_H__
#define __BRICKS_POOL_STACK_H__ 1

#include "duck.h"
#include "pool.h"

namespace bricks
{

class Stack : public Pool<Duck>
{
public:
    Stack();
    Stack(Duck *head);

public:
    virtual void hire(Duck *duck);
    virtual Duck *fire();

public:
    Duck *head();

protected:
    Duck m_singularity;
};

}

#endif /* #ifndef __BRICKS_POOL_STACK_H__ */
