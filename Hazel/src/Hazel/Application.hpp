#pragma once
#include <Hazel/Core.hpp>
#include <iostream>
namespace Hazel {
    
    class HAZEL_API Application {
        public:
            Application();
            virtual~Application() = default;
            void Run();
           
    };
     Application* CreateApplication();
      
}