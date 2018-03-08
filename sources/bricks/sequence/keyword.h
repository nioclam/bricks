/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_SEQUENCE_KEYWORD_H__
#define __BRICKS_SEQUENCE_KEYWORD_H__ 1

#include <bricks/object/object.h>

namespace bricks
{

class Hint;
class HintFactory;
class KeywordFactory;

/**
 * 关键字：决定序列元素的顺序；协助完成定位和搜索操作。
 */
class Keyword : public ObjectPoolAdapter
{
public:
	/**
	 * 判断关键字是否小于成员元素
	 */
	virtual bool operator < (Hint *hint) = 0;

	/**
	 * 判断关键字是否大于成员元素
	 */
	virtual bool operator > (Hint *hint) = 0;

	/**
	 * 判断关键字是否等于成员元素
	 */
	virtual bool operator == (Hint *hint) = 0;

	/**
	 * 判断关键字是否小于等于成员元素
	 */
	virtual bool operator <= (Hint *hint);

	/**
	 * 判断关键字是否大于等于成员元素
	 */
	virtual bool operator >= (Hint *hint);

	/**
	 * 判断关键字是否不等于成员元素
	 */
	virtual bool operator != (Hint *hint);

protected:
	friend class KeywordFactory;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_KEYWORD_H__ */

