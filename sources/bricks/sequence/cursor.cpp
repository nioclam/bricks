/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#include <bricks/toolkit/bricks.h>
#include "cursor.h"
#include "sequence.h"

using namespace bricks;

Cursor::Cursor(Element *prev, Element *next, Sequence *sequence)
	: m_prevHint()
	, m_nextHint()
{
	if (-1 == m_prevHint.unfreeze(sequence->hint(prev))
			|| -1 == m_nextHint.unfreeze(sequence->hint(next)))
	{
		throw std::bad_alloc();
	}
}

Cursor::Cursor(Frozen<Hint> &&prevHint, Frozen<Hint> &&nextHint, Sequence *sequence)
	: m_prevHint()
	, m_nextHint()
{
	if (-1 == m_prevHint.unfreeze(std::move(prevHint))
			|| -1 == m_nextHint.unfreeze(std::move(nextHint)))
	{
		throw std::bad_alloc();
	}
}

Cursor::Cursor(Cursor &that)
{
	Sequence    *sequence    = that.sequence();
	HintFactory *hintFactory = sequence->hintFactory();

	if (-1 == m_prevHint.unfreeze(hintFactory->make(that.prevHint())))
	{
		throw std::bad_alloc();
	}

	if (-1 == m_nextHint.unfreeze(hintFactory->make(that.nextHint())))
	{
		throw std::bad_alloc();
	}
}

bool Cursor::isFirst()
{
	return m_prevHint->isSingular();
}

bool Cursor::isFinal()
{
	return m_nextHint->isSingular();
}

Hint *Cursor::prevHint()
{
	return m_prevHint;
}

Hint *Cursor::nextHint()
{
	return m_nextHint;
}

Element *Cursor::prevElement()
{
	return m_prevHint->element();
}

Element *Cursor::nextElement()
{
	return m_nextHint->element();
}

Sequence *Cursor::sequence()
{
	return m_prevHint->sequence();
}

void Cursor::movePrev()
{
	if (m_prevHint->expired())
	{
		Bricks()->error("Cursor::movePrev : expired\n");
		moveFirst();
	}
	else
	{
		if (!m_prevHint->isSingular())
		{
			m_prevHint->movePrev();
			m_nextHint->movePrev();
		}
	}
}

void Cursor::moveNext()
{
	if (m_nextHint->expired())
	{
		Bricks()->error("Cursor::moveNext : expired\n");
		moveFinal();
	}
	else
	{
		if (!m_nextHint->isSingular())
		{
			m_prevHint->moveNext();
			m_nextHint->moveNext();
		}
	}
}

void Cursor::moveFirst()
{
	m_prevHint->stop();
	m_nextHint->stop();
	m_nextHint->moveNext();
}

void Cursor::moveFinal()
{
	m_prevHint->stop();
	m_nextHint->stop();
	m_prevHint->movePrev();
}
