/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_SEQUENCE_HINTFACTORY_H__
#define __BRICKS_SEQUENCE_HINTFACTORY_H__ 1

#include <bricks/resource/resource.h>
#include "hint.h"

namespace bricks
{

class Sequence;
class Element;

/**
 * 元素索引工厂
 */
class HintFactory : public Releasable<Hint>
				  , public Cloneable<Hint>
{
public:
	/**
	 * @see Cloneable<Hint>
	 */
	virtual Frozen<Hint> make(Hint *hint);

public:
	/**
	 * 创建奇异索引
	 */
	Frozen<Hint> make(Sequence *sequence);

	/**
	 * 创建与元素@element关联的元素索引
	 */
	virtual Frozen<Hint> make(Element *element, Sequence *sequence) = 0;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_HINTFACTORY_H__ */
