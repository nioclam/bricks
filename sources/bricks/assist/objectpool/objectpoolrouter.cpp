/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include <bricks/common.h>
#include "objectpoolrouter.h"
#include "objecthost.h"

using namespace bricks;

ObjectPoolRouter::ObjectPoolRouter()
{
}

ObjectPool *ObjectPoolRouter::route(size_t size)
{
	static ObjectPool *map[] =
	{
		new ObjectHost< 1, sizeof(void *), ObjectPoolRouter::Alignment>,
		new ObjectHost< 2, sizeof(void *), ObjectPoolRouter::Alignment>,
		new ObjectHost< 3, sizeof(void *), ObjectPoolRouter::Alignment>,
		new ObjectHost< 5, sizeof(void *), ObjectPoolRouter::Alignment>,
		new ObjectHost< 8, sizeof(void *), ObjectPoolRouter::Alignment>,
		new ObjectHost<13, sizeof(void *), ObjectPoolRouter::Alignment>,
		new ObjectHost<21, sizeof(void *), ObjectPoolRouter::Alignment>,
		new ObjectHost<34, sizeof(void *), ObjectPoolRouter::Alignment>,
		new ObjectHost<55, sizeof(void *), ObjectPoolRouter::Alignment>,
		new ObjectHost<89, sizeof(void *), ObjectPoolRouter::Alignment>,
	};

    static int toIndex[] =
    {
        0, 0, 1, 2, 3, 3, 4, 4,
        4, 5, 5, 5, 5, 5, 6, 6,
        6, 6, 6, 6, 6, 6, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9,
        9, 9
    };

	size_t multi = ceiling(size, sizeof(void *));

    if (multi < sizeof(toIndex) / sizeof(toIndex[0]))
    {
        return map[toIndex[multi]];
    }

	return NULL;
}
