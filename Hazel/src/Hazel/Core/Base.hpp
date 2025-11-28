#pragma once

#include <memory>
#include <Hazel/Core/PlatformDetection.hpp>

#ifdef HAZEL_DEBUG
    #if defined(WINDOWS)
        #define HAZEL_DEBUG_CALL __debugbreak()
    #else
        #error "Debugging is not supported on this platform"
    #endif
    #define HAZEL_ENABLE_ASSERTS
#else
    #define HAZEL_DEBUG_CALL
#endif

#define HAZEL_EXPAND(x) x
#define HAZEL_STRINGIFY(x) #x

#define BIT(x) (1 << x)


#define HAZEL_BIND_EVENT_FN(fn) [this](auto&& ...args) -> decltype(auto) { this->fn(std::forward<decltype(args)>(args)...) }

namespace Hazel{
    template<typename T>
        using Scope = std::unique_ptr<T>;
        template<typename T, typename ...Args>
        constexpr Scope<T> CreateScope(Args&& ...args){
            return std::make_unique<T>(std::forward<Args>(args)...)
        }

        template<typename T>
        using Ref = std::shared_ptr<T>;
        template<typename T, typename ...Args>
        constexpr Ref<T> CreateRef(Args&& ...args){
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
}

#include <Hazel/Core/Log.hpp>

