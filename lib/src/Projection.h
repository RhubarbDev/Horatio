#pragma once

namespace Horatio
{
    class Projection
    {
    public:
        Projection(float x1, float x2, float y1, float y2);
        float& operator()(int row, int col);
        const float& operator()(int row, int col) const;
    private:
        float data[16] = { 0 };
    };
}