#pragma once
#include <Hazel/Event/Event.hpp>
#include <Hazel/Core/KeyCodes.hpp>
#include <sstream>

namespace Hazel{
        class  KeyEvent : public Event{
            public:
                KeyCode GetKeyCode() const { return m_KeyCode; }
                EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
            protected:
                KeyEvent(KeyCode keyCode) : m_KeyCode(keyCode) {}
                KeyCode m_KeyCode;
        };

        class KeyPressedEvent : public KeyEvent{
            public:
                KeyPressedEvent(KeyCode keyCode, bool isRepeat = false) : KeyEvent(keyCode), m_IsRepeat(isRepeat) {}
                EVENT_CLASS_TYPE(KeyPressed);
                bool IsRepeat() const { return m_IsRepeat; }
                std::string ToString() const override
                {
                    std::stringstream ss;
                    ss << "按下的按键为 = " << GetKeyCode() << ", IsRepeat  = " << IsRepeat();
                    return ss.str();
                }
            private:
                bool m_IsRepeat;
        };

        class KeyReleasedEvent : public KeyEvent{
            public:
                KeyReleasedEvent(KeyCode keyCode) : KeyEvent(keyCode) {}
                EVENT_CLASS_TYPE(KeyReleased);
                std::string ToString() const override
                {
                    std::stringstream ss;
                    ss << "释放的按键为 = " << GetKeyCode();
                    return ss.str();
                }
        };
        

        class KeyTypedEvent : public KeyEvent{
            public:
                KeyTypedEvent(KeyCode keyCode) : KeyEvent(keyCode) {}
                EVENT_CLASS_TYPE(KeyTyped);
                std::string ToString() const override
                {
                    std::stringstream ss;
                    ss << "输入的按键为 = " << GetKeyCode();
                    return ss.str();
                }
        };

}