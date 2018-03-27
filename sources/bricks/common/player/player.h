/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#ifndef __BRICKS_PLAYER_PLAYER_H__
#define __BRICKS_PLAYER_PLAYER_H__ 1

/**
 * 特立独行
 */

#include <thread>
#include <functional>
#include "../chaos.h"
#include "../philosopher.h"

namespace bricks
{

class ObjectPool;
class Journal;

class Player : public std::thread
             , public Philosopher
{
public:
    enum {
        NameSize = 128,
    };

public:
    Player(const char *familyName);
    Player(const char *familyName, Player *that);
    Player(const char *familyName, std::function<void()> game);

public:
    virtual const char *whoami(Chaos *chaos);

protected:
    /**
     * 启动游戏
     */
    void play(std::function<void()> game);

public:
    /**
     * 日志系统使用stringPool组装字符串，因此，stringPool的实现不能输出日志，
     * 否则有可能造成死循环
     */
    Chaos      *stringPool;
    ObjectPool *objectPool;
    Journal    *journal;

protected:
    char m_name[Player::NameSize];
};

extern thread_local Player *this_player;

}

#endif /* #ifndef __BRICKS_PLAYER_PLAYER_H__ */
