#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Hazel/Core/Application.hpp>
#include <Hazel/Event/ApplicationEvent.hpp>
#include <Hazel/Event/KeyEvent.hpp>
#include <Hazel/Core/Log.hpp>
#include <PreHeader.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>



namespace Hazel {
    void Application::Run() {
    //  m_Window = Window::Create();   
     float sliderValue = 0.5f;
       while(m_Running){
         glClear(GL_COLOR_BUFFER_BIT);
         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);    
          
         ImGui_ImplOpenGL3_NewFrame();
         ImGui_ImplGlfw_NewFrame();

         ImGui::NewFrame();

         ImGui::Begin("Hazel Engine");
         ImGui::Text("Hello, World!");
         ImGui::SliderFloat("float", &sliderValue, 0.0f, 1.0f);
         ImGui::Button("Click Me");
         ImGui::End();

         ImGui::Render();
         int display_w, display_h;
         glfwGetFramebufferSize((GLFWwindow*)m_Window->GetNativeWindow(), &display_w, &display_h);
         glViewport(0, 0, display_w, display_h);
        
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        
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
      disparcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClosed));
      disparcher.Dispatch<WindowResizedEvent>(BIND_EVENT_FN(OnWindowResized));

      for(auto it : m_LayerStack){
        if(!e.Handled)
        it->OnEvent(e);
      }
     // HAZEL_CORE_INFO("Event: {0}", e.ToString());
    }

    bool Application::OnWindowClosed(const WindowClosedEvent& e){
      HAZEL_CORE_INFO("_______________________________________________________");
      m_Running = false;
      return true;
    }

    bool Application::OnWindowResized(const WindowResizedEvent& e){
      HAZEL_CORE_INFO("Window Resized: {0} x {1}", e.GetWidth(), e.GetHeight());
      return false;
    }

    void Application::PushLayer(Layer* layer){
      m_LayerStack.PushLayer(layer);
    }
    void Application::PushOverlay(Layer* overlayer){
      m_LayerStack.PushOverlay(overlayer);
    }
}