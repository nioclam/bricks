/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
 #include "named.h"

using namespace bricks;

Named::Named(const char *name)
    : m_name(name)
{
}

const char *Named::whoami(Chaos *chaos)
{
    return m_name;
}
