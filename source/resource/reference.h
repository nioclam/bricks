/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_REFERENCE_H__
#define __BRICKS_RESOURCE_REFERENCE_H__ 1

#include "makable.h"

namespace bricks
{

class ReferenceReleaser;

/**
 * Reference是一种虚拟资源，以引用计数的方式管理另一种（被引用的）虚拟资源的生命周期。
 * Reference（以下称为引用）获取虚拟资源的一个引用计数，释放引用即是释放虚拟资源的引
 * 用计数。直至虚拟资源的引用计数为0，则释放虚拟资源。
 * 构造（支持引用计数的）虚拟资源的同时，构造第一个（该虚拟资源的）引用，称为原生引用（
 * 即虚拟资源初始引用计数为1）。以后通过Reference::Makable<Reference>::make()构造
 * 引用，称为派生引用。原生引用和派生引用等价，无法区分。
 * 一般来说，仅仅在概念上区分引用和虚拟资源，实际上它们是同一个内存地址。
 *
 * @see Makable<Reference>
 */
class Reference : public Makable<Reference>
{
public:
    Reference();

public:
    /**
     * @see Makable<Reference>
     */
    Frozen<Reference> make();

    /**
     * 获取虚拟资源的引用计数
     */
    int referenceCount();

protected:
    /**
     * 释放Reference，减少被引用的虚拟资源的引用计数
     */
    void *decrease();

    /**
     * 事件：当虚拟资源的引用计数为0时发生：需要释放虚拟资源
     *
     * @return NULL 总是返回NULL
     */
    virtual void *onReferenceless() = 0;

protected:
    int m_count;

protected:
    friend class ReferenceReleaser;
};

}

#include "referencereleaser.h"

#endif /* #ifndef __BRICKS_RESOURCE_REFERENCE_H__ */
