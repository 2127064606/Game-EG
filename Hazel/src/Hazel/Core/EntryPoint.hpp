#pragma once

#ifdef WINDOWS
#include <Hazel/Core/Log.hpp>
#include <GLFW/glfw3.h>

extern Hazel::Application * Hazel::CreateApplication();



int main(int argc, char **argv)
{
    //解决中文乱码问题
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Hazel::Log::Init();
    HAZEL_CORE_INFO("Engine Initialized!");
    int a = 10;
    HAZEL_CLIENT_INFO("Client Initialized! a = {}", a);
    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}

#endif