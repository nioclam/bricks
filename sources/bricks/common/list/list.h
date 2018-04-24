/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_LIST_LIST_H__
#define __BRICKS_LIST_LIST_H__ 1

#include "node.h"

namespace bricks
{

class List
{
public:
    virtual void push(Node *node) = 0;
    virtual Node *pop() = 0;
};

}

#endif /* #ifndef __BRICKS_LIST_LIST_H__ */
