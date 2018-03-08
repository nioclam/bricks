﻿/**
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
char *whoami(DataType unknown, Chaos *chaos)
{
    CStrCoder coder(chaos);

    if (-1 == coder.code("#%s", typeid(DataType).name()))
    {
        return "[WhoAmI?]";
    }

    return coder.cstr();
}

template <typename DataType>
char *whoami<DataType *>(DataType *pointer, Chaos *chaos)
{
    CStrCoder coder(chaos);

    if (-1 == coder.code("#%s@%p", typeid(DataType *).name(), pointer))
    {
        return "[WhoAmI?]";
    }

    return coder.cstr();
}

template <>
Buffer whoami<Philosopher>(Philosopher &philosopher, Chaos *chaos)
{
    return philosopher.whoami(chaos);
}

template <>
Buffer whoami<Philosopher>(Philosopher *philosopher, Chaos *chaos)
{
    return philosopher->whoami(chaos);
}

}

#endif /* #ifndef __BRICKS_PHILOSOPHER_WHOAMI_H__ */
