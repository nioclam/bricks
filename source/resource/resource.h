/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_RESOURCE_H__
#define __BRICKS_RESOURCE_RESOURCE_H__ 1

/**
 * 未知死焉知生
 */
#include "releasable.h"
#include "frozen.h"
#include "freezer.h"
#include "stupid.h"
#include "makable.h"
#include "cloneable.h"
#include "reference.h"

namespace bricks
{

class ResourceReleaser;

/**
 * Resource是资源，资源必须被释放
 *
 * 虚拟资源是广义的资源，不一定实现了Resource接口，但是必须被释放。例如: 通过new构造
 * 的对象是虚拟资源，必须使用delete释放。
 */
class Resource
{
protected:
    /**
     * 释放资源
     *
     * @return NULL 总是返回NULL
     */
    virtual void *release() = 0;

protected:
    friend class ResourceReleaser;
};

}

#include "resourcereleaser.h"
#include "referenceresource.h"

#endif /* #ifndef __BRICKS_RESOURCE_RESOURCE_H__ */
