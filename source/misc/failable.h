/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_MISC_FAILABLE_H__
#define __BRICKS_MISC_FAILABLE_H__ 1

namespace bricks
{

/**
 * 失败乃成功之母
 * 接口：可以失败的
 */
class Failable
{
public:
	Failable();

public:
	/**
	 * 获取失败状态
	 *
	 * @return  true 已经失败
	 *         false 没有失败
	 */
	bool failed();

	/**
	 * 更新然后获取失败状态
	 *
	 * @return  true 已经失败
	 *         false 没有失败
	 */
	bool failed(bool failed);

	/**
	 * 忽略失败状态，重置为正常状态
	 */
	void ignoreFailed();

protected:
	bool m_failed;
};

}

#endif /* #ifndef __BRICKS_MISC_FAILABLE_H__ */
