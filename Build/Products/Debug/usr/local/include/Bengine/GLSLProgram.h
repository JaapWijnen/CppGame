#pragma once

// Platform specific includes
#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#elif _WIN32
    #include <GL/glew.h>
#endif

#include <string>

namespace Bengine {

    //This class handles the compilation, linking, and usage of a GLSL shader program.
    //Reference: http://www.opengl.org/wiki/Shader_Compilation
    class GLSLProgram
    {
    public:
        GLSLProgram();
        ~GLSLProgram();

        void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilepath);

        void linkShaders();

        void addAttribute(const std::string& attributeName);

        GLint getUniformLocation(const std::string& uniformName);

        void use();
        void unuse();
    private:

        int _numAttributes;

        void compileShader(const std::string& filePath, GLuint id);

        GLuint _programID;

        GLuint _vertexShaderID;
        GLuint _fragmentShaderID;
    };

}
