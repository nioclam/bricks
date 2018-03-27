/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_SPIRITFREER_H__
#define __BRICKS_AZRAEL_SPIRITFREER_H__ 1

namespace bricks
{

class Spirit;
class SpiritFreer
{
public:
    void operator()(Spirit *spirit);
};

}

#endif /* #ifndef __BRICKS_AZRAEL_SPIRITFREER_H__ */
