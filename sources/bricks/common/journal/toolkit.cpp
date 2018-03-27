/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "toolkit.h"

ErrorTool::ErrorTool(const char *where)
    : Log(For_Error, where)
{
}

WarningTool::WarningTool(const char *where)
    : Log(For_Warning, where)
{
}

MessageTool::MessageTool(const char *where)
    : Log(For_Message, where)
{
}

TrackTool::TrackTool(const char *where)
    : Log(For_Track, where)
{
}
