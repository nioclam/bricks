/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_MAKER_H__
#define __BRICKS_AZRAEL_MAKER_H__ 1

/**
 * 未知死焉知生
 */

#include "evil.h"

namespace bricks
{

/**
 * 接口：恶灵制造者
 */
template <typename Soul, typename Freer = DefaultFreer>
class Maker
{
public:
    virtual Evil<Soul, Freer> make() = 0;

public:
	Evil<Soul, Freer> make(Soul *soul)
	{
		return std::move(Evil<Soul, Freer>(soul));
	}
};

}

#endif /* #ifndef __BRICKS_AZRAEL_MAKER_H__ */
