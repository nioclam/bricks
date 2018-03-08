/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_REFERABLE_H__
#define __BRICKS_AZRAEL_REFERABLE_H__ 1

#include "maker.h"
#include "referencefreer.h"

namespace bricks
{

/**
 * Referable指的是实体，可以被引用的
 * Reference指的是引用
 *
 * 虽然使用相同的定义，但是Reference和Referable是两个概念。
 */
typedef Reference Referable;

/**
 * 基类：可以被引用的
 *
 * - 引用（灵魂）是虚拟的，同一个实体有多个引用（灵魂），每个引用（灵魂）都由独立的死神
 *   掌管它的死亡；
 * - 实体诞生时初始引用计数为1，表示首个引用（灵魂）伴随实体同时诞生；
 * - 每次对实体的引用都诞生一个新的引用（灵魂），并且对实体的引用计数加1；
 * - 每当引用（灵魂）死亡时，对实体的引用计数减1；
 * - 每当实体的引用计数减为0时，消灭实体；
 * - 实体不需要死神掌管死亡。
 */
class Referable : public Maker<Reference, ReferenceFreer>
{
public:
    Referable();

public:
    /**
     * 引用
     */
    Evil<Reference, ReferenceFreer> make();

    /**
     * 获取引用计数
     */
    int referenceCount();

protected:
    /**
     * 引用（灵魂）死亡时，离开实体，实体的引用计数减1
     */
    void leave();

    /**
     * 事件：当引用计数减为0时发生
     *
     * @return NULL 总是返回NULL
     */
    virtual void onReferenceless() = 0;

protected:
    int m_count;

protected:
    friend class ReferenceFreer;
};

}

#include "referencefreer.h"

#endif /* #ifndef __BRICKS_AZRAEL_REFERABLE_H__ */
