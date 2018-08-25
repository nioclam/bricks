/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_QUEUE_H__
#define __BRICKS_POOL_QUEUE_H__ 1

#include "duck.h"
#include "pool.h"

namespace bricks
{

class Queue : public Pool<Duck>
{
public:
    Queue();
    Queue(Duck *head, Duck *tail);

public:
    virtual void hire(Duck *duck);
    virtual Duck *fire();

public:
    Duck *head();

protected:
    Duck  m_singularity;
    Duck *m_tail;
};

}

#endif /* #ifndef __BRICKS_POOL_QUEUE_H__ */
