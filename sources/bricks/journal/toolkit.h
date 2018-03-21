/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_JOURNAL_TOOLKIT_H__
#define __BRICKS_JOURNAL_TOOLKIT_H__ 1

#include <bricks/philosopher.h>
#include <bricks/player.h>
#include "log.h"

namespace bricks
{

#define Error(what, ...) { \
    Chaos      __chaos = bricks::this_player->stringPool;
    ChaosFrame __frame(__chaos);
    Log        __error(For_Error, WHEREAMI(__chaos))(what, __VA_ARGS__);
}

#define Warning(what, ...) { \
    Chaos      __chaos = bricks::this_player->stringPool;
    ChaosFrame __frame(__chaos);
    Log        __warning(For_Warning, WHEREAMI(__chaos))(what, __VA_ARGS__);
}

#define Message(what, ...) { \
    Chaos      __chaos = bricks::this_player->stringPool;
    ChaosFrame __frame(__chaos);
    Log        __message(For_Message, WHEREAMI(__chaos))(what, __VA_ARGS__);
}

#define Track(what, ...) { \
    Chaos      __chaos = bricks::this_player->stringPool;
    ChaosFrame __frame(__chaos);
    Log        __track(For_Track, WHEREAMI(__chaos))(what, __VA_ARGS__);
}

}
#endif /* #ifndef __BRICKS_JOURNAL_TOOLKIT_H__ */
