/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_CODER_H__
#define __BRICKS_CHAOS_CODER_H__ 1

#include <cstddef>
#include <bricks/common.h>

/**
 * 程序员是混乱的制造者。
 * 只有程序员本人知道写的是什么鬼，几个月以后，自己也忘记了。
 */

namespace bricks
{

class Chaos;

/**
 * 很遗憾，作为初级程序员，只能记住最后一次写的代码
 */
class Coder
{
public:
    /**
     * 初级程序员总是从chaos末尾开始写代码
     */
    Coder(Chaos *chaos);

public:
    /**
     * 最后一份源代码在这里
     * 一般是chaos->access(m_position).data
     */
    byte_t *source();

protected:
    Chaos  *m_chaos;
    size_t  m_position;
};

}

#endif /* #ifndef __BRICKS_CHAOS_CODER_H__ */
