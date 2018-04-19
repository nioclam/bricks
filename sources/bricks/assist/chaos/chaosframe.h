/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_CHAOSFRAME_H__
#define __BRICKS_CHAOS_CHAOSFRAME_H__ 1

#include <cstddef>

namespace bricks
{

class Chaos;

/**
 * 按栈的方式使用Chaos
 */
class ChaosFrame
{
public:
    ChaosFrame(Chaos *chaos);
    ~ChaosFrame();

public:
    Chaos  *m_chaos;
    size_t  m_position;
};

}

#endif /* #ifndef __BRICKS_CHAOS_CHAOSFRAME_H__ */
