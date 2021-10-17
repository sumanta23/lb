#include "Leaderboard.h"

Leaderboard::Leaderboard()
{
}

void Leaderboard::addScore(int playerId, int score)
{
    lookup_[playerId] += score;
}

int Leaderboard::top(int K)
{
    return 0;
}

void Leaderboard::reset(int playerId)
{
    lookup_[playerId] = 0;
}
