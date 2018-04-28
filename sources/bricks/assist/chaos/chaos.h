/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_CHAOS_H__
#define __BRICKS_CHAOS_CHAOS_H__ 1

/**
 * 混沌的世界，唯有盘古能够开天辟地
 */

#include "../azrael.h"
#include "byte.h"
#include "piece.h"
#include "block.h"

namespace bricks
{

/**
 * 混乱的世界，用于存取信息，信息只能以byte_t的形式存在。
 *
 * 提供了两种存取模型：
 * 一是一维空间模型，按位置（position）存取，位置是连续的，不能超过空间大小（size）。
 * 一是内存碎片模型，从位置定位到碎片，碎片是连续的内存块，直接存取内存。
 *
 * 使用了两种资源：
 * 一是位置
 * 一是内存
 *
 * expand和truncate组合接口，为混乱的世界提供了一个类似栈的信息存取方式。
 */
class Chaos
{
public:
    /**
     * 空间的大小
     */
    virtual size_t size() = 0;

    /**
     * 扩展空间的大小
     * 何时何处划分碎片由实现定义，但是必须遵循以下约定，两次expand之间的区间在内存上
     * 必须是连续的
     */
    virtual int expand(size_t size) = 0;

    /**
     * 忘记区间[0, position)的内容，后续位置以及内存没有变化
     * 仅仅提供一个释放闲置资源的时机
     */
    virtual int forget(size_t position) = 0;

    /**
     * 从位置position截断，丢弃区间[position, size)
     */
    virtual int truncate(size_t position) = 0;

    /**
     * 根据空间位置定位到碎片
     */
    virtual Evil<Piece> locate(size_t position) = 0;

    /**
     * 存取position开始的连续空间
     *
     * @return 内存块。当Block.data() == nullptr，表示出错
     */
    Block access(size_t osition);
};

}

#endif /* #ifndef __BRICKS_CHAOS_CHAOS_H__ */
