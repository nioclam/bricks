/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_SECRET_SECRETSEED_H__
#define __BRICKS_SECRET_SECRETSEED_H__ 1

#include <cstdint>

namespace bricks
{

class SecretSeed
{
public:
    SecretSeed();
    int32_t secret();

protected:
    int32_t m_secret;
};

}

#endif /* #ifndef __BRICKS_SECRET_SECRETSEED_H__ */
