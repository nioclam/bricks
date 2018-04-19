/**
 * MIT License
 * Copyright (C) 2014, Coin Lam.
 */
#ifndef __BRICKS_OBJECT_OBJECTPOOL_H__
#define __BRICKS_OBJECT_OBJECTPOOL_H__ 1

namespace bricks
{

/**
 * 对象池接口
 */
class ObjectPool
{
public:
	virtual void *restore() = 0;
	virtual void *discard(void *object) = 0;
};

} // namespace bricks

#endif /* #ifndef __BRICKS_OBJECT_OBJECTPOOL_H__ */
