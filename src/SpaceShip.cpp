#include "SpaceShip.h"

#include <algorithm>
#include <cassert>

namespace Chess
{
    SpaceShip::SpaceShip(const PlayerIndex& owner, const Faction& faction, const Size& size, const Position& position)
        : m_owner(owner)
        , m_faction(faction)
        , m_size(size)
        , m_position(position)
    {

    }

    const PlayerIndex& SpaceShip::GetOwner() const
    {
        return m_owner;
    }

    const Faction& SpaceShip::GetFaction() const
    {
        return m_faction;
    }

    const SpaceShip::Size& SpaceShip::GetSize() const
    {
        return m_size;
    }

    const Position& SpaceShip::GetPosition() const
    {
        return m_position;
    }

    bool SpaceShip::VerifyMove(const Position& position) const
    {
        const U32 distanceX = std::max(m_position.GetX(), position.GetX()) - std::min(m_position.GetX(), position.GetX());
        const U32 distanceY = std::max(m_position.GetY(), position.GetY()) - std::min(m_position.GetY(), position.GetY());

        U32 range = 0;
        switch (m_size)
        {
            case Size::Big:
                range = 2;
                break;
            case Size::Small:
                range = 5;
                break;
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }

        if (distanceX + distanceY > range ||
            distanceX + distanceY == 0)
        {
            return false;
        }
        return true;
    }

    void SpaceShip::Move(const Position& position)
    {
        m_position = position;
    }
}
