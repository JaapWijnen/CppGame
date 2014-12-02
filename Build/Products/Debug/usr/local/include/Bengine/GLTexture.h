#pragma once

// Platform specific includes
#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#elif _WIN32
    #include <GL/glew.h>
#endif

namespace Bengine {

    struct GLTexture {
        GLuint id;
        int width;
        int height;
    };
}