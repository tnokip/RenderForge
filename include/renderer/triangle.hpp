# pragma once
#include "framebuffer.hpp"
#include "line.hpp" 
#include "color.hpp" 
#include "shape.hpp"
#include <SDL3/SDL_gpu.h>

namespace rf
{

class triangle 
{
    std::pair<float,float> a,b,c;

    public:
    triangle(
                std::pair<float,float> p1,
                std::pair<float,float> p2,
                std::pair<float,float> p3) :
            a{p1.first, p1.second},
            b{p2.first, p2.second},
            c{p3.first, p3.second} {}

    void draw(FrameBuffer &fb,color mono)
    {
        Line ab{fb, a.first, a.second, b.first, b.second};
        Line bc{fb, b.first, b.second, c.first, c.second};
        Line ca{fb, c.first, c.second, a.first, a.second};

        ab.draw(mono.r, mono.g,mono.b,mono.a);
        bc.draw(mono.r, mono.g,mono.b,mono.a);
        ca.draw(mono.r, mono.g,mono.b,mono.a);

    }

    //void draw(color c1, color c2, color c3) override;

    //~triangle() {}
};

}
        


