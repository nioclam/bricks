/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_SECRET_SECRET_H__
#define __BRICKS_SECRET_SECRET_H__ 1

#include <cstdint>

namespace bricks
{

class Secret
{
public:
    static int32_t seed();

public:
    Secret();
    bool pass();

private:
    int32_t m_secret;
};

}

#endif /* #ifndef __BRICKS_SECRET_SECRET_H__ */
