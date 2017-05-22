/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_STUPIDMETHOD_H__
#define __BRICKS_RESOURCE_STUPIDMETHOD_H__ 1

#include <stdexcept>
#include "../misc/bricks.h"
#include "releasable.h"
#include "frozen.h"

namespace bricks
{

/**
 * 傻瓜指针方法
 */
template <typename VirtualResource, typename Object>
class StupidMethod : protected Holder<Object *>
{
public:
	StupidMethod()
		: Holder<Object *>()
		, m_releaser(NULL)
	{
	}

	StupidMethod(Releasable<VirtualResource> *releaser)
		: Holder<Object *>()
		, m_releaser(releaser)
	{
	}

	StupidMethod(Object *resource, Releasable<VirtualResource> *releaser)
		: Holder<Object *>(resource)
		, m_releaser(releaser)
	{
		if (NULL == m_releaser)
		{
			throw std::bad_alloc();
		}
	}

	~StupidMethod()
	{
		release();
	}

protected: // 禁止拷贝构造和拷贝赋值函数
	StupidMethod(const StupidMethod<VirtualResource, Object> &that)
	{
		bricks()->error("StupidMethod : Copy Constructor is forbidden\n");
		throw std::logic_error("StupidMethod : Copy Constructor is forbidden");
	}

	StupidMethod<VirtualResource, Object> &operator=(const StupidMethod<VirtualResource, Object> &that)
	{
		bricks()->error("StupidMethod : Copy-Assignment Operator is forbidden\n");
		throw std::logic_error("StupidMethod : Copy-Assignment Operator is forbidden");
		return StupidMethod<VirtualResource, Object>();
	}

public:
	/**
	 * 冻结虚拟资源（传递虚拟资源的生命周期）
	 */
	Frozen<VirtualResource> freeze()
	{
		return std::move(Frozen<VirtualResource>(cancel()));
	}

	/**
	 * 解冻虚拟资源（接管虚拟资源的生命周期）
	 */
	int unfreeze(Frozen<VirtualResource> &&frozen)
	{
		Object *resource = NULL;

		resource   = static_cast<Object *>(frozen.cancel());
		m_releaser = frozen.m_releaser;

		release();
		Holder<Object *>::hold(resource);

		return (NULL == resource) ? -1 : 0;
	}

	/**
	 * 获取对象指针
	 */
	Object *resource()
	{
		return Holder<Object *>::data();
	}

	Object &operator*()
	{
		return *Holder<Object *>::data();
	}

	operator Object *() const
	{
		return Holder<Object *>::data();
	}

	Object *operator->() const
	{
		return Holder<Object *>::data();
	}

protected:
	/**
	 * 取消托管生命周期
	 */
	Object *cancel()
	{
		return Holder<Object *>::hold(NULL);
	}

	void release()
	{
		Object *resource = cancel();

		if (NULL != resource)
		{
			m_releaser->release(resource);
		}
	}

protected:
	Releasable<VirtualResource> *m_releaser;
};

}

#endif /* #ifndef __BRICKS_RESOURCE_STUPIDMETHOD_H__ */
