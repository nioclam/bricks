/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include "stacklist.h"

using namespace bricks;

StackList::StackList()
    : m_singularity()
{
}

void StackList::push(Node *node)
{
    m_singularity.link(node);
}

Node *StackList::pop()
{
    return m_singularity.drop();
}
