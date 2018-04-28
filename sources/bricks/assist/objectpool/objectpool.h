/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_OBJECTPOOL_OBJECTPOOL_H__
#define __BRICKS_OBJECTPOOL_OBJECTPOOL_H__ 1

namespace bricks
{

/**
 * 对象池接口
 */
class ObjectPool
{
public:
	virtual void *fire() = 0;
	virtual void *hire(void *object) = 0;
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECT_OBJECTPOOL_H__ */
