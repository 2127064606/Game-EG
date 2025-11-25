#pragma once

#include <Hazel/Core.hpp>
#include <Hazel/Event/Event.hpp>


#include <sstream>


namespace Hazel{
    //窗口属性
    struct WindowProps{
        std::string Title;
        uint32_t width;
        uint32_t height;
        WindowProps(const std::string& title = "Hazel", uint32_t width = 1600, uint32_t height = 900)
            : Title(title), width(width), height(height)
        {}
    };

    //窗口类
    class Window{
        public:
        //返回值void,参数Event&
            using EventCallbackFn = std::function<void(Event&)>;

            virtual ~Window() = default;

            virtual void OnUpdate() = 0;

            //设置事件回调函数
            virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

            virtual void SetVSync(bool enabled) = 0;
            //返回值bool
            virtual bool IsVSync() const = 0;

            //返回窗口指针
            virtual void* GetNativeWindow() const = 0;

            //返回值bool
            virtual bool IsClosed() const = 0;

            //创建窗口
            static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());

            virtual uint32_t GetWidth() const = 0;
            virtual uint32_t GetHeight() const = 0;
            
       
    };
}
