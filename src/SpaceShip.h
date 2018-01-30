#pragma once

#include "Position.h"
#include "Utils.h"

namespace Chess
{
    class SpaceShip
        : public NonCopyable
    {
    public:
        enum class Size
        {
            Big,
            Small
        };

        SpaceShip(const PlayerIndex& owner, const Faction& faction, const Size& size, const Position& position);

        const PlayerIndex& GetOwner() const;
        const Faction& GetFaction() const;
        const Size& GetSize() const;
        const Position& GetPosition() const;

        bool VerifyMove(const Position& position) const;
        void Move(const Position& position);

    private:
        PlayerIndex m_owner;
        Faction m_faction;
        Size m_size;
        Position m_position;
    };
}
