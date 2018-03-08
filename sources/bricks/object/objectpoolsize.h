/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_OBJECT_OBJECTPOOLSIZE_H__
#define __BRICKS_OBJECT_OBJECTPOOLSIZE_H__ 1

#include "objecthost.h"
#include "objectpage.h"
#include "objectpool.h"

namespace bricks_objectpool
{

/**
 * 对象池实现
 */
template<int HostSize>
class ObjectPoolSize : public bricks::ObjectPool
{
public:
	ObjectPoolSize()
		: m_nextHost(NULL)
		, m_nextPage(NULL)
	{
	}

	~ObjectPoolSize()
	{
		ObjectPage<HostSize> *page = NULL;
		ObjectPage<HostSize> *next = NULL;

		for (
				next = m_nextPage;
				NULL != next;
				)
		{
			page = next;
			next = next->m_nextPage;

			delete page;
		}
	}

	virtual void *restore()
	{
		ObjectHost<HostSize> *host = NULL;
		ObjectPage<HostSize> *page = NULL;

		if (NULL != m_nextHost)
		{
			host       = m_nextHost;
			m_nextHost = m_nextHost->m_nextHost;

			return host;
		}

		if (NULL == m_nextPage || NULL == (host = m_nextPage->nextHost()))
		{
			if (NULL == (page = new ObjectPage<HostSize>()))
			{
				return NULL;
			}

			page->m_nextPage = m_nextPage;
			m_nextPage       = page;
			host             = m_nextPage->nextHost();
		}

		return host;
	}

	virtual void *discard(void *object)
	{
		ObjectHost<HostSize> *host = NULL;

		host             = static_cast<ObjectHost<HostSize> *>(object);
		host->m_nextHost = m_nextHost;
		m_nextHost       = host;

		return NULL;
	}

public:
	ObjectHost<HostSize> *m_nextHost;
	ObjectPage<HostSize> *m_nextPage;
};

} // namespace bricks_objectpool

#endif /* #ifndef __BRICKS_OBJECT_OBJECTPOOLSIZE_H__ */

