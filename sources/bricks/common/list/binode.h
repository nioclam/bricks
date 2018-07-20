/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_LIST_BINODE_H__
#define __BRICKS_LIST_BINODE_H__ 1

namespace bricks
{

class BINode
{
public:
    BINode();

public:
    void enter(BINode *listAtStub); // node enter list at stub
    void leave();                   // node leave list

protected:
    BINode *m_prev;
    BINode *m_next;
};

}

#endif /* #ifndef __BRICKS_LIST_BINODE_H__ */
