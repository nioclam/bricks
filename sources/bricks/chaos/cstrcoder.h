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
    CStrCoder(Chaos *chaos, size_t position, Milestone *milestone = singleton<DefaultMilestone>());

public:
    int format(const char *base, ...);
    char *cstr();
};

}

#endif /* #ifndef __BRICKS_CHAOS_CSTRCODER_H__ */
