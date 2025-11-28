#pragma once

#include <Hazel/Core.hpp>
#include <Hazel/Core/Layer.hpp>


namespace Hazel{
    class HAZEL_API LayerStack{
        public:
            LayerStack() = default;
            ~LayerStack();

            void PushLayer(Layer* layer);
            void PopLayer(Layer* layer);
            void PushOverlay(Layer* layer);
            void PopOverlay(Layer* layer);

            std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
            std::vector<Layer*>::iterator end() { return m_Layers.end(); }
            std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
            std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }
        private:
            std::vector<Layer*> m_Layers;
            unsigned int m_LayerInsertIndex = 0;
    };
}