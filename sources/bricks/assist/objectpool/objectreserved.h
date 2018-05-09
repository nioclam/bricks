/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */
#ifndef __BRICKS_OBJECTPOOL_OBJECTRESERVED_H__
#define __BRICKS_OBJECTPOOL_OBJECTRESERVED_H__ 1

#include <bricks/common.h>
#include "objectpool.h"

namespace bricks
{

class ObjectReserved : public Resource
{
public:
	ObjectReserved()
		: Resource()
	{
	}

    void setPool(ObjectPool *pool)
    {
        m_pool = pool;
    }

    ObjectPool *pool()
    {
        return m_pool;
    }

protected:
    ObjectPool *m_pool;
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECTPOOL_OBJECTRESERVED_H__ */
