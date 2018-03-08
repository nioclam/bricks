/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_CODER_H__
#define __BRICKS_CHAOS_CODER_H__ 1

#include <misc/misc.h>
#include "byte.h"
#include "defaultmilestone.h"

/**
 * 程序员是混乱的制造者。
 * 只有程序员本人知道写的是什么鬼，几个月以后，自己也忘记了。
 */

namespace bricks
{

class Chaos;
class Coder
{
public:
    /**
     * @param chaos    混乱的世界
     * @param position 开始制造混乱的位置
     */
    Coder(Chaos *chaos, size_t position, Milestone *milestone = singleton<DefaultMilestone>());

public:
    /**
     * 代码在这里
     * 一般是chaos->access(position).first
     */
    byte_t *code();

    /**
     * 代码的大小
     */
    size_t size();

    /**
     * 代码在chaos的起始位置
     */
    int lowerPosition();

    /**
     * 代码在chaos的结束位置
     */
    int upperPosition();

protected:
    /**
     * 程序员做计划，麻烦（混乱）就更大了。
     *
     * @return -1 计划失败
     */
    int plan(size_t progress);

protected:
    Milestone *m_milestone;
    Chaos     *m_chaos;
    size_t     m_lowerPosition;
    size_t     m_upperPosition;
};

}

#endif /* #ifndef __BRICKS_CHAOS_CODER_H__ */
