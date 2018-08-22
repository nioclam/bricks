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
	 * 判断是否已经失败
	 *
	 * @return true  已经失败
	 *         false 没有失败
	 */
	bool isFailed();

	/**
	 * beFailed
	 *
	 * @return true  已经失败
	 *         false 没有失败
	 */
	bool beFailed(bool failed);

	/**
	 * 吸取教训
	 */
	void learnALesson();

protected:
	bool m_failed;
};

}

#endif /* #ifndef __BRICKS_COMMON_FAILABLE_H__ */
