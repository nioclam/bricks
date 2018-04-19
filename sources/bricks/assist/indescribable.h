/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_ASSIST_INDESCRIBABLE_H__
#define __BRICKS_ASSIST_INDESCRIBABLE_H__ 1

/**
 * 道可道非常道名可名非常名
 */

namespace bricks
{

/**
 * 接口：可描述的
 */
class Indescribable
{
public:
	Indescribable();

public:
	const char *toString(Chaos *stringPool);
};

}

#endif /* #ifndef __BRICKS_ASSIST_INDESCRIBABLE_H__ */
