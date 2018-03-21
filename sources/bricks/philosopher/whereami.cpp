/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include <bricks/chaos.h>
#include "whereami.h"

char *bricks::whereami(const char *file, size_t line, Chaos *chaos)
{
    StringCoder coder(chaos);

    if (-1 == coder.code("@%s#%d", file, line))
    {
        return "[WhereAmI?]";
    }

    return coder.string();
}
