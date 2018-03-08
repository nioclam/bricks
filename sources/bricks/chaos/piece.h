/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_PIECE_H__
#define __BRICKS_CHAOS_PIECE_H__ 1

#include "byte.h"

namespace bricks
{

class Chaos;

/**
 * 碎片
 */
class Piece
{
public:
    /**
     * 在世界中的起始位置
     */
    virtual size_t lowerPosition() = 0;

    /**
     * 在世界中的结束位置
     */
    virtual size_t upperPosition() = 0;

    /**
     * 长度
     */
    virtual size_t length();

    /**
     * 内存块的起始地址
     */
    virtual byte_t *data() = 0;

    /**
     * 混乱的世界
     */
    virtual Chaos *chaos() = 0;

    /**
     * 移动到后一个碎片
     */
    virtual bool moveNext() = 0;

    /**
     * 移动到前一个碎片
     */
    virtual bool movePrev() = 0;
};

}

#endif /* #ifndef __BRICKS_CHAOS_PIECE_H__ */
