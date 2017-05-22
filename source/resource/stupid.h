/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_STUPID_H__
#define __BRICKS_RESOURCE_STUPID_H__ 1

#include "stupidmethod.h"

namespace bricks
{

template <typename VirtualResource, typename Object = VirtualResource>
class Stupid : public StupidMethod<VirtualResource, Object>
{
public:
    Stupid()
        : StupidMethod<VirtualResource, Object>()
    {
    }

    Stupid(Object *resource)
        : StupidMethod<VirtualResource, Object>(resource, singleton<Releasable<VirtualResource>>())
    {
    }
    
	Stupid(Object *resource, Releasable<VirtualResource> *releaser)
        : StupidMethod<VirtualResource, Object>(resource, releaser)
    {
    }
};

}

#endif /* #ifndef __BRICKS_RESOURCE_STUPID_H__ */
