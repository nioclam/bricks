/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_SEQUENCE_DETACHER_H__
#define __BRICKS_SEQUENCE_DETACHER_H__ 1

namespace bricks
{

class Element;

/**
 * 分离操作接口
 * 职责：使用自定义策略从序列中分离出元素
 */
class Detacher
{
public:
	/**
	 * 分离元素
	 *
	 * @return  0 成功
	 *         -1 失败
	 */
	virtual int detach(Element *element) = 0;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_DETACHER_H__ */

