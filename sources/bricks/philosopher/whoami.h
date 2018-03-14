/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_PHILOSOPHER_WHOAMI_H__
#define __BRICKS_PHILOSOPHER_WHOAMI_H__ 1

#include <typeinfo>
#include <bricks/chaos/chaos.h>

namespace bricks
{

/**
 * 我是谁
 *
 * @return 返回utf8编码的string
 */
template <typename DataType>
char *whoami(DataType unknown, Chaos *chaos = this_player->stringPool)
{
    CStrCoder coder(chaos);

    if (-1 == coder.code("#%s", typeid(DataType).name()))
    {
        return "[WhoAmI?]";
    }

    return coder.cstr();
}

template <typename DataType>
char *whoami<DataType *>(DataType *pointer, Chaos *chaos = this_player->stringPool)
{
    CStrCoder coder(chaos);

    if (-1 == coder.code("#%s@%p", typeid(DataType *).name(), pointer))
    {
        return "[WhoAmI?]";
    }

    return coder.cstr();
}

template <>
char *whoami<Philosopher>(Philosopher &philosopher, Chaos *chaos = this_player->stringPool)
{
    return philosopher.whoami(chaos);
}

template <>
char *whoami<Philosopher>(Philosopher *philosopher, Chaos *chaos = this_player->stringPool)
{
    return philosopher->whoami(chaos);
}

}

#endif /* #ifndef __BRICKS_PHILOSOPHER_WHOAMI_H__ */
