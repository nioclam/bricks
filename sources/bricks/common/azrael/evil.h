/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_EVIL_H__
#define __BRICKS_AZRAEL_EVIL_H__ 1

#include <memory>
#include "defaultfreer.h"

namespace bricks
{

template<typename Soul, typename DefaultFreer> class AzraelWings;

/**
 * 恶魔 - 禁锢堕落的灵魂
 *
 *
 * 用于在函数间传递灵魂，例如：
 *   - 参数
 *   - 返回值
 */
template <typename Soul, typename Freer = DefaultFreer>
class Evil
{
public:
    Evil()
    {
    }

	Evil(Evil &&that)
	{
		destroy();
		m_unique.reset(that.release());
	}

	~Evil()
	{
		destroy();
	}

	Evil(const Evil &that)            = delete;
	Evil &operator=(const Evil &that) = delete;

	Evil(Soul *soul)
	{
		m_unique.reset(soul);
	}

public:
    /**
     * 获取灵魂
     */
    Soul *soul()
    {
        return static_cast<Soul *>(m_unique.get());
    }

    Soul *operator->() const
    {
        return soul();
    }

protected:
	/**
	 * 灵魂被恶魔释放。只有被拯救的灵魂才能被恶魔释放。
	 */
	Soul *release()
	{
		return m_unique.release();
	}

	/**
	 * 烟消云散
	 */
	void destroy()
	{
		m_unique.reset(nullptr);
	}

protected:
	std::unique_ptr<Soul, Freer> m_unique;

protected:
	friend class AzraelWings<Soul, Freer>;
};

template <typename Soul>
class Evil<Soul, DefaultFreer>
{
public:
    Evil()
    {
    }

	Evil(Evil &&that)
	{
		m_unique.reset(that.release());
	}

	~Evil()
	{
		destroy();
	}

	Evil(const Evil &that)            = delete;
	Evil &operator=(const Evil &that) = delete;

	Evil(Soul *soul)
	{
		m_unique.reset(soul);
	}

public:
    /**
     * 获取灵魂
     */
    Soul *soul()
    {
        return static_cast<Soul *>(m_unique.get());
    }

    Soul *operator->() const
    {
        return soul();
    }

protected:
	/**
	 * 灵魂被恶魔释放。只有被拯救的灵魂才能被恶魔释放。
	 */
	Soul *release()
	{
		return m_unique.release();
	}

	/**
	 * 烟消云散
	 */
	void destroy()
	{
		m_unique.reset(nullptr);
	}

protected:
	std::unique_ptr<Soul> m_unique;

protected:
	friend class AzraelWings<Soul, DefaultFreer>;
};

}

#endif /* #ifndef __BRICKS_AZRAEL_EVIL_H__ */
