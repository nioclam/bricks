/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_FREEZER_H__
#define __BRICKS_RESOURCE_FREEZER_H__ 1

#include <stdexcept>
#include "frozen.h"

namespace bricks
{

/**
 * 冰箱
 */
template <typename VirtualResource>
class Freezer
{
public:
    Freezer()
        : m_number(0)
        , m_releaser(NULL)
    {
    }

    ~Freezer()
    {
        if (0 != m_number)
        {
			bricks()->error("Freezer::~Freezer : memory leak!\n");
			throw std::logic_error("Freezer::~Freezer : memory leak!");
        }
    }

public:
    /**
     * 解冻虚拟资源的生命周期（将虚拟资源的生命周期托管到容器）
     */
    void unfreeze(Frozen<VirtualResource> frozen)
    {
        ++m_number;
        m_releaser = frozen.m_releaser;
        frozen.cancel();
    }

    /**
     * 冻结虚拟资源的生命周期（从容器中取消托管虚拟资源的生命周期）
     */
    Frozen<VirtualResource> freeze(VirtualResource *resource)
    {
        --m_number;
        return Frozen<VirtualResource>(resource, m_releaser);
    }

protected:
    int                          m_number;
	Releasable<VirtualResource> *m_releaser;
};

}

#endif /* #ifndef __BRICKS_RESOURCE_FREEZER_H__ */
