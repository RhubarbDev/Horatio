#pragma once

#include <string>

namespace Horatio
{
    class Shader
    {
    public:
        Shader(const std::string& vertex, const std::string& fragment);
        ~Shader();
        int render_id = 0;
    private:
        unsigned int compile(unsigned int type, const std::string& source);
        unsigned int create(const std::string& vertex_source, const std::string& fragment_source);
        std::string read_file(const std::string& path);
    };
}