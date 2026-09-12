#include "../../include/renderer/shape.hpp"

namespace rf
{
    void Shape::draw(FrameBuffer &fb, color c)
    {
        size_t n = vertices.size();
        if (n < 2) return; 
 
        for (size_t i = 0; i < n; ++i)
        {
            size_t j = (i + 1) % n;
            Line edge(fb, vertices[i].first, vertices[i].second,
                           vertices[j].first, vertices[j].second);
            edge.draw(c.r, c.g, c.b, c.a);
        }
        
    }
}
