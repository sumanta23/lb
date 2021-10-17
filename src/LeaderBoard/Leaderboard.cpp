#include "Leaderboard.h"

Leaderboard::Leaderboard()
{
}

void Leaderboard::printLB()
{
    for (const auto& [key, value] : lookup_) {
        std::cout << key << " = " << value << std::endl;
    }
    std::cout << "\n";
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
