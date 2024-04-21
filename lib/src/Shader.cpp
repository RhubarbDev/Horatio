#include "Horatio/Shader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace Horatio
{

    Shader::Shader(const std::string &vertex, const std::string &fragment)
    {
        if(glfwGetCurrentContext() == nullptr)
        {
            throw std::runtime_error("no context. shader can't initialise");
        }

        std::string vertex_source = read_file(vertex);
        std::string fragment_source = read_file(fragment);

        render_id = create(vertex_source, fragment_source);
    }

    Shader::~Shader()
    {
        if(render_id != 0) glDeleteProgram(render_id);
    }

    unsigned int Shader::compile(unsigned int type, const std::string &source)
    {
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);
        return id;
    }

    unsigned int Shader::create(const std::string &vertex_source, const std::string &fragment_source)
    {
        unsigned int program = glCreateProgram();

        unsigned int vertex_compiled = compile(GL_VERTEX_SHADER, vertex_source);
        unsigned int fragment_compiled = compile(GL_FRAGMENT_SHADER, fragment_source);

        glAttachShader(program, vertex_compiled);
        glAttachShader(program, fragment_compiled);
        glLinkProgram(program);

        glValidateProgram(program);

        glDeleteShader(vertex_compiled);
        glDeleteShader(fragment_compiled);

        return program;
    }

    std::string Shader::read_file(const std::string &path)
    {
        if(!std::filesystem::exists(path))
        {
            throw std::invalid_argument("Invalid path.");
        }

        std::stringstream stream;
        std::ifstream file(path);

        if(file.is_open())
        {
            for(std::string line; getline(file, line);)
            {
                stream << line << '\n';
            }
        }
        return stream.str();
    }
}