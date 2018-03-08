/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_SEQUENCE_ATTACHER_H__
#define __BRICKS_SEQUENCE_ATTACHER_H__ 1

namespace bricks
{

class Element;

/**
 * 附加操作接口
 * 职责：使用自定义策略将元素附加到序列中
 */
class Attacher
{
public:
	/**
	 * 附加元素
	 *
	 * @return  0 成功
	 *         -1 失败
	 */
	virtual int attach(Element *element) = 0;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_ATTACHER_H__ */

