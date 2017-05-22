/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */

#ifndef __BRICKS_OBJECT_COMPOSITENODE_H__
#define __BRICKS_OBJECT_COMPOSITENODE_H__ 1

#include "objectpooladapter.h"

namespace bricks
{

/**
 * 复合对象节点
 */
template <class CompositeObject>
class CompositeNode : public ObjectPoolAdapter
{
public:
	CompositeNode()
		: m_nextNode(NULL)
		, m_object(NULL)
	{
	}

public:
	CompositeNode   *m_nextNode;
	CompositeObject *m_object;
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECT_COMPOSITENODE_H__ */

