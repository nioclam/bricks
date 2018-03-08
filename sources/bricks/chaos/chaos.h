/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_CHAOS_H__
#define __BRICKS_CHAOS_CHAOS_H__ 1

/**
 * 混沌的世界，唯有盘古能够开天辟地
 */

#include "byte.h"
#include "piece.h"
#include "coder.h"
#include "cstrcoder.h"

namespace bricks
{

/**
 * 混乱的世界，用于存取信息，信息只能以byte_t的形式存在。
 * 世界提供了两个存取模型：
 * 一是一维空间模型，按空间位置（position）存取，位置是连续的，不能超过空间大小（size）。
 * 二是碎片模型，碎片是一块连续的内存，以空间位置定位到碎片，然后直接存取内存。
 */
class Chaos
{
public:
    /**
     * 空间的大小
     */
    size_t size() = 0;

    /**
     * 扩展空间的大小
     * 何时何处划分碎片由实现定义，但是必须遵循以下约定，两次expand之间的空间必须是连
     * 续的
     */
    int expand(size_t size) = 0;

    /**
     * 遗忘[0, size)之间的信息，遗忘之后无法再存取，但是不会改变空间的位置。仅仅为了
     * 获取释放内存的时机。
     */
    int forget(size_t size) = 0;

    /**
     * 根据空间位置定位到碎片
     */
    Piece *locate(int position) = 0;

    /**
     * 存取position开始的连续空间
     *
     * @return result.first  position对应的内存地址
     *         result.second 从position开始能够连续存取的长度
     */
    std::pair<byte_t *, size_t> access(int position);
};

}

#endif /* #ifndef __BRICKS_CHAOS_CHAOS_H__ */
