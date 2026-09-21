# pragma once
#include "framebuffer.hpp"
#include "line.hpp"
#include <cstdint>

namespace rf
{

enum class radiustype
{
    vertex,edges
};

class regularpolygon
{
    int edges, cx, cy;
    float circumradius,rotation;
    color clr;

    public:
    regularpolygon(int n,
            float x = {WIDTH/2}, float y = {HEIGHT/2}, 
            float r = 0.0f, radiustype type = radiustype::vertex,
            float rotation = 0.0f, color c) :
        edges(x), cx(x), cy(y), circumradius(r), rotation(rotation), clr(c) {}



};

}
