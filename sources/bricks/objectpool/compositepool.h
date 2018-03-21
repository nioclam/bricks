/**
 * MIT License
 * Copyright (C) 2016, Coin Lam.
 */
#ifndef __BRICKS_OBJECT_COMPOSITEPOOL_H__
#define __BRICKS_OBJECT_COMPOSITEPOOL_H__ 1

#include "objectpool.h"
#include "compositenode.h"

namespace bricks
{

/**
 * 复合对象池适配器
 */
template <class CompositeObject>
class CompositePool : public ObjectPool
{
public:
	static const int PoolLimit = 128;

public:
	CompositePool()
		: m_nextNode(NULL)
		, m_objectCount(0)
	{
	}

	~CompositePool()
	{
		CompositeNode<CompositeObject> *node   = NULL;
		CompositeNode<CompositeObject> *next   = NULL;
		CompositeObject                *object = NULL;

		for (
				node = m_nextNode;
				NULL != node;
				node = next)
		{
			next   = node->m_nextNode;
			object = node->m_object;

			delete object;
			delete node;
		}
	}

public: // 继承自ObjectPool
	virtual void *restore()
	{
		CompositeNode<CompositeObject> *node   = NULL;
		CompositeObject                *object = NULL;

		if (NULL != m_nextNode)
		{
			--m_objectCount;

			node       = m_nextNode;
			m_nextNode = node->m_nextNode;
			object     = node->m_object;
			delete node;

			return object;
		}

		return new CompositeObject();
	}

	virtual void *discard(void *object)
	{
		CompositeNode<CompositeObject> *node      = NULL;
		CompositeObject                *composite = static_cast<CompositeObject *>(object);

		if (m_objectCount < PoolLimit)
		{
			if (NULL != (node = new(std::nothrow) CompositeNode<CompositeObject>()))
			{
				++m_objectCount;

				node->m_nextNode = m_nextNode;
				node->m_object   = composite;
				m_nextNode       = node;
				composite->cleanup();

				return /* void */;
			}
		}

		delete composite;
	}

protected:
	CompositeNode<CompositeObject> *m_nextNode;
	int                             m_objectCount;
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECT_COMPOSITEPOOL_H__ */

