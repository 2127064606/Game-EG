#include <Platform/Windows/WindowsWindow.hpp>
#include <Hazel/Log.hpp>
#include <Hazel/Event/ApplicationEvent.hpp>
#include <Hazel/Event/KeyEvent.hpp>
#include <Hazel/Event/MouseEvent.hpp>

namespace Hazel{
    static uint8_t s_GLFWWindowCount = 0;
    WindowsWindow::WindowsWindow(const WindowProps& props){
        Init(props);
    }

    void WindowsWindow::Init(const WindowProps& props){
        m_Data.Title = props.Title;
        m_Data.Width = props.width;
        m_Data.Height = props.height;
        
        HAZEL_CORE_INFO("Creating window {} ({}, {})", props.Title, props.width, props.height);

        if(s_GLFWWindowCount == 0){
           int success =  glfwInit();
           glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
           glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
           glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
           glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        }
      

        m_Window = glfwCreateWindow(props.width, props.height, props.Title.c_str(), nullptr, nullptr);
        if(!m_Window){
            HAZEL_CORE_ERROR("Failed to create window!");
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(m_Window);
           // 在窗口创建后、使用 OpenGL 函数前添加
      if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            HAZEL_CORE_ERROR("Failed to load OpenGL function pointers!");
            glfwTerminate();
            return;
        }
        ++s_GLFWWindowCount;
        //设置窗口用户指针
        glfwSetWindowUserPointer(m_Window, &m_Data);

        SetVSync(true);
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height){
          void *userPointer = glfwGetWindowUserPointer(window);
          if(!userPointer){
            HAZEL_CORE_ERROR("Window user pointer is null!");
            return;
          }
            WindowData& data = *(WindowData*)userPointer;
            
            data.Width = width;
            data.Height = height;
            WindowResizedEvent e(width, height);
            data.EventCallback(e);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window){
             void *userPointer = glfwGetWindowUserPointer(window);
          if(!userPointer){
            HAZEL_CORE_ERROR("Window user pointer is null!");
            return;
          }
            WindowData& data = *(WindowData*)userPointer;
            WindowClosedEvent e;
            data.EventCallback(e);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
             void *userPointer = glfwGetWindowUserPointer(window);
          if(!userPointer){
            HAZEL_CORE_ERROR("Window user pointer is null!");
            return;
          }
           WindowData& data = *(WindowData*)userPointer;
           switch(action){
            case GLFW_PRESS:
            {
                KeyPressedEvent e(((KeyCode)key));
                data.EventCallback(e);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent e(((KeyCode)key));
                data.EventCallback(e);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent e(((KeyCode)key), true);
                data.EventCallback(e);
                break;
            }
           }
        });
        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode){
             void *userPointer = glfwGetWindowUserPointer(window);
          if(!userPointer){
            HAZEL_CORE_ERROR("Window user pointer is null!");
            return;
          }
           WindowData& data = *(WindowData*)userPointer;
           KeyTypedEvent e((KeyCode)keycode);
           data.EventCallback(e);
        });
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods){
             void *userPointer = glfwGetWindowUserPointer(window);
          if(!userPointer){
            HAZEL_CORE_ERROR("Window user pointer is null!");
            return;
          }
           WindowData& data = *(WindowData*)userPointer;
            switch(action){
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent e((MouseCode)button);
                    data.EventCallback(e);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent e((MouseCode)button);
                    data.EventCallback(e);
                    break;
                }
            }
        });
        glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xPos, int yPos){
             void *userPointer = glfwGetWindowUserPointer(window);
          if(!userPointer){
            HAZEL_CORE_ERROR("Window user pointer is null!");
            return;
          }
           WindowData& data = *(WindowData*)userPointer;
           WindowMovedEvent e(xPos, yPos);
           data.EventCallback(e);
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset){
             void *userPointer = glfwGetWindowUserPointer(window);
          if(!userPointer){
            HAZEL_CORE_ERROR("Window user pointer is null!");
            return;
          }
           WindowData& data = *(WindowData*)userPointer;
           MouseScrolledEvent e((float)xOffset, (float)yOffset);
           data.EventCallback(e);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos){
             void *userPointer = glfwGetWindowUserPointer(window);
          if(!userPointer){
            HAZEL_CORE_ERROR("Window user pointer is null!");
            return;
          }
           WindowData& data = *(WindowData*)userPointer;
           MouseMovedEvent e((float)xPos, (float)yPos);
           data.EventCallback(e);
        });
    }

    void WindowsWindow::Shutdown(){
        glfwDestroyWindow(m_Window);
        --s_GLFWWindowCount;
        if(s_GLFWWindowCount == 0){
            glfwTerminate();
        }
        HAZEL_CORE_INFO("Destroyed window {} ({}, {})", m_Data.Title, m_Data.Width, m_Data.Height);
    }

    void WindowsWindow::OnUpdate(){
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled){
        if(enabled){
            glfwSwapInterval(1);
        }
        else{
            glfwSwapInterval(0);
        }
        m_Data.VSync = enabled;
    }

    WindowsWindow::~WindowsWindow(){
        Shutdown();
    }
}