#pragma once

#include "../../../include/renderer/renderer.hpp"
#include <cstdint>
#include <memory>

struct SDL_Renderer;

namespace rf
{

class SDLRenderer : public Renderer 
{
    SDL_Renderer* m_renderer;
    bool m_shouldClose = false;

    public: 
    SDLRenderer();

    bool create(std::unique_ptr<Window>& window, const char* name) override;

    //void pollEvents() override;

    bool shouldClose() const override;
    
    void* nativeHandle() override;

    void clear (uint8_t r, uint8_t g, uint8_t b, uint8_t a) override;

    void present () override;

    ~SDLRenderer() override;
};

}
