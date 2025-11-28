#include <Hazel/Core/Window.hpp>

#ifdef WINDOWS
#include <Platform/Windows/WindowsWindow.hpp>
#endif


namespace Hazel{
        //创建窗口
        std::unique_ptr<Window> Window::Create(const WindowProps& props){
            #ifdef WINDOWS
                return std::make_unique<WindowsWindow>(props);
            #endif
        
        }
}