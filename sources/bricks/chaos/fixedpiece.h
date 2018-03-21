/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_FIXEDPIECE_H__
#define __BRICKS_CHAOS_FIXEDPIECE_H__ 1

#include "piece.h"

namespace bricks
{

class FixedStack;

class FixedPiece : public Piece
{
public:
    FixedPiece(FixedStack *chaos);

public:
    virtual size_t lowerPosition();
    virtual size_t upperPosition();
    virtual byte_t *data();
    virtual Chaos *chaos();
    virtual bool moveNext();
    virtual bool movePrev();

protected:
    FixedStack *m_chaos;
};

}

#endif /* #ifndef __BRICKS_CHAOS_FIXEDPIECE_H__ */
