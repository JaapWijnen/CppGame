#pragma once

// Platform specific includes
#ifdef __APPLE__
    #include <SDL2/SDL.h>
    #include <OpenGL/gl3.h>
#elif _WIN32
    #include <SDL/SDL.h>
    #include <GL/glew.h>
#endif

#include <string>

namespace Bengine {

    enum WindowFlags { INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

    class Window
    {
    public:
        Window();
        ~Window();

        int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);

        void swapBuffer();

        int getScreenWidth() { return _screenWidth; }
        int getScreenHeight() { return _screenHeight; }
    private:
        SDL_Window* _sdlWindow;
        int _screenWidth, _screenHeight;
    };

}