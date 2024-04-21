#include "Horatio/Projection.h"

namespace Horatio
{
    // haven't tested this yet
    Projection::Projection(float x1, float x2, float y1, float y2)
    {
        /*
            0 |1 |2 |3
            4 |5 |6 |7
            8 |9 |10|11
            12|13|14|15
        */

        data[0] = 2.0f / (x2 - x1);
        data[5] = 2.0f / (y2 - y1);
        data[10] = -1.0f;

        data[12] = -(x2 + x1) / (x2 - x1);
        data[13] = -(y2 + y1) / (y2 - y1);
    }

    // haven't tested this yet
    float &Projection::operator()(int row, int col)
    {
        return data[row * 4 + col];
    }

    // haven't tested this yet
    const float &Projection::operator()(int row, int col) const
    {
        return data[row * 4 + col];
    }
    void Projection::update_projection(float x1, float x2, float y1, float y2)
    {
        data[0] = 2.0f / (x2 - x1);
        data[5] = 2.0f / (y2 - y1);
        data[10] = -1.0f;

        data[12] = -(x2 + x1) / (x2 - x1);
        data[13] = -(y2 + y1) / (y2 - y1);
    }
}
