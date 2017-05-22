/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_CLONEABLE_H__
#define __BRICKS_RESOURCE_CLONEABLE_H__ 1

#include "frozen.h"

namespace bricks
{

/**
 * 接口：可以克隆虚拟资源的
 */
template <class VirtualResource>
class Cloneable
{
public:
	/**
	 * 克隆虚拟资源
	 */
	virtual Frozen<VirtualResource> make(VirtualResource *resource) = 0;
};

}

#endif /* #ifndef __BRICKS_RESOURCE_CLONEABLE_H__ */
