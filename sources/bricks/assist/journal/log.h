/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_JOURNAL_LOG_H__
#define __BRICKS_JOURNAL_LOG_H__ 1

/**
 * 人在做天在看
 */

#include <chrono>
#include "whylog.h"

namespace bricks
{

class Journal;

/**
 * 日志事件
 *
 * 约定：
 * - 字符集使用Unicode，字符编码使用UTF-8
 * - Journal不能缓存Log，Log一般是栈对象
 * - who, what, where使用常量字符串或者this_player::StringPool，由调用者保证在Log析构前可用
 */
class Log
{
public:
	/**
	 * 构造函数
	 *
	 * @param what  日志事件描述；
	 * @param where 位置；参考值："__file__:__line__"
	 */
	Log(WhyLog why, const char *where);
	~Log();

public:
	WhyLog why();
	const char *reason();
	const char *who();
	const char *what();
	const char *where();
	std::chrono::system_clock::time_point &when();

	/**
	 * 记录发生了什么事情
	 */
	void operator()(const char *what, ...);

protected:
	WhyLog      m_why;
	const char *m_who;
	const char *m_what;
	const char *m_where;
	std::chrono::system_clock::time_point m_when;
};

}

#endif /* #ifndef __BRICKS_JOURNAL_LOG_H__ */
