#pragma once

#include <GLFW/glfw3.h>

namespace Horatio
{
    class Projection
    {
    public:
        Projection(float x1, float x2, float y1, float y2);
        virtual float& operator()(int row, int col);
        virtual const float& operator()(int row, int col) const;
    private:
        float data[16] = { 0 };
    };
}