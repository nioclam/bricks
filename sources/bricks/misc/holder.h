/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_MISC_HOLDER_H__
#define __BRICKS_MISC_HOLDER_H__ 1

namespace bricks
{

/**
 * 数据持有者：只持有数据，不管理数据的生命周期
 */
template <typename DataType>
class Holder
{
public:
	Holder()
		: m_data()
	{
	}

	Holder(DataType data)
		: m_data(data)
	{
	}

public:
	/**
	 * 获取数据
	 */
	DataType data() const
	{
		return m_data;
	}

	/**
	 * 设置数据
	 *
	 * @return 旧的数据
	 */
	DataType hold(DataType data)
	{
		DataType backup = DataType();

		backup = m_data;
		m_data = data;

		return backup;
	}

protected:
	DataType m_data;
};

}

#endif /* #ifndef __BRICKS_MISC_HOLDER_H__ */
