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
Buffer whoami(DataType unknown, Chaos *chaos)
{
    auto name = chaos.next();

    *chaos("#")(typeid(DataType).name())("\0");
    chaos.format(u8"#%s", typeid(DataType).name());
}

template <typename DataType>
Buffer whoami<DataType *>(DataType *pointer)
{
    return Buffer(u8"#%s@%p", typeid(DataType *), pointer);
}

template <>
Buffer whoami<Philosopher>(Philosopher &philosopher)
{
    return philosopher.whoami();
}

template <>
Buffer whoami<Philosopher>(Philosopher *philosopher)
{
    return philosopher->whoami();
}

}

#endif /* #ifndef __BRICKS_PHILOSOPHER_WHOAMI_H__ */
