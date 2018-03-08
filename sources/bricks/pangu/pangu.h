/**
 * MIT License
 * Copyright (C) 2017, Coin Lam.
 */
 #ifndef __BRICKS_PANGU_PANGU_H__
 #define __BRICKS_PANGU_PANGU_H__ 1

 /**
  * 盘古开天辟地
  */

 namespace bricks
 {

template <typename OrderType, typename ChaosType = Chaos*>
class Pangu : public Order
{
public:
    virtual OrderType makeEpoch(ChaosType chaos) = 0;
};

 }

 #endif /* #ifndef __BRICKS_PANGU_PANGU_H__ */
