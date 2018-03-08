/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_REFERENCEFREER_H__
#define __BRICKS_AZRAEL_REFERENCEFREER_H__ 1

namespace bricks
{

class Reference;
class ReferenceFreer
{
public:
    void operator()(Reference *reference);
};

}

#endif /* #ifndef __BRICKS_AZRAEL_REFERENCEFREER_H__ */
