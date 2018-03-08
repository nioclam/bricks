/**
 * MIT License
 * Copyright (C) 2016, Coin Lam.
 */

#include "singularity.h"

using namespace bricks;

Singularity::Singularity()
{
}

bool Singularity::inSequence()
{
	return true;
}

bool Singularity::isSingular()
{
	return true;
}

Element *Singularity::getSingularity()
{
	return this;
}

