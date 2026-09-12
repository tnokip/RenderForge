# pragma once
#include "framebuffer.hpp"
#include "line.hpp"
#include <vector>
#include <utility>

namespace rf
{

class Shape {
    std::vector<std::pair<float, float>> vertices;
public:
 
    Shape(std::vector<std::pair<float,float>> vertex) : vertices(std::move(vertex)) {}

    void draw(FrameBuffer &fb, color c);


};

}
