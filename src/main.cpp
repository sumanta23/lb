#include <iostream>
#include <csignal>
#include <httplib.h>
#include "LeaderBoard/Leaderboard.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;
using namespace httplib;

Leaderboard lb;
Server svr;

void signalHandler( int signum ) {
  cout << "Interrupt signal (" << signum << ") received.\n";
  svr.stop();
  exit(signum);
}

int main(void)
{
  signal(SIGINT, signalHandler);

  svr.Post("/hi/", [](const Request& req, Response& res) {
    const char * body = req.body.c_str();
    cout << body << endl;
    auto j = json::parse(body);
    string user = j["user"].get<std::string>();;
    int point = j["point"].get<int>();;
    lb.addScore(user, point);
    res.set_content(to_string(lb.getScore(user)), "text/plain");
    res.set_content(user, "text/plain");
  });

  svr.Get("/hi/", [](const Request& req, Response& res) {
    res.set_content("Hello World!", "text/plain");
  });

  svr.listen("0.0.0.0", 1234);
}
