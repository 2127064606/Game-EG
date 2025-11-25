#include <Hazel/Window.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Hazel{
    class WindowsWindow : public Window{
        public:
            WindowsWindow(const WindowProps& props);
            virtual ~WindowsWindow();
            void OnUpdate() override;

            unsigned int GetWidth() const override{ return m_Data.Width; }
            unsigned int GetHeight() const override{ return m_Data.Height; }

            void SetVSync(bool enabled) override;

            bool IsVSync() const override { return m_Data.VSync; }

            void SetEventCallback(const EventCallbackFn& callback) override{ m_Data.EventCallback = callback; }

            virtual void* GetNativeWindow() const override{ return m_Window; }

            bool IsClosed() const override { return glfwWindowShouldClose(m_Window); }

            //初始化窗口
            void Init(const WindowProps& props);
            //关闭窗口
            void Shutdown();
        private:
            GLFWwindow* m_Window;
            struct WindowData{
                std::string Title;
                uint32_t Width, Height;
                //是否开启垂直同步
                bool VSync;
                //事件回调函数
                EventCallbackFn EventCallback;
            };
            WindowData m_Data;

    };
}