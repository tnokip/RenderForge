#include "../include/platform/window.hpp"
#include "../include/renderer/renderer.hpp"
#include "../include/renderer/line.hpp"
#include <ctime>

int main()
{
    std::unique_ptr<rf::Window> window = rf::createWindow();
    std::unique_ptr<rf::Renderer> renderer = rf::createRenderer();
    rf::FrameBuffer* fb = renderer->getframebuffer();
    std::clock_t ticks = std::clock();
    int seconds = static_cast<int>(ticks)/CLOCKS_PER_SEC;

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
        
        renderer->clear(0, 0, 0, 255); 
        
        rf::Line line1{*fb,100,100,100,500};
        rf::Line line2{*fb,100,100,500,100};
        rf::Line line3{*fb,500,100,100,500};

        line1.draw(0,255,0,255 );
        line2.draw(0,0,255,255 );
        line3.draw(255,0,0,255 );

        line1.draw(255,0,255,255 );
        line2.draw(255,255,0,255 );
        line3.draw(0,255,255,255 );
    
        renderer->present();
      
    }

    return 0;
}
