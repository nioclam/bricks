/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#include <cstdio>
#include "journal.h"

using namespace bricks;

Journal::Journal()
{
}

void Journal::log(const char *fmt, ...)
{
	va_list va;

	va_start(va, fmt);
	log(fmt, va);
	va_end(va);
}

void Journal::log(const char *fmt, va_list va)
{
	vprintf(fmt, va);
}

