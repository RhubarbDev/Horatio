#pragma once

namespace Horatio
{
    class Projection
    {
    public:
        Projection(float x1 = 0, float x2 = 0, float y1 = 0, float y2 = 0);
        float& operator()(int row, int col);
        const float& operator()(int row, int col) const;
        void update_projection(float x1, float x2, float y1, float y2);
    private:
        float data[16] = { 0 };
    };
}