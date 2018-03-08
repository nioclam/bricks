/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_SEQUENCE_ELEMENT_H__
#define __BRICKS_SEQUENCE_ELEMENT_H__ 1

#include <bricks/object/object.h>

namespace bricks
{

/**
 * 元素
 */
class Element : public ObjectPoolAdapter
{
public:
	Element();

public:
	/**
	 * 判断是否在序列中
	 */
	virtual bool inSequence() = 0;

	/**
	 * 判断是否是奇异的
	 */
	virtual bool isSingular();
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_ELEMENT_H__ */

