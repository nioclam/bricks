/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_MISC_SINGLETON_H__
#define __BRICKS_MISC_SINGLETON_H__ 1

namespace bricks
{

/**
 * 单件：只有无外部状态的类才可以使用单件
 */
template <typename StatelessObject>
StatelessObject *singleton()
{
	static StatelessObject singleton;
	return &singleton;
}

}

#endif /* #ifndef __BRICKS_MISC_SINGLETON_H__ */
