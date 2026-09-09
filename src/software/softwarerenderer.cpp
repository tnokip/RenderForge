#include "softwarerenderer.hpp"
#include "../../include/platform/window.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <memory>

namespace rf
{
    SoftwareRenderer::SoftwareRenderer() : m_framebuffer(800,600) {}

    SoftwareRenderer::~SoftwareRenderer()
    {
        if(m_sdltexture) SDL_DestroyTexture(m_sdltexture);
        if(m_sdlrenderer) SDL_DestroyRenderer(m_sdlrenderer);
    }

    bool SoftwareRenderer::create(std::unique_ptr<Window> &window, const char* name)
    {
        SDL_Window* sdlwin = static_cast<SDL_Window*> (window->nativeHandle());
        m_sdlrenderer = SDL_CreateRenderer(sdlwin, nullptr);
        if(!m_sdlrenderer) return false;

        SDL_SetRenderVSync(m_sdlrenderer, 1);

        m_sdltexture = SDL_CreateTexture(
                m_sdlrenderer,
                SDL_PIXELFORMAT_RGBA32 ,
                SDL_TEXTUREACCESS_STREAMING ,
                m_framebuffer.width(),
                m_framebuffer.height()
                );

        return m_sdltexture != nullptr;
    }

    bool SoftwareRenderer::shouldClose() const {return m_shouldclose;}
    void* SoftwareRenderer::nativeHandle() {return m_sdlrenderer;}
    
    void SoftwareRenderer::clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        m_framebuffer.clear(color{r,g,b,a});
    }

    void SoftwareRenderer::present()
    {
        SDL_UpdateTexture(m_sdltexture, 
                nullptr,
                m_framebuffer.data(),
                m_framebuffer.width()*sizeof(uint32_t)
                );
        SDL_RenderTexture(m_sdlrenderer, m_sdltexture, nullptr, nullptr);
        SDL_RenderPresent(m_sdlrenderer);
    }

    FrameBuffer* SoftwareRenderer::getframebuffer()
    {
        return &m_framebuffer;
    }
}

