# pragma once
#include "../../include/core/framebuffer.hpp"
#include "../../include/renderer/renderer.hpp"

struct SDL_Renderer;
struct SDL_Texture;

namespace rf
{
    class SoftwareRenderer : public Renderer
    {
        FrameBuffer m_framebuffer;
        SDL_Renderer* m_sdlrenderer = nullptr;
        SDL_Texture* m_sdltexture = nullptr;
        bool m_shouldclose = false;

        public:
        SoftwareRenderer();
        ~SoftwareRenderer() override;

        bool create(std::unique_ptr<Window> &window, const char* name) override;
        
        bool shouldClose() const override;

        void* nativeHandle() override;

        void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override;
        void present() override;
    };

}

        

