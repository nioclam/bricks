/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */

#include "sequence.h"

using namespace bricks;

Sequence::Sequence(HintFactory *hintFactory, CursorFactory *cursorFactory)
	: m_hintFactory(hintFactory)
	, m_cursorFactory(cursorFactory)
	, m_revision(0)
{
	if (NULL == m_hintFactory || NULL == m_cursorFactory)
	{
		throw std::bad_alloc();
	}
}

Frozen<Hint> Sequence::hint()
{
	return m_hintFactory->alloc(this, this->getSingularity());
}

Frozen<Hint> Sequence::hint(Element *element)
{
	return m_hintFactory->alloc(this, element);
}

HintFactory *Sequence::hintFactory()
{
	return m_hintFactory;
}

CursorFactory *Sequence::cursorFactory()
{
	return m_cursorFactory;
}

int Sequence::revision()
{
	return m_revision;
}
