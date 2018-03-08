/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_JOURNAL_JOURNAL_H__
#define __BRICKS_JOURNAL_JOURNAL_H__ 1

/**
 * Event的字符串类型是char *，字符编码使用UTF-8
 * Journal将Event写入日志，根据实际需要决定如何处理Event，例如：
 *   - 用循环队列记录Event（不需要EventFormatter）
 *   - 写入到文件（与EventFormatter共同觉得使用何种字符编码）
 *   - 发送到日志服务（推荐使用UTF-8编码，这也是Event使用UTF-8的原因）
 *   - 脑洞
 */

#include <cstdarg>
#include "event.h"
#include "eventformatter.h"

namespace bricks
{

/**
 * 好记性不如烂笔头
 * 日志
 */
class Journal
{
public:
	/**
	 * 将事件写入日志
	 */
	virtual void log(Event *event) = 0;
};

}

#endif /* #ifndef __BRICKS_JOURNAL_JOURNAL_H__ */
