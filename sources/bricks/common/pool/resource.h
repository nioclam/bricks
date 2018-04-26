/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_POOL_RESOURCE_H__
#define __BRICKS_POOL_RESOURCE_H__ 1

namespace bricks
{

class Resource
{
public:
    Resource();
    Resource(Resource *next);

public:
    void link(Resource *next);
    Resource *drop();

public:
    Resource *m_next;
};

}

#endif /* #ifndef __BRICKS_POOL_RESOURCE_H__ */
