/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_PHILOSOPHER_NAMED_H__
#define __BRICKS_PHILOSOPHER_NAMED_H__ 1

#include "philosopher.h"

namespace bricks
{

/**
 */
class Named : public Philosopher
{
public:
    Named(const char *name);

public:
    /**
     * @param chaos 参数退化，不需要这个参数了
     */
    virtual const char *whoami(Chaos *chaos = nullptr);

protected:
    const char *m_name;
};

}

#endif /* #ifndef __BRICKS_PHILOSOPHER_NAMED_H__ */
