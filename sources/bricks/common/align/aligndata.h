/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_ALIGN_ALIGNDATA_H__
#define __BRICKS_ALIGN_ALIGNDATA_H__ 1

#include <cstdio>
#include <cstdint>
#include "alignstub.h"

namespace bricks
{

template <typename Reserved, int Alignment>
class AlignData
{
public:
    typedef AlignStub<Reserved, Alignment> Stub;

public:
    Stub *stub()
    {
        auto s = (Stub *)((uintptr_t)this & Stub::Mask);

        if (s->pass())
        {
            return s;
        }

        fprintf(
            stderr,
            "AlignData@%p#Alignment(%d): invald",
            this,
            Alignment);
        return nullptr;
    }
};

}

#endif /* #ifndef __BRICKS_ALIGN_ALIGNDATA_H__ */
