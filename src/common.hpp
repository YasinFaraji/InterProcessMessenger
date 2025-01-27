#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

constexpr int MAX_COUNT = 10;

class Logger
{
  public:
    static Logger& instance()
    {
        static Logger logger;
        return logger;
    }

    void log(const std::string& message)
    {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

        std::ostringstream oss;
        oss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S") 
            << '.' << std::setfill('0') 
            << std::setw(3) 
            << milliseconds.count() 
            << " [LOG] "
            << message;

        spdlog::info(oss.str());
        fileLogger_->info(oss.str());
    }

  private:
    Logger()
    {
        consoleLogger_ = spdlog::stdout_color_mt("console");
        consoleLogger_->set_level(spdlog::level::debug);

        fileLogger_ = spdlog::basic_logger_mt("file_logger", "log.txt");
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
    }

    std::shared_ptr<spdlog::logger> fileLogger_;
    std::shared_ptr<spdlog::logger> consoleLogger_;
};

inline void log(const std::string& message)
{
    Logger::instance().log(message);
}

#endif // COMMON_HPP
