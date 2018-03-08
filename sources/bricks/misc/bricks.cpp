/**
 * MIT License
 * Copyright (C) 2016, Coin Lam.
 */
#include <cstddef>
#include "bricks.h"

using namespace bricks;

Bricks *Bricks::operator()()
{
    return singleton<Bricks>();
}

Bricks::Bricks()
    : m_fatal(NULL)
    , m_error(NULL)
    , m_warning(NULL)
    , m_track(NULL)
    , m_debug(NULL)
{
    BricksConfig()
        (singleton<Journal>(), Bricks::Fatal | Bricks::Error | Bricks::Warning);
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

