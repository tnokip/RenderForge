#include "../include/platform/window.hpp"
#include "../include/renderer/renderer.hpp"
#include "../include/renderer/line.hpp"
#include "../include/renderer/triangle.hpp"
#include "../include/renderer/shape.hpp"
#include <chrono>
#include <cmath>
#include <ctime>

int main()
{
    std::unique_ptr<rf::Window> window = rf::createWindow();
    std::unique_ptr<rf::Renderer> renderer = rf::createRenderer();
    rf::FrameBuffer* fb = renderer->getframebuffer();

    constexpr float PI = 3.14159265f;

    using clock = std::chrono::steady_clock;
    const auto starttime = clock::now();
    auto prevtime = starttime;

    

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

        const auto now = clock::now();
        const float t  = std::chrono::duration<float>(now - starttime).count();
        const float dt = std::chrono::duration<float>(now - prevtime).count();
        prevtime = now;
        (void)dt;
        

        const float cx = 400.0f, cy = 300.0f;
        int r = 100;
        const float angle = 2.094;
        
        renderer->clear(255, 255, 255, 255); 


        //rf::triangle tri{ {105,505}, {505,105}, {505,505} };
        //rf::Shape hexagon{ { {600,300}, {500,473}, {300,473}, {200,300}, {300,127}, {500,127} } };
        rf::triangle moving{ {cx + r*std::cos(t), cy + r*std::sin(t + 1)},
                                {cx + r*std::cos(t + angle), cy + r*std::sin(t + 1 + angle)},
                                {cx + r*std::cos(t + 2*angle), cy + r*std::sin(t + 1 + 2*angle)}};
        moving.draw(*fb, {255 ,25, 25, 255} );
        moving.fill(*fb,  {25 , 25 , 255 , 255} );




        //if( t  < 10)
        //{  //rf::Line line1{*fb,100,100,100,500};
        //rf::Line line2{*fb,100,100,500,100};
        //rf::Line line3{*fb,500,100,100,500};
        //rf::Line focus{*fb,cx,cy,cx+500.0f*std::cos(angle),cy+500.0f*std::sin(angle)};
        //line1.draw(0,255,0,255 );
        //line2.draw(0,0,255,255 );
        //line3.draw(255,0,0,255 );
        //focus.draw(a,a,a,255);
        //}
        /*else{
        line1.draw(255,0,255,255 );
        line2.draw(255,255,0,255 );
        line3.draw(0,255,255,255 );
        } */  
        //tri.draw(*fb, {100,200,150,255});
        //tri.fill(*fb, {255,0,31,255});
        //hexagon.draw(*fb, {25,250,200,255});
    
        renderer->present();
      
    }

    return 0;
}
