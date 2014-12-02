// Platform specific includes
#ifdef __APPLE__
    #include <SDL2/SDL.h>
    #include <OpenGL/gl3.h>
#elif _WIN32
    #include <SDL/SDL.h>
    #include <GL/glew.h>
#endif

#include "Bengine.h"

namespace Bengine {

    int init() {
        //Initialize SDL
        SDL_Init(SDL_INIT_EVERYTHING);
        
        //Apple specific OpenGL setup
        #ifdef __APPLE__
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
        #endif

        //Tell SDL that we want a double buffered window so we dont get
        //any flickering
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        return 0;
    }

}