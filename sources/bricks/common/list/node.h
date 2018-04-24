/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_LIST_NODE_H__
#define __BRICKS_LIST_NODE_H__ 1

namespace bricks
{

class Node
{
public:
    Node();
    Node(Node *next);

public:
    void link(Node *next);
    Node *drop();

protected:
    Node *m_next;
};

}

#endif /* #ifndef __BRICKS_LIST_NODE_H__ */
