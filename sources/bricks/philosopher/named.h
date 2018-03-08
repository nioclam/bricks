/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_PHILOSOPHER_NAMED_H__
#define __BRICKS_PHILOSOPHER_NAMED_H__ 1

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
     * Philosopher is who know 'who am I?'.
     */
    virtual Buffer whoami();

protected:
    const char *m_name;
};

}

#endif /* #ifndef __BRICKS_PHILOSOPHER_NAMED_H__ */
