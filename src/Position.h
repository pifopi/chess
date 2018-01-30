#pragma once

#include "Utils.h"

namespace Chess
{
    class Position
    {
    public:
        Position(const U32& x, const U32& y);

        const U32& GetX() const;
        const U32& GetY() const;

    private:
        U32 m_x;
        U32 m_y;
    };
}
