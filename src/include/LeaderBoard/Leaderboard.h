#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Leaderboard
{
public:
    Leaderboard();

    void addScore(string playerId, int score);
    int getScore(string playerId);

    void printLB();

    int top(int K);

    void reset(string playerId);

    int rank(string playerId);

private:
    std::unordered_map<string, int> lookup_;
};