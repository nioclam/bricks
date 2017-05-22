/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */

#ifndef __BRICKS_RESOURCE_REFERENCERESOURCE_H__
#define __BRICKS_RESOURCE_REFERENCERESOURCE_H__ 1

#include "reference.h"
#include "resource.h"

namespace bricks
{

class ReferenceResource : public Reference
                        , public Resource
{
public:
    ReferenceResource();

protected:
    /**
     * @see Reference
     */
    virtual void *onReferenceless();
};

}

#endif /* #ifndef __BRICKS_RESOURCE_REFERENCERESOURCE_H__ */
