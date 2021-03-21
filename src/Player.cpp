#include "Player.h"
#include "SpaceShip.h"

#include <QApplication>
#include <QMessageBox>
#include <QWidget>

namespace Chess
{
    Player::Player(const Faction& faction, const QString& name)
        : m_faction(faction)
        , m_name(name)
    {

    }

    const Faction& Player::GetFaction() const
    {
        return m_faction;
    }

    const QString& Player::GetName() const
    {
        return m_name;
    }

    const std::vector<std::shared_ptr<SpaceShip>>& Player::GetSpaceShips() const
    {
        return m_spaceShips;
    }

    void Player::AddSpaceShip(const std::shared_ptr<SpaceShip>& spaceShip)
    {
        m_spaceShips.push_back(spaceShip);
    }

    void Player::RemoveSpaceShip(const std::shared_ptr<SpaceShip>& spaceShip)
    {
        m_spaceShips.erase(std::remove(m_spaceShips.begin(), m_spaceShips.end(), spaceShip));

        if (m_spaceShips.empty() == true)
        {
            QWidget message;
            QMessageBox::information(&message, "Game ended", m_name + " lose", QMessageBox::Ok);
            qApp->exit();
        }
    }
}
