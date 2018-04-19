/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_PHILOSOPHER_WHEREAMI_H__
#define __BRICKS_PHILOSOPHER_WHEREAMI_H__ 1

#include "../player/player.h"

namespace bricks
{

const char *whereami(const char *file, size_t line, Chaos *chaos = bricks::this_player->stringPool);

}

#define WHEREAMI whereami(__FILE__, __LINE__)

#endif /* #ifndef __BRICKS_PHILOSOPHER_WHEREAMI_H__ */
