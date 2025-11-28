#pragma once


#ifdef _WIN32
    #ifdef _WIN64
        #define WINDOWS
        #define HAZEL_BUILD_API
        #define HAZEL_DEBUG
    #else
        #error "32-bit Windows is not supported"
    #endif
#else 
    #error "Only Windows is supported"
#endif