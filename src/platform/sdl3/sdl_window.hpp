#pragma once

#include "../../../include/platform/window.hpp"

struct SDL_Window;

namespace rf
{

class SDLWindow : public Window 
{
    SDL_Window* m_window = nullptr;
    bool m_shouldClose = false;

    public: 
    SDLWindow();

    bool create(int width, int height, const char* title) override;

    void pollEvents() override;

    bool shouldClose() const override;
    
    void* nativeHandle() override;

    ~SDLWindow() override;
};

}
