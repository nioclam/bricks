/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_MISC_JOURNAL_H__
#define __BRICKS_MISC_JOURNAL_H__ 1

#include <cstdarg>

namespace bricks
{

/**
 * 好记性不如烂笔头
 * 日志
 */
class Journal
{
public:
	Journal();

public:
	/**
	 * 记录日志
	 */
	virtual void log(const char *fmt, ...);
	virtual void log(const char *fmt, va_list va);
};

}

#endif /* #ifndef __BRICKS_MISC_JOURNAL_H__ */
