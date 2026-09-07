#include "../../include/core/framebuffer.hpp"
#include <algorithm>
#include <cstdint>

namespace rf
{

    void FrameBuffer::clear(color color)
    {
        uint32_t fill = RGBA(color);
        std::fill(m_pixels.begin(), m_pixels.end(), fill);
    }

    void FrameBuffer::setPixel(int x, int y, color color)
    {
        if (x < 0 || x >= m_width || y < 0 || y >= m_height)return;
        m_pixels[y * m_width + x] = RGBA(color);

    }

}
