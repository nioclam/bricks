/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#include "objectpooladapter.h"
#include "objectpoolsize.h"

using namespace bricks;
using namespace bricks_objectpool;

ObjectPoolAdapter::ObjectPoolAdapter()
{
}

void* ObjectPoolAdapter::operator new(size_t size)
{
	ObjectPool *pool = NULL;

	if (NULL == (pool = adapt(size)))
	{
		return ::operator new(size);
	}

	return pool->restore();
}

void ObjectPoolAdapter::operator delete(void* ptr, size_t size)
{
	ObjectPool *pool = NULL;

	if (NULL == (pool = adapt(size)))
	{
		return ::operator delete(ptr);
	}

	pool->discard(ptr);
}

int ObjectPoolAdapter::align(int size)
{
	return size / BaseSize;
}

ObjectPool *ObjectPoolAdapter::adapt(int size)
{
	static ObjectPool *objectPoolVector[] =
	{
		singleton<ObjectPoolSize<BaseSize * 0x01>>(),
		singleton<ObjectPoolSize<BaseSize * 0x02>>(),
		singleton<ObjectPoolSize<BaseSize * 0x03>>(),
		singleton<ObjectPoolSize<BaseSize * 0x04>>(),
		singleton<ObjectPoolSize<BaseSize * 0x05>>(),
		singleton<ObjectPoolSize<BaseSize * 0x06>>(),
		singleton<ObjectPoolSize<BaseSize * 0x07>>(),
		singleton<ObjectPoolSize<BaseSize * 0x08>>(),
		singleton<ObjectPoolSize<BaseSize * 0x09>>(),
		singleton<ObjectPoolSize<BaseSize * 0x0a>>(),
		singleton<ObjectPoolSize<BaseSize * 0x0b>>(),
		singleton<ObjectPoolSize<BaseSize * 0x0c>>(),
		singleton<ObjectPoolSize<BaseSize * 0x0d>>(),
		singleton<ObjectPoolSize<BaseSize * 0x0e>>(),
		singleton<ObjectPoolSize<BaseSize * 0x0f>>(),
		singleton<ObjectPoolSize<BaseSize * 0x10>>(),
	};

	int index = align(size);

	if (index < sizeof(objectPoolVector) / sizeof(objectPoolVector[0]))
	{
		return objectPoolVector[index];
	}

	return NULL;
}

