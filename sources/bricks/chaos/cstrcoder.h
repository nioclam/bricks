/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_CSTRCODER_H__
#define __BRICKS_CHAOS_CSTRCODER_H__ 1

#include "coder.h"

namespace bricks
{

class CStrCoder : public Coder
{
public:
    CStrCoder(Chaos *chaos);

public:
    int code(const char *format, ...);
    char *cstr();
};

}

#endif /* #ifndef __BRICKS_CHAOS_CSTRCODER_H__ */
