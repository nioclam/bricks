#include "fixedpiece.h"

using namespace bricks;

FixedPiece::FixedPiece(FixedStack *chaos)
    : m_chaos(chaos)
{
}

size_t FixedPiece::lowerPosition()
{
    return 0;
}

size_t FixedPiece::upperPosition()
{
    return m_chaos->size();
}

byte_t *FixedPiece::data()
{
    return m_chaos->stack();
}

Chaos *FixedPiece::chaos()
{
    return m_chaos;
}

bool FixedPiece::moveNext()
{
    return false;
}

bool FixedPiece::movePrev()
{
    return false;
}
