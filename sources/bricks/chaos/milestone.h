/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_CHAOS_MILESTONE_H__
#define __BRICKS_CHAOS_MILESTONE_H__ 1

namespace bricks
{

class Chaos;
class Milestone
{
public:
    /**
     * 根据当前进度，返回下一个里程碑
     * 由里程碑决定混乱程度（Chaos的capacity）
     */
    virtual size_t next(size_t progress, Chaos *chaos) = 0;
};

}

#endif /* #ifndef __BRICKS_CHAOS_MILESTONE_H__ */
