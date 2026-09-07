#include "../../include/platform/window.hpp"
//#include "sdl3/sdl_renderer.hpp"
#include "../software/softwarerenderer.hpp"
#include "sdl3/sdl_window.hpp"

#include <memory>
namespace rf
{

std::unique_ptr<Window> createWindow()
{
    return std::make_unique<SDLWindow>();
}

std::unique_ptr<Renderer> createRenderer()
{
    return std::make_unique<SoftwareRenderer>();
}

}
