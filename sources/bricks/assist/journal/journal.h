/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_JOURNAL_JOURNAL_H__
#define __BRICKS_JOURNAL_JOURNAL_H__ 1

/**
 * 好记性不如烂笔头
 */
/**
 * Log的字符串类型是char *，字符编码使用UTF-8
 * Journal将Log写入日志，根据实际需要决定如何处理Log，例如：
 *   - 写入到文件（与LogFormatter共同觉得使用何种字符编码）
 *   - 发送到日志服务（推荐使用UTF-8编码，这也是Log使用UTF-8的原因）
 *   - 脑洞
 */

#include <cstdarg>

namespace bricks
{

class Log;

/**
 * 日志
 */
class Journal
{
public:
	/**
	 * 将事件写入日志
	 */
	virtual void write(Log *log) = 0;
};

}

#endif /* #ifndef __BRICKS_JOURNAL_JOURNAL_H__ */
