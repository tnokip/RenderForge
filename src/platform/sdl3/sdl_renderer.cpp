//#include "sdl_window.hpp"
#include "sdl_renderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

namespace rf 
{

SDLRenderer::SDLRenderer() {}

SDLRenderer::~SDLRenderer()
{
    SDL_DestroyRenderer(m_renderer);

}

bool SDLRenderer::create(std::unique_ptr<Window>& window, const char* name)
{
    SDL_Window *sdlwin = static_cast<SDL_Window*>(window->nativeHandle());
    m_renderer = SDL_CreateRenderer(sdlwin, name );
    return m_renderer != nullptr;
}

/*
void SDLRenderer::pollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        
    }
}
*/

bool SDLRenderer::shouldClose() const
{
    return m_shouldClose;
}



void* SDLRenderer::nativeHandle()
{
    return m_renderer;
}


void SDLRenderer::clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
    SDL_RenderClear(m_renderer);
}

void SDLRenderer::present()
{
    SDL_RenderPresent(m_renderer);
}


}
