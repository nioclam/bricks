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

Stack::Stack(Resource *head)
    : m_singularity(head)
{
}

void Stack::hire(Resource *resource)
{
    m_singularity.link(resource);
}

Resource *Stack::fire()
{
    return m_singularity.drop();
}
