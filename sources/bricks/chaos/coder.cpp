/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
 #include "coder.h"
 #include "chaos.h"

using namespace bricks;

Coder::Coder(Chaos *chaos)
    : m_chaos(chaos)
    , m_position(m_chaos->size())
{
}

byte_t *Coder::source()
{
    return m_chaos->access(m_position).first;
}
