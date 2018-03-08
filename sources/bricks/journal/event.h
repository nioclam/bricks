/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_JOURNAL_EVENT_H__
#define __BRICKS_JOURNAL_EVENT_H__ 1

#include <chrono>
#include <bricks/byte/byte.h>

using namespace std::chrono;

namespace bricks
{

class Journal;

/**
 * 人在做天在看
 *
 * 约定：
 * - 字符集使用Unicode，字符编码使用UTF-8
 * - Journal可能缓存了Event，因此Event析构的时机未定义
 * - why和who使用常量字符串，或者保证Event析构前可用
 * - where和what使用Buffer保存字符串
 * - how需要保证Event析构前可用
 */
class Event
{
public:
	/**
	 * 构造函数
	 *
	 * @param why   类型；参考值："Fatal"、"Error"、"Warning"、"Message"、"Debug"
	 * @param who   模块；参考值："Bricks"
	 * @param where 位置；参考值："__file__:__line__"
	 */
	Event(
		const char *why,
		const char *who,
		Buffer &&where);

	/**
	 * 构造函数
	 *
	 * @param how 指定如何记录事件
	 */
	Event(
		Journal *how,
		const char *why,
		const char *who,
		Buffer &&where);

	/**
	 * 构造函数
	 *
	 * @param what 描述；what的格式化字符串，后面接可变参数
	 */
	Event(
		const char *why,
		const char *who,
		Buffer &&where,
		Buffer &&what);

	/**
	 * 构造函数
	 */
	Event(
		Journal *how,
		const char *why,
		const char *who,
		Buffer &&where,
		Buffer &&what);

	/**
	 * 构造函数
	 *
	 * @param formatWhat 描述；what的格式化字符串，后面接可变参数
	 */
	Event(
		const char *why,
		const char *who,
		Buffer &&where,
		const char *formatWhat, ...);

	/**
	 * 构造函数
	 */
	Event(
		Journal *how,
		const char *why,
		const char *who,
		Buffer &&where,
		const char *formatWhat, ...);

public:
	system_clock::time_point &when();
	char const *why();
	char const *who();
	char const *where();
	char const *what();

protected:
	system_clock::time_point m_when;
	Journal    *m_how;
	const char *m_who;
	const char *m_why;
	Buffer      m_where;
	Buffer      m_what;
};

}

#endif /* #ifndef __BRICKS_JOURNAL_EVENT_H__ */
