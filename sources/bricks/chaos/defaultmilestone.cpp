/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "defaultmilestone.h"
#include "chaos.h"

size_t DefaultMilestone::next(size_t progress, Chaos *chaos)
{
    int milestone = chaos->size();

    if (progress <= milestone)
    {
        return milestone;
    }

    return milestone + milestone >> 2 + 32;
}
