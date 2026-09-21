# pragma once
#include "framebuffer.hpp"
#include "line.hpp" 
#include "color.hpp" 
#include "shape.hpp"
#include <SDL3/SDL_gpu.h>
#include <algorithm>
#include <cmath>
#include <iostream>

namespace rf
{

class triangle 
{
    std::pair<float,float> a,b,c;
    //std::vector<std::vector<std::pair<int,int>>> Y;

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

        //Y.push_back(ab.coordinates());
        //Y.push_back(bc.coordinates());
        //Y.push_back(ca.coordinates());

    }

    void fill(FrameBuffer &fb,color col)
    {
        //std::cout<<"line is being drawn\n";
        auto edge = [](const std::pair<float,float> &p, const std::pair<float,float> &q,
                        const float x, const float y)
        {
            //return (q.first-p.first)*(y-p.second)-(q.second-p.second)*(x-p.second);
            return std::abs(p.first*(q.second-y)+q.first*(y-p.second)+x*(p.second-q.second));
        };

        const float area = edge(a, b, c.first, c.second);
        if (area == 0.0f) return;

        const int minX = (int)std::floor(std::min({a.first, b.first, c.first}));
        const int maxX = (int)std::ceil(std::max({a.first, b.first, c.first}));
        const int minY = (int)std::floor(std::min({a.second, b.second, c.second}));
        const int maxY = (int)std::ceil(std::max({a.second, b.second, c.second}));
        bool inside  = false;

        for (int y = minY; y <= maxY; ++y)
        {
            for (int x = minX; x <= maxX; ++x)
            {
                float w0 = edge(b, c, x, y);
                float w1 = edge(c, a, x, y);
                float w2 = edge(a, b, x, y);
                //if(area == w0 + w1 + w2) inside = true; 
                //const bool inside = area > 0 ? (w0 >= 0 && w1 >= 0 && w2 >= 0)
                        //                     : (w0 <= 0 && w1 <= 0 && w2 <= 0);
                if (area == (w0 + w1 + w2))
                {
                    fb.setPixel(x, y, col);
                    inside = false;
                }

            }
        }

    }


};

}
        
