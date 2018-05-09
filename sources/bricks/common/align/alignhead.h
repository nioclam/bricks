/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_ALIGN_ALIGNHEAD_H__
#define __BRICKS_ALIGN_ALIGNHEAD_H__ 1

#include "../secret.h"

namespace bricks
{

template <typename Reserved>
class AlignHead : public Reserved
                , public Secret
{
};

}

#endif /* #ifndef __BRICKS_ALIGN_ALIGNHEAD_H__ */
