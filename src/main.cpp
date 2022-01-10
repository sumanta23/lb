#include <iostream>
#include <csignal>
#include <httplib.h>
#include "LeaderBoard/Leaderboard.h"
#include "json.hpp"
#include "log.h"

using namespace std;
using json = nlohmann::json;
using namespace httplib;

Leaderboard lb;
Server svr;

void signalHandler( int signum ) {
  WARN("Interrupt signal ("<< signum <<") received. stopping server");
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
    cout << user << point << endl;
    string result = to_string(lb.getScore(user));
    res.set_content(result, "text/plain");
  });

  svr.Get("/hi/", [](const Request& req, Response& res) {
		INFO("request "<< req.method <<" "<<req.path <<" from " <<req.remote_addr<<":"<<req.remote_port);
    res.set_content("Hello World!", "text/plain");
  });

  DEBUG("starting server on 1234 port");
  svr.listen("0.0.0.0", 1234);
}
