/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_QUEUE_H__
#define __BRICKS_POOL_QUEUE_H__ 1

#include "node.h"
#include "pool.h"

namespace bricks
{

class Queue : public Pool<Node>
{
public:
    Queue();
    Queue(Node *head, Node *tail);

public:
    virtual void hire(Node *node);
    virtual Node *fire();

protected:
    Node  m_singularity;
    Node *m_tail;
};

}

#endif /* #ifndef __BRICKS_POOL_QUEUE_H__ */
