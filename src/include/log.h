#pragma once
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <chrono>
#include <cstdio>
#include <limits>
#include <sstream>

#include "spdlog/async.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/spdlog.h"

static void initLogging()
{
    spdlog::init_thread_pool(8192, 1);
    spdlog::flush_every(std::chrono::seconds(1));
    spdlog::set_level(spdlog::level::info);

    const char *progname = "samlb";
    std::string logsPath = std::string(std::getenv("PROJECT_HOME")) + "/logs/";
    logsPath += std::string(progname) + "_" + std::to_string(getpid()) + ".log";
    auto async_file = spdlog::rotating_logger_mt<spdlog::async_factory>(progname, logsPath.c_str(), 10*1024*1024, std::numeric_limits<size_t>::max());
    spdlog::set_default_logger(async_file);
}

#define INFO(msg) \
    do { \
        std::ostringstream s; \
        s << msg; \
        SPDLOG_INFO(s.str().c_str()); \
    } while(0);

#define WARN(msg) \
    do { \
        std::ostringstream s; \
        s << msg; \
        SPDLOG_WARN(s.str().c_str()); \
    } while(0);

#define DEBUG(msg) \
    do { \
        std::ostringstream s; \
        s << msg; \
        SPDLOG_DEBUG(s.str().c_str()); \
    } while(0);

#define ERROR(msg) \
    do { \
        std::ostringstream s; \
        s << msg; \
        SPDLOG_ERROR(s.str().c_str()); \
    } while(0);

