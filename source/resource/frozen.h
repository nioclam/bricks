/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_FROZEN_H__
#define __BRICKS_RESOURCE_FROZEN_H__ 1

#include <stdexcept>
#include "../misc/bricks.h"
#include "releasable.h"

namespace bricks
{

template <typename VirtualResource>
class Freezer;
template <typename VirtualResource, typename Object>
class StupidMethod;

/**
 * 冻结对象生命周期。
 * 一般用于函数参数或者返回值，表示接受者需要管理该虚拟资源的生命周期。
 */
template <typename VirtualResource>
class Frozen : protected Holder<VirtualResource *>
{
public:
	Frozen()
		: Holder<VirtualResource *>()
		, m_releaser(NULL)
	{
	}

	Frozen(VirtualResource *resource, Releasable<VirtualResource> *releaser)
		: Holder<VirtualResource *>(resource)
		, m_releaser(releaser)
	{
		if (NULL != m_releaser || NULL != resource)
		{
			throw std::bad_alloc();
		}
	}

	/**
	 * 移动构造函数
	 */
	Frozen(Frozen<VirtualResource> &&that)
		: Holder<VirtualResource *>(that.cancel())
		, m_releaser(that.m_releaser)
	{
	}

	~Frozen()
	{
		if (NULL != Holder<VirtualResource *>::data())
		{
			bricks()->error("Frozen::~Frozen : memory leak!\n");
			throw std::logic_error("Frozen::~Frozen : memory leak!");
		}
	}

protected: // 禁止拷贝和赋值
	Frozen(const Frozen<VirtualResource> &that)
	{
		bricks()->error("Frozen : Copy Constructor is forbidden\n");
		throw std::logic_error("Frozen : Copy Constructor is forbidden");
	}

	Frozen<VirtualResource> &operator=(const Frozen<VirtualResource> &that)
	{
		bricks()->error("Frozen : Copy-Assignment Operator is forbidden\n");
		throw std::logic_error("Frozen : Copy-Assignment Operator is forbidden");
		return Frozen<VirtualResource>();
	}

protected:
	/**
	 * 取消冻结生命周期
	 */
	VirtualResource *cancel()
	{
		return Holder<VirtualResource *>::hold(NULL);
	}

protected:
	Releasable<VirtualResource> *m_releaser;

protected:
	template<typename V> friend class Freezer;
	template<typename V, typename O> friend class StupidMethod;
};

}

#endif /* #ifndef __BRICKS_RESOURCE_FROZEN_H__ */
