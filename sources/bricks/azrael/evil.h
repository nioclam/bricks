/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_EVIL_H__
#define __BRICKS_AZRAEL_EVIL_H__ 1

#include <memory>

namespace bricks
{

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
	Evil &operator=(const Evil &that) = delete

protected: // 只有Maker可以制造恶魔
	Evil(Soul *soul)
	{
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
		if (nullptr != m_unique.get())
		{
			Logic(u8"bricks", u8"Evil[%s] said: %s be forgotten!", whoami(this).cstr(), whoami(soul()).cstr());
		}

		m_unique.reset(nullptr);
	}

protected:
	std::unique<Soul, Freer> m_unique;

protected:
	friend class Maker<Soul, Freer>;
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
		destroy();
		m_unique.reset(that.release());
	}

	~Evil()
	{
		destroy();
	}

	Evil(const Evil &that)            = delete;
	Evil &operator=(const Evil &that) = delete

protected: // 只有Maker可以制造恶魔
	Evil(Soul *soul)
	{
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
		if (nullptr != m_unique.get())
		{
			Logic(u8"bricks", u8"Evil[%s] said: %s be forgotten!", whoami(this).cstr(), whoami(soul()).cstr());
		}

		m_unique.reset(nullptr);
	}

protected:
	std::unique<Soul> m_unique;

protected:
	friend class Maker<Soul, DefaultFreer>;
	friend class AzraelWings<Soul, DefaultFreer>;
};

}

#endif /* #ifndef __BRICKS_AZRAEL_EVIL_H__ */
