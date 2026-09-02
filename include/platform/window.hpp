#pragma once

#include <memory>

namespace rf
{
const int WIDTH = 800;
const int HEIGHT = 600;

class Window
{
    public:
        virtual bool create(int width, int height, const char* title) = 0;
        
        virtual void pollEvents() = 0;
        virtual bool shouldClose() const = 0;

        virtual void* nativeHandle() = 0;
        virtual ~Window () = default;
};

std::unique_ptr<Window> createWindow();

}
