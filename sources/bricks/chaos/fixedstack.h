/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_FIXEDSTACK_H__
#define __BRICKS_CHAOS_FIXEDSTACK_H__ 1

#include "chaos.h"

namespace bricks
{

class FixedStack : public Chaos
{
public:
    FixedStack(size_t capacity = 8192);

public:
    virtual size_t size();
    virtual int expand(size_t size);
    virtual int forget(size_t position);
    virtual int truncate(size_t position);
    virtual Evil<Piece> locate(int position);

public:
    byte_t *stack();

protected:
    byte_t *m_stack;
    size_t  m_capacity;
    size_t  m_size;
};

}

#endif /* #ifndef __BRICKS_CHAOS_FIXEDSTACK_H__ */
