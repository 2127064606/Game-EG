#pragma once


#ifdef WINDOWS
#ifdef HAZEL_BUILD_API
#define HAZEL_API __declspec(dllexport)
#else
#define HAZEL_API __declspec(dllimport)
#endif
#else
#error "Hazel engine only supports Windows"
#endif

#define BIT(x) (1 << x)
