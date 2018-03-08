/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_SEQUENCE_TRAVERSER_H__
#define __BRICKS_SEQUENCE_TRAVERSER_H__ 1

namespace bricks
{

class Visitor;

/**
 * 遍历操作接口
 * 职责：使用访问操作接口访问元素
 */
class Traverser
{
public:
	/**
	 * 遍历元素
	 *
	 * @return  0 成功（遍历所有成员元素或者停止访问）
	 *         -1 失败
	 */
	virtual int traverse(Visitor *visitor) = 0;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_TRAVERSER_H__ */

