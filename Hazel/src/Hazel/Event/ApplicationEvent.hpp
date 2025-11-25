#pragma once
#include <Hazel/Event/Event.hpp>
#include <sstream>

namespace Hazel{
    class WindowResizedEvent : public Event{
        public:
            WindowResizedEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}
            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
                return ss.str();
            }
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(WindowResize)
        private:
            unsigned int m_Width, m_Height;
    };

    class WindowClosedEvent : public Event{
        public:
            WindowClosedEvent() = default;
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(WindowClose)
    };
    class WindowFocusedEvent : public Event{
        public:
            WindowFocusedEvent() = default;
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(WindowFocus)
    };
    class WindowLostFocusEvent : public Event{
        public:
            WindowLostFocusEvent() = default;
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(WindowLostFocus)
    };

    class WindowMovedEvent : public Event{
        public:
            WindowMovedEvent(int x, int y) : m_X(x), m_Y(y) {}
            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "WindowMovedEvent: " << m_X << ", " << m_Y;
                return ss.str();
            }
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(WindowMoved)
        private:
            int m_X, m_Y;
    };

    class AppTickEvent : public Event{
        public:
            AppTickEvent() = default;
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(AppTick)
    };
    class AppUpdateEvent : public Event{
        public:
            AppUpdateEvent() = default;
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(AppUpdate)
    };
    class AppRenderEvent : public Event{
        public:
            AppRenderEvent() = default;
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            EVENT_CLASS_TYPE(AppRender)
    };
}