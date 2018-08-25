/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_DUCK_H__
#define __BRICKS_POOL_DUCK_H__ 1

namespace bricks
{

class Duck
{
public:
    Duck();
    Duck(Duck *next);

public:
    void link(Duck *next);
    Duck *drop();

public:
    Duck *m_next;
};

}

#endif /* #ifndef __BRICKS_POOL_DUCK_H__ */
