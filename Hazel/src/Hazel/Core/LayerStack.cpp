#include <Hazel/Core/LayerStack.hpp>
#include <PreHeader.hpp>



namespace Hazel{
    LayerStack::~LayerStack(){
        for(auto layer : m_Layers){
            layer->OnDetach();
            delete layer;
        }
    }


    void LayerStack::PushLayer(Layer* layer){
        m_Layers.insert(m_Layers.begin() + m_LayerInsertIndex, layer);
        layer->OnAttach();
        ++m_LayerInsertIndex;
    }

    void LayerStack::PopLayer(Layer* layer){
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if(it != m_Layers.end()){
            layer->OnDetach();
            m_Layers.erase(it);
            --m_LayerInsertIndex;
            delete layer;
        }
    }

    void LayerStack::PushOverlay(Layer* layer){
        m_Layers.push_back(layer);
        layer->OnAttach();
    }

    void LayerStack::PopOverlay(Layer* layer){
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if(it != m_Layers.end()){
            layer->OnDetach();
            m_Layers.erase(it);
            delete layer;
        }
    }
}