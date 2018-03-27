/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_JOURNAL_TOOLKIT_H__
#define __BRICKS_JOURNAL_TOOLKIT_H__ 1

#include "../philosopher.h"
#include "../player.h"
#include "log.h"

namespace bricks
{

#define Error(...) { \
    Chaos      *__chaos = bricks::this_player->stringPool; \
    ChaosFrame  __frame(__chaos); \
    Log         __error(For_Error, WHEREAMI(__chaos)); \
	__error(__VA_ARGS__); \
}

#define Warning(...) { \
    Chaos      *__chaos = bricks::this_player->stringPool; \
    ChaosFrame  __frame(__chaos); \
    Log         __warning(For_Warning, WHEREAMI(__chaos))(__VA_ARGS__); \
}

#define Message(...) { \
    Chaos      *__chaos = bricks::this_player->stringPool; \
    ChaosFrame  __frame(__chaos); \
    Log         __message(For_Message, WHEREAMI(__chaos))(__VA_ARGS__); \
}

#define Track(...) { \
    Chaos      *__chaos = bricks::this_player->stringPool; \
    ChaosFrame *__frame(__chaos); \
    Log        *__track(For_Track, WHEREAMI(__chaos))(__VA_ARGS__); \
}

}

#endif /* #ifndef __BRICKS_JOURNAL_TOOLKIT_H__ */
