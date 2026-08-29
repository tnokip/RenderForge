#include "../include/platform/window.hpp"

int main()
{
    auto window = mr::createWindow();

    if(!window->create(800,600,"Renderer"))
    {
        return 1;
    }

    while(!window->shouldClose())
    {
        window->pollEvents();
    

    }

    return 0;
}
