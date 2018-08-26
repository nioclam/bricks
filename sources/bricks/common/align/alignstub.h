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
#include "../byte.h"

namespace bricks
{

/**
 * The value of @Alignment shall be a multiple of sizeof( void *),
 * that is also a power of two.
 */
template <typename Reserved, int Alignment>
class AlignStub : public bricks::AlignHead<Reserved>
{
public:
    enum
    {
        Mask = ((Alignment ^ (Alignment - 1)) >> 1),
        Size = (Alignment - sizeof(AlignHead<Reserved>)),
    };

public:
    static void *operator new(size_t size)
    {
        void *align = nullptr;
        int   errno = posix_memalign(&align, Alignment, Alignment);

        if (0 != errno)
        {
            fprintf(
                stderr,
                "AlignStub#Alignment(%d): %s",
                Alignment,
                std::strerror(errno)
            );
            throw std::bad_alloc();
        }

        return align;
    }

    static void *operator new(size_t size, const std::nothrow_t &tag) noexcept
    {
        void *align = nullptr;
        int   errno = posix_memalign(&align, Alignment, Alignment);

        if (0 != errno)
        {
            fprintf(
                stderr,
                "AlignStub#Alignment(%d): %s",
                Alignment,
                std::strerror(errno)
            );
            return nullptr;
        }

        return align;
    }

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
        return static_cast<void *>(this + 1);
    }

    size_t size()
    {
        return AlignStub::Size;
    }
};

}

#endif /* #ifndef __BRICKS_ALIGN_ALIGNSTUB_H__ */
