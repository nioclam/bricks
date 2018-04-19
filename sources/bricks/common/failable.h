/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_COMMON_FAILABLE_H__
#define __BRICKS_COMMON_FAILABLE_H__ 1

namespace bricks
{

/**
 * 失败乃成功之母
 * 基类：可以失败的
 */
class Failable
{
public:
	Failable();

public:
	/**
	 * 获取失败状态
	 *
	 * @return true  已经失败
	 *         false 没有失败
	 */
	bool failed();

	/**
	 * 更新失败状态
	 *
	 * @return true  已经失败
	 *         false 没有失败
	 */
	bool failAs(bool failed);

	/**
	 * 重置失败状态
	 *
	 * 吸取教训，重新出发
	 */
	void learnALesson();

protected:
	bool m_failed;
};

}

#endif /* #ifndef __BRICKS_COMMON_FAILABLE_H__ */
