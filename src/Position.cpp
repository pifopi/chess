#include "Position.h"

namespace Chess
{
    Position::Position(const U32& x, const U32& y)
        : m_x(x)
        , m_y(y)
    {

    }

    const U32& Position::GetX() const
    {
        return m_x;
    }

    const U32& Position::GetY() const
    {
        return m_y;
    }
}
