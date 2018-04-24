/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_LIST_QUEUELIST_H__
#define __BRICKS_LIST_QUEUELIST_H__ 1

#include "list.h"

namespace bricks
{

class QueueList : public List
{
public:
    QueueList();
    QueueList(Node *head, Node *tail);

public:
    virtual void push(Node *node);
    virtual Node *pop();

protected:
    Node  m_singularity;
    Node *m_tail;
};

}

#endif /* #ifndef __BRICKS_LIST_QUEUELIST_H__ */
