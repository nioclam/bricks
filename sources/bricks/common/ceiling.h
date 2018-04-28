/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_COMMON_CEILING_H__
#define __BRICKS_COMMON_CEILING_H__ 1

namespace bricks
{

constexpr int ceiling(int divident, int divisor)
{
    return (divident + divisor - 1) / divisor;
}

}

#endif /* #ifndef __BRICKS_COMMON_CEILING_H__ */
