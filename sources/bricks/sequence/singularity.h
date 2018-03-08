/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */

#ifndef __BRICKS_SEQUENCE_SINGULARITY_H__
#define __BRICKS_SEQUENCE_SINGULARITY_H__ 1

#include "element.h"

namespace bricks
{

/**
 * 奇点：序列的特殊元素，代表序列自身
 *
 * @Entity 必须派生自Element
 */
template <typename Entity>
class Singularity : public Entity
{
public:
	Singularity()
		: Entity()
	{
	}

public:
	/**
	 * @see Element
	 */
	virtual bool inSequence()
	{
		return true; // 起点必定在序列中
	}

	/**
	 * @see Element
	 */
	virtual bool isSingular()
	{
		return true;
	}
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_SINGULARITY_H__ */
