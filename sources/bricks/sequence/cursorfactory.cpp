/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#include <bricks/toolkit/bricks.h>
#include "cursorfactory.h"
#include "sequence.h"

using namespace bricks;

Frozen<Cursor> CursorFactory::make(Cursor *cursor)
{
	return make(cursor->prevElement(), cursor->nextElement(), cursor->sequence());
}

Frozen<Cursor> CursorFactory::make(Element *prev, Element *next, Sequence *sequence)
{
	Stupid<Cursor> cursor;

	if (NULL == (cursor = new Cursor(prev, next, sequence)))
	{
		return Frozen<Cursor>();
	}

	return cursor.freeze();
}
