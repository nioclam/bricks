/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_REFERENCEFREER_H__
#define __BRICKS_AZRAEL_REFERENCEFREER_H__ 1

#include "reference.h"

namespace bricks
{

class ReferenceFreer
{
public:
    void operator()(Reference *reference);
};

}

#endif /* #ifndef __BRICKS_AZRAEL_REFERENCEFREER_H__ */
