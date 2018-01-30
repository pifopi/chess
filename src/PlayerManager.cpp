#include "PlayerManager.h"

namespace Chess
{
    PlayerManager& PlayerManager::Instance()
    {
        static PlayerManager instance;
        return instance;
    }

    std::shared_ptr<Player> PlayerManager::GetPlayer(const PlayerIndex& index) const
    {
        return m_players[index];
    }

    void PlayerManager::SetPlayer(const PlayerIndex& index, const std::shared_ptr<Player>& value)
    {
        m_players[index] = value;
    }

    PlayerManager::PlayerManager()
        : m_players{nullptr, nullptr}
    {

    }
}
