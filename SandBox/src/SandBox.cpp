#include <Hazel.hpp>
#include <Hazel/Core/Layer.hpp>
#include <Hazel/Event/Event.hpp>

class ExampleLayer : public Hazel::Layer{
    public:
     ExampleLayer() : Layer("ExampleLayer") {}
     virtual void OnEvent(Hazel::Event& event) {
        HAZEL_CLIENT_TRACE("ExampleLayer::OnEvent({0})", event.ToString());
     }
     
};


class SandBox : public Hazel::Application {
    public:
        SandBox(){
            PushLayer(new ExampleLayer());
        }
        ~SandBox(){}
       
        
};

 Hazel::Application* Hazel::CreateApplication(){
    return new SandBox();
 }