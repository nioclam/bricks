/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#include <cstddef>
#include "bricksconfig.h"
#include "bricks.h"

using namespace bricks;

BricksConfig *BricksConfig::operator()()
{
    return singleton<BricksConfig>();
}

BricksConfig *operator()(Journal *journal, int mask)
{
    if (Bricks::Fatal & mask)
    {
        Bricks()->m_fatal = journal;
    }
}

