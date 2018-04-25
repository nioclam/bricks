/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_STACK_H__
#define __BRICKS_POOL_STACK_H__ 1

#include "node.h"
#include "pool.h"

namespace bricks
{

class Stack : public Pool<Node>
{
public:
    Stack();
    Stack(Node *head);

public:
    virtual void hire(Node *node);
    virtual Node *fire();

protected:
    Node m_singularity;
};

}

#endif /* #ifndef __BRICKS_POOL_STACK_H__ */
