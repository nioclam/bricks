/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_AZRAELWINGS_H__
#define __BRICKS_AZRAEL_AZRAELWINGS_H__ 1

#include <stdexcept>
#include <memory>
#include "evil.h"

namespace bricks
{

/**
 * 死神之翼
 */
template <typename Soul, typename Freer>
class AzraelWings
{
public:
	AzraelWings()
		: m_unique()
	{
	}

	~AzraelWings()
	{
		destroy();
	}

	AzraelWings(const AzraelWings &that)            = delete;
	AzraelWings &operator=(const AzraelWings &that) = delete;

public:
	/**
	 * 堕落为恶灵
	 */
	Evil<Soul, Freer> fallen()
	{
		return std::move(Evil<Soul, Freer>(release()));
	}

	/**
	 * 拯救灵魂
	 */
	int redeem(Evil<Soul, Freer> &&evil)
	{
		m_unique.reset(evil.release()); // implicit destroy

		return (nullptr == m_unique.get()) ? -1 : 0;
	}

protected:
	/**
	 * 灵魂被死神释放。两个结果，一是堕落为恶灵，一是解脱
	 */
	Soul *release()
	{
		return m_unique.release();
	}

	/**
	 * 解脱灵魂
	 */
	void destroy()
	{
		m_unique.reset(nullptr);
	}

protected:
    std::unique_ptr<Soul, Freer> m_unique;
};

// 使用默认Freer
template <typename Soul>
class AzraelWings<Soul, DefaultFreer>
{
public:
	AzraelWings()
		: m_unique()
	{
	}

	~AzraelWings()
	{
		destroy();
	}

	AzraelWings(const AzraelWings &that)            = delete;
	AzraelWings &operator=(const AzraelWings &that) = delete;

public:
	/**
	 * 堕落为恶灵
	 */
	Evil<Soul, DefaultFreer> fallen()
	{
		return std::move(Evil<Soul, DefaultFreer>(release()));
	}

	/**
	 * 拯救灵魂
	 */
	int redeem(Evil<Soul, DefaultFreer> &&evil)
	{
		m_unique.reset(evil.release()); // implicit destroy

		return (nullptr == m_unique.get()) ? -1 : 0;
	}

protected:
	/**
	 * 灵魂被死神释放。两个结果，一是堕落为恶灵，一是解脱
	 */
	Soul *release()
	{
		return m_unique.release();
	}

	/**
	 * 解脱灵魂
	 */
	void destroy()
	{
		m_unique.reset(nullptr);
	}

protected:
    std::unique_ptr<Soul> m_unique;
};

}

#endif /* #ifndef __BRICKS_AZRAEL_AZRAELWINGS_H__ */
