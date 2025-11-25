#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Hazel/Application.hpp>
#include <Hazel/Event/ApplicationEvent.hpp>
#include <Hazel/Event/KeyEvent.hpp>
#include <Hazel/Log.hpp>
#include <PreHeader.hpp>




namespace Hazel {
    void Application::Run() {
    //  m_Window = Window::Create();   
     
       while(m_Running){
         glClear(GL_COLOR_BUFFER_BIT);
         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
          m_Window->OnUpdate();
       }
    }

    Application::Application() {
       HAZEL_CORE_INFO("Hazel Engine Initialized!");
       m_Window = Window::Create();
       m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
       m_Running = true;
    }

    void Application::OnEvent(Event& e){
      EventDispatcher disparcher(e);
      //调度事件，返回值为bool，若返回true，则事件被处理
      if(disparcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClosed)));
      HAZEL_CORE_INFO("Event: {0}", e.ToString());
    }

    bool Application::OnWindowClosed(const WindowClosedEvent& e){
      HAZEL_CORE_INFO("_______________________________________________________");
      m_Running = false;
      return true;
    }
}