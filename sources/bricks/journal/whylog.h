/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_JOURNAL_WHYLOG_H__
#define __BRICKS_JOURNAL_WHYLOG_H__ 1

namespace bricks
{

enum WhyLog
{
    For_Error,
    For_Warning,
    For_Message,
    For_Track,
};

const char *logReason(WhyLog why);

}

#endif /* #ifndef __BRICKS_JOURNAL_WHYLOG_H__ */
