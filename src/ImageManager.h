#pragma once

#include "SpaceShip.h"
#include "Utils.h"

#include <memory>
#include <QIcon>

namespace Chess
{
    class ImageManager
        : public NonCopyable
    {
    public:
        static ImageManager& Instance();

        const QIcon& GetWindowIconImage();
        const QIcon& GetFactionImage(const Faction& faction);
        const QIcon& GetSpaceImage() const;
        const QIcon& GetSpaceShipImage(const Faction& faction, const SpaceShip::Size& size) const;

    private:
        ImageManager();

        QIcon m_windowIcon;

        QIcon m_empireImage;
        QIcon m_rebelImage;
        QIcon m_republicImage;

        QIcon m_spaceImage;

        QIcon m_empireHeavySpaceShipImage;
        QIcon m_empireLightSpaceShipImage;

        QIcon m_rebelHeavySpaceShipImage;
        QIcon m_rebelLightSpaceShipImage;

        QIcon m_republicHeavySpaceShipImage;
        QIcon m_republicLightSpaceShipImage;
    };
}
