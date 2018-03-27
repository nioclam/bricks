/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_PHILOSOPHER_WHOAMI_H__
#define __BRICKS_PHILOSOPHER_WHOAMI_H__ 1

#include <typeinfo>
#include "philosopher.h"

namespace bricks
{

/**
 * 我是谁
 *
 * @return 返回utf8编码的string
 */
template <typename DataType>
inline const char *whoami(DataType unknown, Chaos *chaos)
{
    StringCoder coder(chaos);

    if (-1 == coder.code("#%s", typeid(DataType).name()))
    {
        return "[WhoAmI?]";
    }

    return coder.string();
}

template <typename DataType>
inline const char *whoami(DataType *pointer, Chaos *chaos)
{
    StringCoder coder(chaos);

    if (-1 == coder.code("#%s@%p", typeid(DataType *).name(), pointer))
    {
        return "[WhoAmI?]";
    }

    return coder.string();
}

template <>
inline const char *whoami(Philosopher &philosopher, Chaos *chaos)
{
    return philosopher.whoami(chaos);
}

template <>
inline const char *whoami(Philosopher *philosopher, Chaos *chaos)
{
    return philosopher->whoami(chaos);
}

}

#endif /* #ifndef __BRICKS_PHILOSOPHER_WHOAMI_H__ */
