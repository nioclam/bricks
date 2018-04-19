/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
#ifndef __BRICKS_AZRAEL_AZRAEL_H__
#define __BRICKS_AZRAEL_AZRAEL_H__ 1

#include "defaultfreer.h"
#include "azraelwings.h"

/**
 * 只要灵魂存在，死亡就一直如影随影，直到解脱
 */

namespace bricks
{

/**
 * 死神
 * 掌管灵魂的生死
 *
 * 场景：
 *   - 分配的内存必须释放，且仅释放一次
 *   - 打开的文件必须关闭，且仅关闭一次
 *   - 增加的引用计数必须减少，且仅减少一次
 *   ...
 *
 * 故事一：
 *   一个被恶魔禁锢的灵魂产生；
 *   死神拯救了这个灵魂，后来，灵魂堕落了（恶魔？返回值？）；
 *   另一个死神拯救了这个灵魂，后来，灵魂又堕落了（恶魔？参数？）；
 *   另一个死神拯救了这个灵魂，后来，灵魂又堕落了（地狱？容器？）；
 *   ...
 *   另一个死神拯救了这个灵魂，最终，死亡到来，死神解脱这个灵魂。
 *
 * 故事二：
 *   一个死神
 *   loop
 *   {
 *     一个被恶魔禁锢的灵魂产生
 *     死神解脱旧的灵魂（如果存在），并且拯救新的灵魂；
 *     // do somthing
 *   }
 *   死神解脱最后一个灵魂
 *
 * 在不同场景套用这些故事，可以保证所有灵魂都获得解脱。
 */
template <typename Soul, typename Freer = DefaultFreer, typename Entity = Soul>
class Azrael : public AzraelWings<Soul, Freer>
{
public:
    /**
     * 构造一个死神，用于拯救灵魂
     */
    Azrael()
    {
    }

	Azrael(const Azrael &that)            = delete;
	Azrael &operator=(const Azrael &that) = delete;

public:
    /**
     * 获取灵魂实体
     */
    Entity *soul()
    {
        return static_cast<Entity *>(AzraelWings<Soul, Freer>::m_unique.get());
    }

    Entity *operator->()
    {
        return soul();
    }
};

}

#endif /* #ifndef __BRICKS_AZRAEL_AZRAEL_H__ */
