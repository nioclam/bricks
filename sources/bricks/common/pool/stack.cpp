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

Stack::Stack(Node *head)
    : m_singularity(head)
{
}

void Stack::hire(Node *node)
{
    m_singularity.link(node);
}

Node *Stack::fire()
{
    return m_singularity.drop();
}
