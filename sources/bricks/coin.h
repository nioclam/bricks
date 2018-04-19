/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */
#ifndef __BRICKS_COIN_H__
#define __BRICKS_COIN_H__ 1

namespace bricks
{

/**
 * 硬币总有正反两面
 * 接口：在正反两种类型之间转换
 */
template <typename Obverse, typename Reverse>
class Coin
{
public:
	/**
	 * 获取对立面（从正面获得反面）
	 *
	 * @return    * 成功
	 *         NULL 失败
	 */
	virtual Reverse *getOpposite(Obverse *object);

	/**
	 * 获取对立面（从反面获得正面）
	 *
	 * @return    * 成功
	 *         NULL 失败
	 */
	virtual Obverse *getOpposite(Reverse *object);
};

}

#endif /* #ifndef __BRICKS_COIN_H__ */
