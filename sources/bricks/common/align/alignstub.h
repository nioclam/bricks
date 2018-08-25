/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_ALIGN_ALIGNSTUB_H__
#define __BRICKS_ALIGN_ALIGNSTUB_H__ 1

#include <cstdio>
#include <cstring>
#include <cstddef>
#include <cstdint>
#include <new>
#include "alignhead.h"

namespace bricks
{

/**
 * The value of @Alignment shall be a multiple of sizeof( void *),
 * that is also a power of two.
 */
template <typename Reserved, int Alignment>
class alignas(Alignment) AlignStub : public bricks::AlignHead<Reserved>
{
public:
    enum
    {
        Mask = ((Alignment ^ (Alignment - 1)) >> 1),
        Size = (Alignment - sizeof(AlignHead<Reserved>)),
    };

public:
    AlignStub()
    {
        if ((uintptr_t)this & AlignStub::Mask && sizeof(AlignStub) != Alignment)
        {
            fprintf(
                stderr,
                "AlignStub@%p#Alignment(%d)",
                this,
                Alignment);
            throw std::bad_alloc();
        }
    }

    ~AlignStub()
    {
    }

    void *page()
    {
        return m_page;
    }

    size_t size()
    {
        return AlignStub::Size;
    }

protected:
    char m_page[AlignStub::Size];
};

}

#endif /* #ifndef __BRICKS_ALIGN_ALIGNSTUB_H__ */
