/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_LIST_UNINODE_H__
#define __BRICKS_LIST_UNINODE_H__ 1

namespace bricks
{

class UNINode
{
public:
    UNINode();

public:
    void link(UNINode *next); // link to stub's next of list
    UNINode *drop();          // drop stub's next of list

protected:
    UNINode *m_next;
};

}

#endif /* #ifndef __BRICKS_LIST_UNINODE_H__ */
