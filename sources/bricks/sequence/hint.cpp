/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#include <bricks/toolkit/bricks.h>
#include "hint.h"
#include "sequence.h"

using namespace bricks;

Hint::Hint(Element *element, Sequence *sequence)
	: m_element(element)
	, m_sequence(sequence)
	, m_revision(0)
{
	if (NULL == m_element || NULL == m_sequence)
	{
		throw std::bad_alloc();
	}

	m_revision = m_sequence->revision();
}

Hint::Hint(Hint &that)
	: m_element(that.m_element)
	, m_sequence(that.m_sequence)
	, m_revision(that.m_revision)
{
}

bool Hint::isSingular()
{
	return m_element->isSingular();
}

Element *Hint::element()
{
	if (expired())
	{
		stop();
	}

	return m_element;
}

Sequence *Hint::sequence()
{
	return m_sequence;
}

void Hint::movePrev()
{
	if (expired())
	{
		Bricks()->error("Hint::movePrev : expired\n");
		stop();
	}
	else
	{
		movePrevHint();
	}
}

void Hint::moveNext()
{
	if (expired())
	{
		Bricks()->error("Hint::moveNext : expired\n");
		stop();
	}
	else
	{
		moveNextHint();
	}
}

void Hint::stop()
{
	m_element  = m_sequence->singularity();
	m_revision = m_sequence->revision();
}

bool Hint::expired()
{
	m_revision != m_sequence->revision();
}
