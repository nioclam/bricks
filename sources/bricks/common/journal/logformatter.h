/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_JOURNAL_LOGFORMATTER_H__
#define __BRICKS_JOURNAL_LOGFORMATTER_H__ 1

#include "../philosopherandplayer.h"

namespace bricks
{

class Log;

/**
 * 格式化日志事件
 */
class LogFormatter
{
public:
	virtual const char *format(Log *event, Chaos *chaos = bricks::this_player->stringPool);
};

}

#endif /* #ifndef __BRICKS_JOURNAL_LOGFORMATTER_H__ */
