/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_LIST_STACKLIST_H__
#define __BRICKS_LIST_STACKLIST_H__ 1

#include "list.h"

namespace bricks
{

class StackList : public List
{
public:
    StackList();

public:
    virtual void push(Node *node);
    virtual Node *pop();

protected:
    Node m_singularity;
};

}

#endif /* #ifndef __BRICKS_LIST_STACKLIST_H__ */
