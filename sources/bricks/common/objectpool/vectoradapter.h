/**
 * MIT License
 * Copyright (C) 2015, Coin Lam.
 */
#ifndef __BRICKS_OBJECT_VECTORADAPTER_H__
#define __BRICKS_OBJECT_VECTORADAPTER_H__ 1

#include <vector>
#include "compositepooladapter.h"

namespace bricks
{

/**
 * 复合对象池适配器
 */
template <class DataType>
class VectorAdapter : public std::vector<DataType>
					, public CompositePoolAdapter<VectorAdapter<DataType>>
{
public:
	VectorAdapter()
		: std::vector<DataType>()
		, CompositePoolAdapter<VectorAdapter<DataType>>()
	{
	}

public: // 继承自Composite
	virtual void resetObject()
	{
		std::vector<DataType>::clear();
	}
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECT_VECTORADAPTER_H__ */
