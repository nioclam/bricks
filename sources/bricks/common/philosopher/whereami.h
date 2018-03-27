/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_PHILOSOPHER_WHEREAMI_H__
#define __BRICKS_PHILOSOPHER_WHEREAMI_H__ 1

#include "../chaos.h"

namespace bricks
{

const char *whereami(const char *file, size_t line, Chaos *chaos);

}

#define WHEREAMI(chaos) whereami(__FILE__, __LINE__, chaos)

#endif /* #ifndef __BRICKS_PHILOSOPHER_WHEREAMI_H__ */
