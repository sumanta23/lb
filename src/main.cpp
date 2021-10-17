#include <iostream>
#include "LeaderBoard/Leaderboard.h"
using namespace std;

int main() 
{
	std::cout << "Hello, World!\n" << std::endl;
    Leaderboard lb;
    lb.addScore(2, 5);
    lb.addScore(4, 1);
    lb.addScore(3, 9);
    lb.printLB();
    return 0;
}
