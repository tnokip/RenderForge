#pragma once
#include "framebuffer.hpp"
#include <cstdlib>
#include <vector>
namespace rf
{
class Line 
{
    std::pair<int,int> initial;
    std::pair<int,int> final;
    std::vector<std::pair<int,int>> coords;
    FrameBuffer &fb;

    public:
    Line(FrameBuffer &framebuffer, float x1, float y1, float x2, float y2) : 
        initial{static_cast<int>(x1), static_cast<int>(y1)},
        final{static_cast<int>(x2), static_cast<int>(y2)}, fb(framebuffer)
    {}

    void draw(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        
    std::vector<std::pair<int,int>> coordinates();

    virtual ~Line() {}
        
};

}


