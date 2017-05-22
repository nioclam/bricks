/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_REFERENCERELEASER_H__
#define __BRICKS_RESOURCE_REFERENCERELEASER_H__ 1

#include "../misc/bricks.h"
#include "releasable.h"
#include "stupid.h"

namespace bricks
{

class ReferenceReleaser : public Releasable<Reference>
{
public:
    /**
     * @see Releasable<Reference>
     */
    virtual void *release(Reference *reference);
};

template <typename Object>
class Stupid<Reference, Object> : public StupidMethod<Reference, Object>
{
public:
    Stupid()
        : StupidMethod<Reference, Object>(singleton<ReferenceReleaser>())
    {
    }

    Stupid(Object *reference)
        : StupidMethod<Reference, Object>(reference, singleton<ReferenceReleaser>())
    {
    }
};

}

#endif /* #ifndef __BRICKS_RESOURCE_REFERENCERELEASER_H__ */
