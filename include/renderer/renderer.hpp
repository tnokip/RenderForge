#pragma once

#include "../platform/window.hpp"
#include <SDL3/SDL_render.h>
#include <cstdint>
#include <memory>

namespace rf
{

class FrameBuffer;

class Renderer
{
    public:
    virtual bool create(std::unique_ptr<Window> &window, const char* name) = 0;
        
        //virtual void pollEvents() = 0;
        virtual bool shouldClose() const = 0;

        virtual void* nativeHandle() = 0;
        virtual FrameBuffer* getframebuffer() {return nullptr;}

        virtual void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;
        virtual void present() = 0;

        virtual ~Renderer () = default;
};

std::unique_ptr<Renderer> createRenderer();

}

