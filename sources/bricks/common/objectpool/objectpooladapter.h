/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_OBJECT_OBJECTPOOLADAPTER_H__
#define __BRICKS_OBJECT_OBJECTPOOLADAPTER_H__ 1

#include <cstddef>
#include <new>
#include "objectpool.h"

namespace bricks
{

/**
 * 对象池适配器
 */
class ObjectPoolAdapter
{
public:
	ObjectPoolAdapter();

public:
	static void *operator new(size_t size);
	static void  operator delete(void *ptr, size_t size);

protected:
	static int align(int size);
	static ObjectPool *adapt(int size);

protected:
	static const int BaseSize = 8;
};

}

#endif /* #ifndef __BRICKS_OBJECT_OBJECTPOOLADAPTER_H__ */
