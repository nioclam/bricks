/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#include "hintFactory.h"
#include "sequence.h"

using namespace bricks;

Frozen<Hint> HintFactory::make(Hint *hint)
{
	return make(hint->element(), hint->sequence());
}

Frozen<Hint> HintFactory::make(Sequence *sequence)
{
	return make(sequence->singularity(), sequence);
}

