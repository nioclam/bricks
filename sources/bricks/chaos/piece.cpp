
#include "piece.h"

using namespace bricks;

size_t Piece::length()
{
    return upperPosition() - lowerPosition();
}
