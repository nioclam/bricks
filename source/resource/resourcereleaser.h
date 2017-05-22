/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_RESOURCERELEASER_H__
#define __BRICKS_RESOURCE_RESOURCERELEASER_H__ 1

#include "../misc/bricks.h"
#include "releasable.h"
#include "stupid.h"

namespace bricks
{

class ResourceReleaser : public Releasable<Resource>
{
public:
    /**
     * @see Releasable<Resource>
     */
    virtual void *release(Resource *resource);
};

template <typename Object>
class Stupid<Resource, Object> : public StupidMethod<Resource, Object>
{
public:
    Stupid()
        : StupidMethod<Resource, Object>(singleton<ResourceReleaser>())
    {
    }

    Stupid(Object *resource)
        : StupidMethod<Resource, Object>(resource, singleton<ResourceReleaser>())
    {
    }
};

}

#endif /* #ifndef __BRICKS_RESOURCE_RESOURCERELEASER_H__ */
