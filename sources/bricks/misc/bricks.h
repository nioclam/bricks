/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_TOOLKIT_BRICKS_H__
#define __BRICKS_TOOLKIT_BRICKS_H__ 1

#include "bricksconfig.h"

namespace bricks
{

class Bricks
{
public:
	static Bricks *operator()();

public:
	// Mask for config journal
	enum
	{
		Fatal   = 0x0001,
		Error   = 0x0002,
		Warning = 0x0004,
		Track   = 0x0008,
		Debug   = 0x0010,
	};

protected:
	/**
	 * 只能调用bricks()获取唯一实例
	 */
	Bricks();

public:
	void fatal(const char *fmt, ...) const;
	void fatal(const char *fmt, va_list va) const;
	void error(const char *fmt, ...) const;
	void error(const char *fmt, va_list va) const;
	void warning(const char *fmt, ...) const;
	void warning(const char *fmt, va_list va) const;
	void track(const char *fmt, ...) const;
	void track(const char *fmt, va_list va) const;
	void debug(const char *fmt, ...) const;
	void debug(const char *fmt, va_list va) const;

protected:
	Journal *m_fatal;
	Journal *m_error;
	Journal *m_warning;
	Journal *m_track;
	Journal *m_debug;

protected:
	friend class BricksConfig;
};

}

#endif /* #ifndef __BRICKS_TOOLKIT_BRICKS_H__ */

