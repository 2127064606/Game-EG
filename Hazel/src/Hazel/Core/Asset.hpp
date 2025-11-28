#pragma once
#include <Hazel/Core/Log.hpp>
#include <Hazel/Core/Base.hpp>


#ifdef  HAZEL_ENABLE_ASSERTS
     #define HAZEL_INTERNAL_ASSERT_IMPL(type, check, msg, ...){ if(!(check)) { HZ##type##ERROR(msg, __VA_ARGS__); HAZEL_DEBUG_CALL(); } }

#endif