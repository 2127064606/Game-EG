#pragma once
#include <spdlog/spdlog.h>
#include <memory>
#include <Hazel/Core.hpp>

namespace Hazel
{
    class HAZEL_API Log
    {
    public:
        Log() {};
        ~Log() {};
        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
        static void Init();

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}
    // Core Log
#define HAZEL_CORE_INFO(...) Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HAZEL_CORE_WARN(...) Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HAZEL_CORE_ERROR(...) Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HAZEL_CORE_CRITICAL(...) Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define HAZEL_CORE_FATAL(...) Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define HAZEL_CORE_TRACE(...) Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client Log
#define HAZEL_CLIENT_INFO(...) Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HAZEL_CLIENT_WARN(...) Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HAZEL_CLIENT_ERROR(...) Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HAZEL_CLIENT_CRITICAL(...) Hazel::Log::GetClientLogger()->critical(__VA_ARGS__)
#define HAZEL_CLIENT_FATAL(...) Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define HAZEL_CLIENT_TRACE(...) Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
