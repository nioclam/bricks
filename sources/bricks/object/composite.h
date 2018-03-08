/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */
#ifndef __BRICKS_OBJECT_COMPOSITE_H__
#define __BRICKS_OBJECT_COMPOSITE_H__ 1

namespace bricks
{

/**
 * 复合对象
 *
 *      [混沌状态]             ：未分配内存
 *         |  /|\
 *       make release
 *        \|/  |
 *       [未定义]<-------+     ：已分配内存，未初始化。即未分配复合对象直接管理的内存
 *         |  /|\        |
 *     [init] [term]    [term]
 *        \|/  |         |
 *       [初始化]        |     ：已分配复合对象直接管理的内存以及初始化（按实现需要可以延迟分配）
 *            /|\        |
 *             cleanup   |
 *             |         |
 *       [自定义]--------+     ：用户定义状态
 *
 * 《作用》
 * 1. 实现复合对象内存池，优化复合对象直接管理的内存的使用效率；
 * 2. 默认的成员元素的析构顺序与构造顺序相反，复合对象提供自定义析构顺序的能力；
 */
class Composite
{
public:
	/**
	 * 使复合对象从自定义状态回到初始化状态：重置成员元素为初始值（不释放复合对象直接管理的内存）。
	 */
	virtual void cleanup() = 0;
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECT_COMPOSITE_H__ */

