#pragma once

#include "Utils.h"

#include <memory>
#include <QString>
#include <vector>

namespace Chess
{
    class SpaceShip;

    class Player
    {
    public:
        Player(const Faction& faction, const QString& name);

        const Faction& GetFaction() const;
        const QString& GetName() const;
        const std::vector<std::shared_ptr<SpaceShip>>& GetSpaceShips();

        void AddSpaceShip(const std::shared_ptr<SpaceShip>& spaceShip);
        void RemoveSpaceShip(const std::shared_ptr<SpaceShip>& spaceShip);

    private:
        Faction m_faction;
        QString m_name;
        std::vector<std::shared_ptr<SpaceShip>> m_spaceShips;
    };
}
