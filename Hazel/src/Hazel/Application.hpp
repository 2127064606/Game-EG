#pragma once
#include <Hazel/Core.hpp>
#include <iostream>
#include <Hazel/Window.hpp>

namespace Hazel {
    #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    class HAZEL_API Application {
        public:
            Application();
            virtual~Application() = default;
            void OnEvent(Event& e);
            void Run();
            bool OnWindowClosed(const class WindowClosedEvent& e);

        private:
            std::unique_ptr<Window> m_Window;
            bool m_Running;
           
    };
     Application* CreateApplication();
      
}