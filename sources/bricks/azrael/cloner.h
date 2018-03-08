/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_CLONER_H__
#define __BRICKS_AZRAEL_CLONER_H__ 1

#include "evil.h"

namespace bricks
{

/**
 * 接口：恶灵复制者
 */
template <class Soul, Freer = DefaultFreer>
class Cloner
{
public:
	/**
	 * 复制
	 */
	virtual Evil<Soul, Freer> make(Soul *soul) = 0;
};

}

#endif /* #ifndef __BRICKS_AZRAEL_CLONER_H__ */
