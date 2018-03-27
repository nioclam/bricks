/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#include "keyword.h"
#include "hint.h"

using namespace bricks;

bool Keyword::operator <= (Hint *hint)
{
	return !operator > (hint);
}

bool Keyword::operator >= (Hint *hint)
{
	return !operator < (hint);
}

bool Keyword::operator != (Hint *hint)
{
	return !operator == (hint);
}
