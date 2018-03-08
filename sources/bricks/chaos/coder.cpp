/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
 #include "coder.h"
 #include "chaos.h"

Coder::Coder(Chaos *chaos, size_t position, Milestone *milestone)
    : m_milestone(milestone)
    , m_chaos(chaos)
    , m_lowerPosition(position)
    , m_upperPosition(position)
{
}

byte_t *Coder::code()
{
    auto code   = m_chaos->access(m_lowerPosition);
    code.second = size();

    return code;
}

size_t Coder::size()
{
    return m_upperPosition - m_lowerPosition;
}

size_t Coder::lowerPosition()
{
    return m_lowerPosition;
}

size_t Coder::upperPosition()
{
    return m_upperPosition;
}

int Coder::plan(size_t progress)
{
    return m_chaos->expand(m_milestone->next(progress)))
}
