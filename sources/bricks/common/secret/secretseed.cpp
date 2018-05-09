/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "secretseed.h"

using namespace bricks;

/**
 * 明文密码，九死一生
 */
SecretSeed::SecretSeed()
    : m_secret(0x9413)
{
}

int32_t SecretSeed::secret()
{
    return m_secret;
}
