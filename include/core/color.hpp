# pragma once

#include <cstdint>
namespace rf
{

struct color
{
    uint8_t r, g, b, a;
};

inline uint32_t RGBA(color c)
{
    return (static_cast<uint32_t>(c.r) << 24 | 
            static_cast<uint32_t>(c.g) << 16 | 
            static_cast<uint32_t>(c.b) << 8 | 
            static_cast<uint32_t>(c.a) );    
}


}
