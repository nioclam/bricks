/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
 #include "chaosframe.h"
 #include "chaos.h"

using namespace bricks;

ChaosFrame::ChaosFrame(Chaos *chaos)
    : m_chaos(chaos)
    , m_position(chaos->size())
{
}

ChaosFrame::~ChaosFrame()
{
    m_chaos->truncate(m_position);
}
