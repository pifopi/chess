#include "ImageManager.h"

#include <cassert>

namespace Chess
{
    ImageManager& ImageManager::Instance()
    {
        static ImageManager instance;
        return instance;
    }

    const QIcon& ImageManager::GetWindowIconImage()
    {
        return m_windowIcon;
    }

    const QIcon& ImageManager::GetFactionImage(const Faction& faction)
    {
        switch (faction)
        {
            case Faction::Empire:
                return m_empireImage;
            case Faction::Rebel:
                return m_rebelImage;
            case Faction::Republic:
                return m_republicImage;
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }
    }

    const QIcon& ImageManager::GetSpaceImage() const
    {
        return m_spaceImage;
    }

    const QIcon& ImageManager::GetSpaceShipImage(const Faction& faction, const SpaceShip::Size& size) const
    {
        switch (faction)
        {
            case Faction::Empire:
                switch (size)
                {
                    case SpaceShip::Size::Big:
                        return m_empireHeavySpaceShipImage;
                    case SpaceShip::Size::Small:
                        return m_empireLightSpaceShipImage;
                    default:
                        assert(false);
                        exit(EXIT_FAILURE);
                }
            case Faction::Rebel:
                switch (size)
                {
                    case SpaceShip::Size::Big:
                        return m_rebelHeavySpaceShipImage;
                    case SpaceShip::Size::Small:
                        return m_rebelLightSpaceShipImage;
                    default:
                        assert(false);
                        exit(EXIT_FAILURE);
                }
                break;
            case Faction::Republic:
                switch (size)
                {
                    case SpaceShip::Size::Big:
                        return m_republicHeavySpaceShipImage;
                    case SpaceShip::Size::Small:
                        return m_republicLightSpaceShipImage;
                    default:
                        assert(false);
                        exit(EXIT_FAILURE);
                }
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }
    }

    ImageManager::ImageManager()
        : m_windowIcon("GreenLightSaber.png")
        , m_empireImage("Empire.png")
        , m_rebelImage("Rebel.png")
        , m_republicImage("Republic.png")
        , m_spaceImage("SpaceImage.png")
        , m_empireHeavySpaceShipImage("EmpireHeavySpaceShip.png")
        , m_empireLightSpaceShipImage("EmpireLightSpaceShip.png")
        , m_rebelHeavySpaceShipImage("RebelHeavySpaceShip.png")
        , m_rebelLightSpaceShipImage("RebelLightSpaceShip.png")
        , m_republicHeavySpaceShipImage("RepublicHeavySpaceShip.png")
        , m_republicLightSpaceShipImage("RepublicLightSpaceShip.png")
    {

    }
}
