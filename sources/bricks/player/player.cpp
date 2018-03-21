/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include <cstdio>
#include <cstring>
#include <stdexecpt>
#include <bricks/chaos.h>
#include <bricks/journal.h>
#include <bricks/objectpool.h>
#include "player.h"

using namespace bricks;

thread_local Player *bricks::this_player = nullptr;
thread_local FixedStack       t_stringPool;
thread_local ObjectPoolRouter t_objectPool;
thread_local DefaultJournal   t_journal;

/**
 * 主(线程)玩家
 */
Player g_mainPlayer("bricks");

Player::Player(const char *familyName)
    : std::thread()
    , stringPool(&t_stringPool)
    , objectPool(&t_objectPool)
    , journal(&t_journal)
{
    bricks::this_player = this;
    snprintf(m_name, sizeof(m_name), "%s#%d", familyName, get_id());
}

Player::Player(const char *familyName, Player *that)
    : std::thread()
    , stringPool(that->stringPool)
    , objectPool(that->objectPool)
    , journal(that->journal)
    , m_familyName(familyName)
{
    bricks::this_player = this;
    snprintf(m_name, sizeof(m_name), "%s#%d", familyName, get_id());
}

Player::Player(const char *familyName, std::function<void()> game)
    : std::thread(&Player::play, this, game)
    , stringPool(nullptr)
    , objectPool(nullptr)
    , journal(nullptr)
{
    strncpy(m_name, familyName, sizeof(m_name));
}

char *Player::whoami(Chaos *chaos)
{
    return m_name;
}

void Player::play(std::function<void()> game)
{
    bricks::this_player = this;

    stringPool = &t_stringPool;
    objectPool = &t_objectPool;
    journal    = &t_journal;
    snprintf(m_name, sizeof(m_name), "%s#%d", m_name, get_id());

    game();
}
