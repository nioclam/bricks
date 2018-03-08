/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_SEQUENCE_CURSORFACTORY_H__
#define __BRICKS_SEQUENCE_CURSORFACTORY_H__ 1

#include <bricks/resource/resource.h>
#include "cursor.h"

namespace bricks
{

class Sequence;
class Element;

/**
 * 游标工厂
 */
class CursorFactory : public Releasable<Cursor>
					, public Cloneable<Cursor>
{
public:
	/**
	 * @see Releasable<Cursor>
	 */
	virtual Frozen<Cursor> make(Cursor *cursor);

public:
	/**
	 * 《前置约束》
	 * prev和next相邻
	 *
	 * 创建指向@prev和@next之间的位置的游标
	 *
	 * @return    * 成功，返回游标指针
	 *         NULL 失败
	 */
	virtual Frozen<Cursor> make(Element *prev, Element *next, Sequence *sequence);
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_CURSORFACTORY_H__ */

