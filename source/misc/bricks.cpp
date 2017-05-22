/**
 * MIT License
 * Copyright (C) 2016, Coin Lam.
 */

#include <cstddef>
#include "bricks.h"

using namespace bricks;

Bricks *bricks::bricks()
{
    static Bricks bricks;

    return &bricks;
}

Bricks::Bricks()
    : m_fatal(singleton<Journal>())
    , m_error(singleton<Journal>())
    , m_warning(NULL)
    , m_track(NULL)
    , m_debug(NULL)
{
}

void Bricks::fatal(const char *fmt, ...)
{
	va_list va;

    if (NULL != m_fatal)
    {
        va_start(va, fmt);
        m_fatal->log(fmt, va);
        va_end(va);
    }
}

void Bricks::fatal(const char *fmt, va_list va)
{
    if (NULL != m_fatal)
    {
        m_fatal->log(fmt, va);
    }
}

void Bricks::error(const char *fmt, ...)
{
	va_list va;

    if (NULL != m_error)
    {
        va_start(va, fmt);
        m_error->log(fmt, va);
        va_end(va);
    }
}

void Bricks::error(const char *fmt, va_list va)
{
    if (NULL != m_error)
    {
        m_error->log(fmt, va);
    }
}

void Bricks::warning(const char *fmt, ...)
{
	va_list va;

    if (NULL != m_warning)
    {
        va_start(va, fmt);
        m_warning->log(fmt, va);
        va_end(va);
    }
}

void Bricks::warning(const char *fmt, va_list va)
{
    if (NULL != m_warning)
    {
        m_warning->log(fmt, va);
    }
}

void Bricks::track(const char *fmt, ...)
{
	va_list va;

    if (NULL != m_track)
    {
        va_start(va, fmt);
        m_track->log(fmt, va);
        va_end(va);
    }
}

void Bricks::track(const char *fmt, va_list va)
{
    if (NULL != m_track)
    {
        m_track->log(fmt, va);
    }
}

void Bricks::debug(const char *fmt, ...)
{
	va_list va;

    if (NULL != m_debug)
    {
        va_start(va, fmt);
        m_debug->log(fmt, va);
        va_end(va);
    }
}

void Bricks::debug(const char *fmt, va_list va)
{
    if (NULL != m_fatal)
    {
        m_fatal->log(fmt, va);
    }
}

Journal *Bricks::configFatal(Journal *fatal)
{
	Journal *backup = NULL;

	backup  = m_fatal;
    m_fatal = fatal;

	return backup;
}

Journal *Bricks::configError(Journal *error)
{
	Journal *backup = NULL;

	backup  = m_error;
    m_error = error;

	return backup;
}

Journal *Bricks::configWarning(Journal *warning)
{
	Journal *backup = NULL;

	backup    = m_warning;
    m_warning = warning;

	return backup;
}

Journal *Bricks::configTrack(Journal *track)
{
	Journal *backup = NULL;

	backup  = m_track;
    m_track = track;

	return backup;
}

Journal *Bricks::configDebug(Journal *debug)
{
	Journal *backup = NULL;

	backup  = m_debug;
    m_debug = debug;

	return backup;
}
