/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_OBJECT_OBJECTHOST_H__
#define __BRICKS_OBJECT_OBJECTHOST_H__ 1

#include <new>
#include <bricks/common.h>
#include "objectpool.h"
#include "objectunit.h"
#include "objectpage.h"

namespace bricks
{

/**
 * 对象池实现
 */
template<int Multi, int BaseSize, int Alignment>
class ObjectHost : public ObjectPool
{
public:
    typedef ObjectUnit<Multi, BaseSize>            Unit;
    typedef ObjectPage<Multi, BaseSize, Alignment> Page;

public:
	ObjectHost()
        : m_units()
        , m_pages()
	{
	}

	~ObjectHost()
	{
        Page *page = nullptr;

        while (nullptr != (page = (Page *)m_pages.fire()))
        {
            delete page;
        }
	}

	virtual void *hire(void *object)
	{
        m_units.hire((Unit *)object);
		return NULL;
	}

	virtual void *fire()
	{
		Unit *unit = NULL;

		if (nullptr != (unit = (Unit *)m_units.fire()))
		{
            if (nullptr == (unit = hirePage()))
            {
                return nullptr;
            }
		}

		return unit;
	}

    Unit *hirePage()
    {
        Page *page = new(std::nothrow) Page();

        if (nullptr == page)
        {
            return nullptr;
        }

        page->setPool(this);
        m_pages.hire(page);
        m_units.hire(page->head(), page->tail());

        return page->once();
    }

public:
    LockFreeStack m_units;
    LockFreeStack m_pages;
};

} // namespace bricks_objectpool

#endif /* #ifndef __BRICKS_OBJECT_OBJECTHOST_H__ */
