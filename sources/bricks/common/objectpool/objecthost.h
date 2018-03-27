/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */
#ifndef __BRICKS_OBJECT_OBJECTHOST_H__
#define __BRICKS_OBJECT_OBJECTHOST_H__ 1

#include <cassert>

namespace bricks_objectpool
{

/**
 * 对象宿主
 *
 * 《约束》
 * sizeof(ObjectHost) > sizeof(Object)
 * 0 == HostSize mod sizeof(UnitType)
 */
template<int HostSize, typename UnitType = int>
class ObjectHost
{
public:
	ObjectHost()
		: m_nextHost(NULL)
	{
		assert( 0 == HostSize % sizeof(UnitType) );
	}

public:
	union
	{
		ObjectHost<HostSize> *m_nextHost;
		UnitType              m_host[HostSize / sizeof(UnitType)];
	};
};

} // namespace bricks_objectpool

#endif /* #ifndef __BRICKS_OBJECT_OBJECTHOST_H__ */

