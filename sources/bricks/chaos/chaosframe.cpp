/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
 #include "chaosframe.h"
 #include "chaos.h"

ChaosFrame::ChaosFrame(Chaos *chaos)
    : m_chaos(chaos)
    , m_position(chaos->size())
{
}

ChaosFrame::~ChaosFrame()
{
    m_chaos->forget(m_position);
}
