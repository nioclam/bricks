/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_SEQUENCE_CURSOR_H__
#define __BRICKS_SEQUENCE_CURSOR_H__ 1

#include <bricks/object/object.h>
#include "hint.h"

namespace bricks
{

class Sequence;
class Element;
class CursorFactory;

/**
 * 游标
 *
 * 《备注》
 * 游标用于迭代序列，一般如下使用：
 * for (
 * 			// init cursor;
 * 			!cursor->isFinal(); // !cursor->isFirst()
 * 			cursor->moveNext()) // cursor->movePrev()
 * {
 * 		// do something
 * }
 *
 * 游标基于索引实现，参看索引的迭代规则。
 */
class Cursor : public ObjectPoolAdapter
{
protected:
	Cursor(Element *prevElement, Element *nextElement, Sequence *sequence);
	Cursor(Frozen<Hint> &&prevHint, Frozen<Hint> &&nextHint, Sequence *sequence);
	Cursor(Cursor &that);

public:
	/**
	 * 判断游标是否指向开始位置
	 */
	bool isFirst();

	/**
	 * 判断游标是否指向结束位置
	 */
	bool isFinal();

	/**
	 * 获取前导索引，开始位置的前导索引是奇异索引
	 *
	 * @return * 总是成功
	 */
	Hint *prevHint();

	/**
	 * 获取后续索引，结束位置的后续索引是奇异索引
	 *
	 * @return * 总是成功
	 */
	Hint *nextHint();

	/**
	 * 获取前导元素
	 * @return 若是开始位置，返回奇点；否则，返回元素
	 */
	Element *prevElement();

	/**
	 * 获取后续元素
	 * @return 若是结束位置，返回奇点；否则，返回元素
	 */
	Element *nextElement();

	/**
	 * 获取游标所在的序列
	 */
	Sequence *sequence();

	/**
	 * 移动到前导位置。若游标指向开始位置，保持游标位置不动
	 *
	 * 《备注》
	 * 若发生错误（一般是因为过期），锁定游标（isFirst和isFinal总是返回true）
	 */
	virtual void movePrev();

	/**
	 * 移动到后续位置。若游标指向结束位置，保持游标位置不动
	 *
	 * 《备注》
	 * 若发生错误（一般是因为过期），锁定游标（isFirst和isFinal总是返回true）
	 */
	virtual void moveNext();

	/**
	 * 移动到开始位置
	 */
	virtual void moveFirst();

	/**
	 * 移动到结束位置
	 */
	virtual void moveFinal();

protected:
	Stupid<Hint> m_prevHint;
	Stupid<Hint> m_nextHint;

protected:
	friend class CursorFactory;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_CURSOR_H__ */

