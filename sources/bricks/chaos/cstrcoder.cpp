/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
 #include "cstrcoder.h"
 #include <cstrio>
 #include <cstrarg>

CStrCoder::CStrCoder(Chaos *chaos, size_t position, Milestone *milestone = singleton<DefaultMilestone>())
    : Coder(chaos, position, milestone)
{
    if (-1 == plan(position + 1))
    {
        throw std::bad_alloc();
    }

    // 预留一个位置放置'\0'
    m_upper = position + 1;
}

int CStrCoder::format(const char *base, ...)
{
    va_list vl;
    va_start(vl, base);

    auto length = vsprintf(nullptr, base, vl);

    if (-1 == plan(m_upper + length))
    {
        va_end(vl);
        return -1;
    }

    vsprintf(tail(), base, vl);
    m_upper += size;

    va_end(vl);
}

char *CStrCoder::cstr()
{
    auto str = this->code();

    str[m_upper - 1] = '\0';
    return str;
}
