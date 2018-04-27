/**
 * MIT License
 * Copyright (C) 2018, Coin Lam.
 */
#include <cstdio>
#include <cstring>
#include "../chaos.h"
#include "../journal.h"
#include "player.h"

using namespace bricks;

thread_local Player *bricks::this_player = nullptr;
thread_local FixedStack       t_stringPool;
//thread_local DefaultJournal   t_journal;

/**
 * 主(线程)玩家
 */
Player g_mainPlayer("bricks");

Player::Player(const char *familyName)
    : std::thread()
    , stringPool(&t_stringPool)
    , journal(nullptr)
{
    bricks::this_player = this;
    snprintf(m_name, sizeof(m_name), "%s#%d", familyName, get_id());
}

Player::Player(const char *familyName, Player *that)
    : std::thread()
    , stringPool(that->stringPool)
    , journal(that->journal)
{
    bricks::this_player = this;
    snprintf(m_name, sizeof(m_name), "%s#%d", familyName, get_id());
}

Player::Player(const char *familyName, std::function<void()> game)
    : std::thread(&Player::play, this, game)
    , stringPool(nullptr)
    , journal(nullptr)
{
    strncpy(m_name, familyName, sizeof(m_name));
}

const char *Player::whoami(Chaos *chaos)
{
    return m_name;
}

void Player::play(std::function<void()> game)
{
    bricks::this_player = this;

    stringPool = &t_stringPool;
    journal    = nullptr;
    snprintf(m_name, sizeof(m_name), "%s#%d", m_name, get_id());

    game();
}
