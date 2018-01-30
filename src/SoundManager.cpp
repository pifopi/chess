#include "SoundManager.h"

#include <cassert>

namespace Chess
{
    SoundManager& SoundManager::Instance()
    {
        static SoundManager instance;
        return instance;
    }

    void SoundManager::PlayMainSound()
    {
        m_mainSound.play();
        m_mainSound.setLoops(-1);
    }

    void SoundManager::StopMainSound()
    {
        m_mainSound.stop();
    }

    void SoundManager::PlayMoveSound(const SpaceShip::Size& size)
    {
        switch (size)
        {
            case SpaceShip::Size::Big:
                m_heavySpaceShipMoveSound.play();
                break;
            case SpaceShip::Size::Small:
                m_lightSpaceShipMoveSound.play();
                break;
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }
    }

    void SoundManager::PlayShootSound(const SpaceShip::Size& size)
    {
        switch (size)
        {
            case SpaceShip::Size::Big:
                m_heavySpaceShipShootSound.play();
                break;
            case SpaceShip::Size::Small:
                m_lightSpaceShipShootSound.play();
                break;
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }
    }

    SoundManager::SoundManager()
        : m_mainSound("MainSound.wav")
        , m_heavySpaceShipMoveSound("HeavySpaceShipMoveSound.wav")
        , m_heavySpaceShipShootSound("HeavySpaceShipShootSound.wav")
        , m_lightSpaceShipMoveSound("LigthSpaceShipMoveSound.wav")
        , m_lightSpaceShipShootSound("LigthSpaceShipShootSound.wav")
    {

    }
}
