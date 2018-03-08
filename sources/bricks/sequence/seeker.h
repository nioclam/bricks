/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_SEQUENCE_SEEKER_H__
#define __BRICKS_SEQUENCE_SEEKER_H__ 1

#include "cursor.h"

namespace bricks
{

class Keyword;

/**
 * 定位操作接口
 * 职责：使用自定义策略定位到与关键字相关的位置
 */
class Seeker
{
public:
	/**
	 * 定位位置
	 */
	virtual Frozen<Cursor> seek(Keyword *keyword) = 0;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_SEEKER_H__ */

