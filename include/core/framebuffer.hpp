# pragma once

#include "../platform/window.hpp"
#include "color.hpp"
#include <cstdint>
#include <vector>

namespace rf
{
    class FrameBuffer
    {
        int m_width;
        int m_height;
        std::vector<uint32_t> m_pixels;

        public:
        FrameBuffer(int w = WIDTH, int h = HEIGHT) : m_width(w) , m_height(h) , m_pixels(m_width * m_height, 0) {}

        void clear(color color);

        void setPixel(int x, int y, color color);

        int width() const {return m_width;}
        int heigth() const {return m_height;}

        const uint32_t* data() const {return m_pixels.data(); }

    };


}
