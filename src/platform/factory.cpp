#include "../../include/platform/window.hpp"
#include "sdl3/sdl_window.hpp"

#include <memory>
namespace mr
{

std::unique_ptr<Window> createWindow()
{
    return std::make_unique<SDLWindow>();
}



}
