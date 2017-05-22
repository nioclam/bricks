/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_OBJECT_OBJECTPAGE_H__
#define __BRICKS_OBJECT_OBJECTPAGE_H__ 1

#include "objecthost.h"

namespace bricks_objectpool
{

/**
 * 对象页
 */
template<int HostSize, int NumberHostOfPage = (8192 / HostSize)>
class ObjectPage
{
public:
	ObjectPage()
		: m_nextPage(NULL)
		, m_nextHost(0)
	{
	}

	ObjectHost<HostSize> *nextHost()
	{
		if (m_nextHost < NumberHostOfPage)
		{
			return m_page + m_nextHost++;
		}

		return NULL;
	}

public:
	ObjectPage<HostSize, NumberHostOfPage> *m_nextPage;
	ObjectHost<HostSize>                    m_page[NumberHostOfPage];
	int                                     m_nextHost;
};

} // namespace bricks_objectpool

#endif /* #ifndef __BRICKS_OBJECT_OBJECTPAGE_H__ */

