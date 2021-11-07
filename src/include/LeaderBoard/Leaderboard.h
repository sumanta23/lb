#include <bits/stdc++.h>


class Leaderboard
{
public:
    Leaderboard();

    void addScore(int playerId, int score);

    void printLB();

    int top(int K);

    void reset(int playerId);

    int rank(int playerId);

private:
    std::unordered_map<int, int> lookup_;
};