#include "../../include/renderer/line.hpp"

namespace rf
{

void Line::draw(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{   
    int x0{initial.first} ,y0{initial.second};
    int x1{final.first} ,y1{final.second};
    color l = {r,g,b,a};
   
     int dx  = std::abs(x1 - x0);
    int dy  = std::abs(y1 - y0);
    int sx  = (x0 < x1) ? 1 : -1;
    int sy  = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
 
    int x = x0, y = y0;
    while (true)
    {
        fb.setPixel(x, y, l);
        if (x == x1 && y == y1) break;
 
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x += sx; }
        if (e2 <  dx) { err += dx; y += sy; }
    }


}

}
