/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOSTOOLKIT_STRINGCODER_H__
#define __BRICKS_CHAOSTOOLKIT_STRINGCODER_H__ 1

#include "coder.h"

namespace bricks
{

class StringCoder : public Coder
{
public:
    StringCoder(Chaos *chaos);

public:
    int code(const char *format, ...);
    char *string();
};

}

#endif /* #ifndef __BRICKS_CHAOSTOOLKIT_STRINGCODER_H__ */
