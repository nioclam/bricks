/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */
#ifndef __BRICKS_OBJECTPOOL_OBJECTUNIT_H__
#define __BRICKS_OBJECTPOOL_OBJECTUNIT_H__ 1

#include <bricks/common.h>

namespace bricks
{

/**
 * 对象宿主
 *
 * 《约束》
 * sizeof(ObjectUnit) > sizeof(Object)
 */
template<int Multi, int BaseSize>
class ObjectUnit : public Duck
{
public:
	ObjectUnit()
		: Duck()
	{
	}

public:
	char m_pad[Multi * BaseSize - sizeof(Duck)];
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECTPOOL_OBJECTUNIT_H__ */
