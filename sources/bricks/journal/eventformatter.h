/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_JOURNAL_EVENTFORMATTER_H__
#define __BRICKS_JOURNAL_EVENTFORMATTER_H__ 1

#include "event.h"

namespace bricks
{

/**
 * 格式化事件
 */
class EventFormatter
{
public:
	/**
	 * 格式化事件
	 * @param event 待格式化的事件
	 * @param
	 */
	virtual Chunk &format(Event *event);
};

}

#endif /* #ifndef __BRICKS_JOURNAL_EVENTFORMATTER_H__ */
