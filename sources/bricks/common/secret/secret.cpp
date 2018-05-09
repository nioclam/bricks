/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "secret.h"
#include "secretseed.h"
#include "../singleton.h"

using namespace bricks;

int32_t Secret::seed()
{
    return singleton<SecretSeed>()->secret();
}

Secret::Secret()
    : m_secret(Secret::seed())
{
}

bool Secret::pass()
{
    return m_secret == Secret::seed();
}
