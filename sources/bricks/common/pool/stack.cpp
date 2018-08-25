/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "stack.h"

using namespace bricks;

Stack::Stack()
    : m_singularity()
{
}

Stack::Stack(Duck *head)
    : m_singularity(head)
{
}

void Stack::hire(Duck *duck)
{
    m_singularity.link(duck);
}

Duck *Stack::fire()
{
    return m_singularity.drop();
}

Duck *Stack::head()
{
    return m_singularity.m_next;
}
