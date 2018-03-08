/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_SEQUENCE_FINDER_H__
#define __BRICKS_SEQUENCE_FINDER_H__ 1

#include "hint.h"

namespace bricks
{

class Keyword;

/**
 * 搜索操作接口
 * 职责：使用自定义策略搜索与关键字相等的元素
 */
class Finder
{
public:
	/**
	 * 搜索元素
	 */
	virtual Frozen<Hint> find(Keyword *keyword) = 0;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_FINDER_H__ */

