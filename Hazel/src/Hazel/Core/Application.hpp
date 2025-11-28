#pragma once
#include <Hazel/Core.hpp>
#include <iostream>
#include <Hazel/Core/Window.hpp>
#include <Hazel/Core/LayerStack.hpp>

namespace Hazel {
    #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    class HAZEL_API Application {
        public:
            Application();
            virtual~Application() = default;
            void OnEvent(Event& e);
            void Run();
            bool OnWindowClosed(const class WindowClosedEvent& e);
            bool OnWindowResized(const class WindowResizedEvent& e);
            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlayer);

        private:
            std::unique_ptr<Window> m_Window;
            bool m_Running;
            LayerStack m_LayerStack;

           
    };
     Application* CreateApplication();
      
}