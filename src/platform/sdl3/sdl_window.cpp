#include "sdl_window.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>

namespace mr
{

SDLWindow::SDLWindow()
{
    SDL_Init(SDL_INIT_VIDEO);
}

SDLWindow::~SDLWindow()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool SDLWindow::create(int width, int height, const char* title)
{
    m_window = SDL_CreateWindow(title, width, height, 0);
    return m_window != nullptr;
}

void SDLWindow::pollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if(event.type == SDL_EVENT_QUIT)
        {
            m_shouldClose = true;
        }
    }
}

bool SDLWindow::shouldClose() const
{
    return m_shouldClose;
}



void* SDLWindow::nativeHandle()
{
    return m_window;
}

}
