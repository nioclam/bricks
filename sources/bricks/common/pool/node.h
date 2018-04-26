/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_NODE_H__
#define __BRICKS_POOL_NODE_H__ 1

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

public:
    Node *m_next;
};

}

#endif /* #ifndef __BRICKS_POOL_NODE_H__ */
