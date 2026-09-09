# pragma once
#include "framebuffer.hpp"
#include "line.hpp" 
#include "color.hpp" 
#include <SDL3/SDL_gpu.h>

namespace rf
{

class triangle 
{
    Line a,b,c;
    FrameBuffer &fb;

    public:
    triangle(FrameBuffer &framebuffer,
            std::pair<float,float> p1,
            std::pair<float,float> p2,
            std::pair<float,float> p3) :
        a{fb(framebuffer), p1.first, p1.second, p2.first, p2.second},
        b{fb(framebuffer), p2.first, p2.second, p3.first, p3.second},
        c{fb(framebuffer), p3.first, p3.second, p1.first, p1.second} {}

    void draw(color mono);
    void draw(color c1, color c2, color c3);

    ~triangle();
};

}
        


