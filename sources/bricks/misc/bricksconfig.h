/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_TOOLKIT_BRICKSCONFIG_H__
#define __BRICKS_TOOLKIT_BRICKSCONFIG_H__ 1

namespace bricks
{

class Journal;

class BricksConfig
{
public:
	static BricksConfig *operator()();

protected:
	/**
	 * 只能调用bricks()获取唯一实例
	 */
	BricksConfig();

public:
    BricksConfig *operator()(Journal *journal, int mask);
};

}

#endif /* #ifndef __BRICKS_TOOLKIT_BRICKSCONFIG_H__ */

