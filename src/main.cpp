#include "../include/platform/window.hpp"
#include "../include/renderer/renderer.hpp"

int main()
{
    std::unique_ptr<rf::Window> window = rf::createWindow();
    std::unique_ptr<rf::Renderer> renderer = rf::createRenderer();

    if(!window->create(rf::WIDTH,rf::HEIGHT,"RenderForge"))
    {
        return 1;
    }

    if(!renderer->create(window, nullptr ))
    {
        return 2;
    }

    while(!window->shouldClose())
    {
        window->pollEvents();
        
        renderer->clear(255, 158, 31, 255); 
        renderer->present();
      
    }

    return 0;
}
