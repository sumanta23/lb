#include <iostream>
#include <httplib.h>
#include "LeaderBoard/Leaderboard.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

//g++ -I./third/ -std=c++11 -Wall -Wextra -pthread test.cpp -o test

Leaderboard lb;

int main(void)
{
  using namespace httplib;

  Server svr;

  svr.Post("/hi/", [](const Request& req, Response& res) {
		cout << req.body<< endl;
    auto j = json::parse(res);
    auto user = j["user"];
    auto point = std::stoi(j["point"]);
	  lb.addScore(3, 9);
    res.set_content("Success", "text/plain");
  });

  svr.Get("/hi/", [](const Request& req, Response& res) {
    res.set_content("Hello World!", "text/plain");
  });

  svr.listen("0.0.0.0", 1234);
}
