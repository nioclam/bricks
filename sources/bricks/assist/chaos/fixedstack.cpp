#include <stdio.h>
#include "fixedstack.h"
#include "fixedpiece.h"

using namespace bricks;

FixedStack::FixedStack(size_t capacity)
    : m_stack(new byte_t[capacity])
    , m_capacity(capacity)
    , m_size(0)
{
}

FixedStack::~FixedStack()
{
    delete[] m_stack;
}

size_t FixedStack::size()
{
    return m_size;
}

int FixedStack::expand(size_t size)
{
    if (m_size + size > m_capacity)
    {
        fprintf(stderr, "FixedStack#size(%d)::expand(%d)", m_size, size);
        return -1;
    }

    m_size += size;
    return 0;
}

int FixedStack::forget(size_t position)
{
    return 0;
}

int FixedStack::truncate(size_t position)
{
    if (position > m_size)
    {
        fprintf(stderr, "FixedStack#size(%d)::truncate(%d)", m_size, position);
        return -1;
    }

    m_size = position;
    return 0;
}

Evil<Piece> FixedStack::locate(int position)
{
    return std::move(Evil<Piece>(new FixedPiece(this)));
}
