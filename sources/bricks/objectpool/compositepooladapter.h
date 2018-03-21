/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */
#ifndef __BRICKS_OBJECT_COMPOSITEPOOLADAPTER_H__
#define __BRICKS_OBJECT_COMPOSITEPOOLADAPTER_H__ 1

#include <new>
#include <bricks/misc/misc.h>
#include "compositepool.h"

namespace bricks
{

/**
 * 复合对象池适配器
 */
template <class CompositeObject>
class CompositePoolAdapter : public Composite
{
public:
	CompositePoolAdapter()
	{
	}

public:
	static void *operator new(size_t size)
	{
		return singleton<CompositePool<CompositeObject>>()->restore();
	}

	static void  operator delete(void *ptr, size_t size)
	{
		return singleton<CompositePool<CompositeObject>>()->discard(ptr);
	}
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECT_COMPOSITEPOOLADAPTER_H__ */
