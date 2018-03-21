/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#include <cstdio>
#include <bricks/player.h>
#include "log.h"

using namespace std::chrono;
using namespace bricks;

Log::Log(WhyLog why, const char *where);
	: m_why(why)
	, m_who(whoami(bricks::this_player))
	, m_what(nullptr)
	, m_where(where)
	, m_when(system_clock::now())
{
}

Log::~Log()
{
	bricks::this_player->journal->write(this);
}

WhyLog Log::why()
{
	return m_why;
}

const char *Log::reason()
{
	return logReason(m_why);
}

const char *Log::who()
{
	return m_who;
}

const char *Log::what()
{
	return m_what;
}

const char *Log::where()
{
	return m_where;
}

system_clock::time_point &Log::when()
{
	return m_when;
}

void operator()(const char *what, ...);
