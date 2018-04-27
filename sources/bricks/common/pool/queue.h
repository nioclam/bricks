/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_QUEUE_H__
#define __BRICKS_POOL_QUEUE_H__ 1

#include "resource.h"
#include "pool.h"

namespace bricks
{

class Queue : public Pool<Resource>
{
public:
    Queue();
    Queue(Resource *head, Resource *tail);

public:
    virtual void hire(Resource *resource);
    virtual Resource *fire();

public:
    Resource *head();

protected:
    Resource  m_singularity;
    Resource *m_tail;
};

}

#endif /* #ifndef __BRICKS_POOL_QUEUE_H__ */
