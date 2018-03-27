/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_SEQUENCE_HINT_H__
#define __BRICKS_SEQUENCE_HINT_H__ 1

#include <bricks/resource/resource.h>
#include <bricks/object/object.h>

namespace bricks
{

class Sequence;
class Element;
class HintFactory;
class Cursor;

/**
 * 索引
 *
 * 《备注》
 * 索引用于迭代序列，一般如下使用：
 * for (
 * 			// init hint;
 * 			!hint->isSingular();
 * 			hint->moveNext())
 * {
 * 		// do something
 * }
 */
class Hint : public ObjectPoolAdapter
{
protected:
	/**
	 * 构造索引，使索引指向元素@element
	 */
	Hint(Element *element, Sequence *sequence);

	/**
	 * 拷贝构造索引
	 */
	Hint(Hint &that);

public:
	/**
	 * 判断索引是否是奇异的（指向奇点）
	 */
	bool isSingular();

	/**
	 * 获取索引的元素
	 * @return 若索引是奇异的，返回奇点；否则，返回成员索引的元素
	 */
	Element *element();

	/**
	 * 获取索引所在的序列
	 */
	Sequence *sequence();

	/**
	 * 向前移动索引
	 * 若索引指向奇点，移动后指向尾元素
	 * 若索引指向首元素，移动后指向奇点
	 * 若索引已经过期，停止索引
	 */
	void movePrev();

	/**
	 * 向后移动索引
	 * 若索引指向奇点，移动后指向首元素
	 * 若索引指向尾元素，移动后指向奇点
	 * 若索引已经过期，停止索引
	 */
	void moveNext();

	/**
	 * 停止索引，将索引置指向奇点，并且同步sequence()::m_revision
	 */
	void stop();

protected:
	/**
	 * 向后移动索引
	 */
	virtual void movePrevHint() = 0;

	/**
	 * 向后移动索引
	 */
	virtual void moveNextHint() = 0;

	/**
	 * 判断是否过期
	 */
	bool expired();

protected:
	Element  *m_element;
	Sequence *m_sequence;
	int       m_revision;

protected:
	friend class HintFactory;
	friend class Cursor;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_HINT_H__ */
