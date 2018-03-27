/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_SEQUENCE_KEYWORDFACTORY_H__
#define __BRICKS_SEQUENCE_KEYWORDFACTORY_H__ 1

#include <bricks/resource/resource.h>
#include "keyword.h"

namespace bricks
{

class Element;

/**
 * 关键字工厂
 */
class KeywordFactory : public Releasable<Keyword>
{
public:
	/**
	 * 创建关键字
	 *
	 * @return    * 成功，返回关键字指针
	 *         NULL 失败
	 */
	virtual Frozen<Keyword> make(Element *element) = 0;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_KEYWORDFACTORY_H__ */
