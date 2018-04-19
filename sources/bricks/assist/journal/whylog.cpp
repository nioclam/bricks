/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "whylog.h"

const char *bricks::logReason(WhyLog why)
{
    switch (why)
    {
    case For_Error:
        return "Error";
    case For_Warning:
        return "Warning";
    case For_Message:
        return "Message";
    case For_Track:
        return "Track";
    }

    return "Unknown";
}
