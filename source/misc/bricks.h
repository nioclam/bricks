/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#ifndef __BRICKS_MISC_MISC_H__
#define __BRICKS_MISC_MISC_H__ 1

#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <algorithm>

#include "coin.h"
#include "failable.h"
#include "journal.h"
#include "holder.h"
#include "singleton.h"

namespace bricks
{

class Bricks;

/**
 * 获取Bricks的全局唯一实例
 */
Bricks *bricks();

class Bricks
{
public:
	/**
	 * 只能调用bricks()获取唯一实例
	 */
	Bricks();

public:
	void fatal(const char *fmt, ...);
	void fatal(const char *fmt, va_list va);
	void error(const char *fmt, ...);
	void error(const char *fmt, va_list va);
	void warning(const char *fmt, ...);
	void warning(const char *fmt, va_list va);
	void track(const char *fmt, ...);
	void track(const char *fmt, va_list va);
	void debug(const char *fmt, ...);
	void debug(const char *fmt, va_list va);

public:
	Journal *configFatal(Journal *fatal);
	Journal *configError(Journal *error);
	Journal *configWarning(Journal *warning);
	Journal *configTrack(Journal *track);
	Journal *configDebug(Journal *debug);

protected:
	Journal *m_fatal;
	Journal *m_error;
	Journal *m_warning;
	Journal *m_track;
	Journal *m_debug;
};

}

#endif /* #ifndef __BRICKS_MISC_MISC_H__ */
