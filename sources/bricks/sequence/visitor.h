/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_SEQUENCE_VISITOR_H__
#define __BRICKS_SEQUENCE_VISITOR_H__ 1

#include "hint.h"

namespace bricks
{

/**
 * 访问操作接口
 * 职责：使用自定义策略访问员元（一般与遍历操作接口配合）
 */
class Visitor : public Failable
{
public:
	/**
	 * 访问成员元素
	 *
	 * @return  true 继续遍历
	 *         false 停止遍历，若发生错误，应该停止遍历
	 *
	 * 《前置约束》
	 * 1. 索引必须指向成员元素；
	 * 2. 允许销毁索引的成员元素；
	 */
	virtual bool visit(Hint *hint) = 0;
};

}

#endif /* #ifndef __BRICKS_SEQUENCE_VISITOR_H__ */

