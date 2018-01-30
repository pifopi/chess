#pragma once

#include "Player.h"
#include "Utils.h"

#include <array>
#include <memory>

namespace Chess
{
    class PlayerManager
        : public NonCopyable
    {
    public:
        static PlayerManager& Instance();

        std::shared_ptr<Player> GetPlayer(const PlayerIndex& index) const;
        void SetPlayer(const PlayerIndex& index, const std::shared_ptr<Player>& value);

    private:
        PlayerManager();

        std::array<std::shared_ptr<Player>, 2> m_players;
    };
}
