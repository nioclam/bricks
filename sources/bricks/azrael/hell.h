/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_HELL_H__
#define __BRICKS_AZRAEL_HELL_H__ 1

#include <stdexcept>
#include "evil.h"

namespace bricks
{

/**
 * 地狱
 *
 * 用于容器
 */
template <typename Soul, typename Freer = DefaultFreer>
class Hell : public Philosopher
		   , public HellDebugger
{
public:
    Hell(const char *name)
        : m_name(name)
    {
    }

    ~Hell()
    {
    }

public: // 继承自Philosopher
    Buffer whoami()
    {
        return Buffer(u8"Hell[%s]", m_name);
    }

public:
    /**
     * 堕落到地狱
     */
    Soul *goTo(Evil<Soul> evil)
    {
        ++m_count;
        evil.release();
    }

    /**
     * 从地狱归来
     */
    Evil<Soul> goBack(Soul *soul)
    {
        --m_count;
        return Evil<Soul>(soul, m_freer);
    }

protected:
    const char  *m_name;
    int          m_count;
	Freer<Soul> *m_freer;
};

}

#endif /* #ifndef __BRICKS_AZRAEL_HELL_H__ */
