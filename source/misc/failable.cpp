/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
 
#include "failable.h"

using namespace bricks;

Failable::Failable()
	: m_failed(false)
{
}

bool Failable::failed()
{
	return m_failed;
}

bool Failable::failed(bool failed)
{
	if (failed)
	{
		m_failed = true;
	}

	return m_failed;
}

void Failable::ignoreFailed()
{
	m_failed = false;
}
