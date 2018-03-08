/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_SEQUENCE_SEQUENCE_H__
#define __BRICKS_SEQUENCE_SEQUENCE_H__ 1

#include "element.h"
#include "singularity.h"
#include "hint.h"
#include "hintfactory.h"
#include "cursor.h"
#include "cursorfactory.h"
#include "keyword.h"
#include "keywordfactory.h"
#include "finder.h"
#include "seeker.h"
#include "attacher.h"
#include "detacher.h"
#include "visitor.h"
#include "traverser.h"

namespace bricks
{

/**
 * 道生一，一生二，二生三，三生万物
 *
 * 序列（Sequence）是一个全序集合，形如：
 *
 *     hint
 *      |
 *      V
 * singularity | 0 | 1 | 2 | ... | n | singularity
 *            /\
 *            |
 *          cursor
 *
 * 序列可以通过游标遍历，有两种游标：
 *   1.hint（索引）：直接指向元素
 *   2.cursor（位置）：指向相邻两个元素的边界
 *
 * [元素]
 * 0、1、2、...、n称为（序列的）（普通）元素（Element）；
 * 元素0称为首元素；
 * 元素n称为尾元素；
 * singularity是奇点，是序列的特殊元素，代表序列自身
 * singularity连接首尾元素，使序列成为一个环
 * P.S. 首尾各出现一个singularity，实际上是同一个
 *
 * [索引]
 * 序列以奇点连接形成一个环，索引可以在这个环内循环移动，一般在遇到起点时停止；
 *
 * [位置]
 * 位于位置前面的元素称为（位置的）前导元素（getPrevMember）；
 * 位于位置后面的元素称为（位置的）后续元素（getNextMember）；
 * 位于元素前面的位置称为（元素的）前导位置（prevCursor）；
 * 位于元素后面的位置称为（元素的）后续位置（nextCursor）；
 *
 * 奇点的后续位置称为起始位置，
 * 奇点的前导位置成为结束位置；
 * 特别地，在空序列中，起始位置和结束位置重叠；
 */
class Sequence
{
public:
	Sequence(HintFactory *hintFactory, CursorFactory *cursorFactory);

public:
	/**
	 * 判断是否为空序列
	 */
	virtual bool empty() = 0;

	/**
	 * 判断是否包含元素
	 */
	virtual bool membership(Element *element) = 0;

	/**
	 * 获取奇点
	 */
	virtual Element *singularity() = 0;

	/**
	 * 获取奇异索引（指向奇点）
	 */
	virtual Frozen<Hint> hint();

	/**
	 * 获取元素索引
	 */
	virtual Frozen<Hint> hint(Element *element);

	/**
	 * 获取起始位置
	 */
	virtual Frozen<Cursor> nextCursor() = 0;

	/**
	 * 获取元素的后续位置
	 */
	virtual Frozen<Cursor> nextCursor(Element *element) = 0;

	/**
	 * 获取结束位置
	 */
	virtual Frozen<Cursor> prevCursor() = 0;

	/**
	 * 获取元素的前导位置
	 */
	virtual Frozen<Cursor> prevCursor(Element *element) = 0;

	/**
	 * 获取元素索引工厂
	 */
	HintFactory *hintFactory();

	/**
	 * 获取游标工厂
	 */
	CursorFactory *cursorFactory();

	/**
	 * 获取序列的版本号
	 */
	int revision();

protected:
	HintFactory   *m_hintFactory;
	CursorFactory *m_cursorFactory;
	int            m_revision;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_SEQUENCE_H__ */
