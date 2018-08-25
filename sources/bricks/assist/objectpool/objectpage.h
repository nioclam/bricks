/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_OBJECTPOOL_OBJECTPAGE_H__
#define __BRICKS_OBJECTPOOL_OBJECTPAGE_H__ 1

#include <bricks/common.h>
#include "objectunit.h"
#include "objectreserved.h"

namespace bricks
{

/**
 * 对象页
 */
template<int Multi, int BaseSize, int Alignment>
class ObjectPage : public AlignStub<ObjectReserved, Alignment>
{
public:
    typedef ObjectUnit<Multi, BaseSize>            Unit;
    typedef ObjectPage<Multi, BaseSize, Alignment> Page;
    typedef AlignStub<ObjectReserved, Alignment>   Stub;

public:
    static const int NumberOfUnits = (Stub::Size / sizeof(Unit));

public:
	ObjectPage()
	{
        int   count = Stub::size() / sizeof(Unit);
        Unit *units = (Unit *)Stub::page();
        Duck *unit  = units + 1;
        Duck *next  = nullptr;

        for (auto i = 2; i < count; ++i)
        {
            next         = units + i;
            unit->m_next = next;
            unit         = next;
        }

        units[0].m_next = nullptr;
	}

    void init(void *page, size_t size)
    {
    }

    Unit *once()
    {
        return (Unit *)Stub::page();
    }

    Unit *head()
    {
        return ((Unit *)Stub::page()) + 1;
    }

    Unit *tail()
    {
        return ((Unit *)Stub::page()) + Page::NumberOfUnits - 1;
    }
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECTPOOL_OBJECTPAGE_H__ */
