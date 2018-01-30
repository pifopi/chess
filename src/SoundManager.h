#pragma once

#include "SpaceShip.h"
#include "Utils.h"

#include <QSound>

namespace Chess
{
    class SoundManager
        : public NonCopyable
    {
    public:
        static SoundManager& Instance();

        void PlayMainSound();
        void StopMainSound();
        void PlayMoveSound(const SpaceShip::Size& size);
        void PlayShootSound(const SpaceShip::Size& size);

    private:
        SoundManager();

        QSound m_mainSound;

        QSound m_heavySpaceShipMoveSound;
        QSound m_heavySpaceShipShootSound;

        QSound m_lightSpaceShipMoveSound;
        QSound m_lightSpaceShipShootSound;
    };
}
