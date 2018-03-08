/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
 #include <cstdio>
 #include <cstdarg>
 #include "cstrcoder.h"

using namespace bricks;

CStrCoder::CStrCoder(Chaos *chaos)
    : Coder(chaos)
{
}

int CStrCoder::code(const char *format, ...)
{
    size_t  length = 0;
    va_list vl;
    va_start(vl, format);

    length     = vsprintf(nullptr, format, vl);
    m_position = m_chaos->size();

    if (-1 == m_chaos->expand(m_position + length + 1)) // 1 for '\0'
    {
        va_end(vl);
        return -1;
    }

    vsprintf(source(), format, vl);
    va_end(vl);
    return 0;
}

char *CStrCoder::cstr()
{
    return (char *)source();
}
