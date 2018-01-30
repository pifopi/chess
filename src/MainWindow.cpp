#include "HelpWindow.h"
#include "ImageManager.h"
#include "MainWindow.h"
#include "OptionWindow.h"
#include "Player.h"
#include "PlayerManager.h"
#include "SoundManager.h"

#include <cassert>
#include <QBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QSignalMapper>

namespace
{
    static const Chess::U32 k_factionImageSize = 100;
}

namespace Chess
{
    MainWindow& MainWindow::Instance()
    {
        static MainWindow instance;
        return instance;
    }

    MainWindow::MainWindow()
        : m_turnIndexPlayer(0)
        , m_selectioned(nullptr)
        , m_playerLabels{new QPushButton, new QPushButton}
        , m_optionsButton(new QPushButton("&Options"))
        , m_helpButton(new QPushButton("&Help"))
        , m_signalMapper(new QSignalMapper)
        , m_mapLayout(new QGridLayout)
        , m_description(new QWidget)
        , m_descriptionLayout(new QVBoxLayout)
        , m_layout(new QHBoxLayout)
    {
        for (auto& row : m_buttons)
        {
            for (auto& elem : row)
            {
                elem = new QPushButton();
            }
        }

        for (auto& row : m_map)
        {
            for (auto& elem : row)
            {
                elem = nullptr;
            }
        }

        m_playerLabels[0]->setText(PlayerManager::Instance().GetPlayer(0)->GetName());
        m_playerLabels[0]->setIcon(ImageManager::Instance().GetFactionImage(PlayerManager::Instance().GetPlayer(0)->GetFaction()));
        m_playerLabels[0]->setIconSize(QSize(k_factionImageSize, k_factionImageSize));

        QObject::connect(m_optionsButton, SIGNAL(clicked()), this, SLOT(ShowOptionsWindow()));
        QObject::connect(m_helpButton, SIGNAL(clicked()), this, SLOT(ShowHelpButton()));

        m_playerLabels[1]->setText(PlayerManager::Instance().GetPlayer(1)->GetName());
        m_playerLabels[1]->setIcon(ImageManager::Instance().GetFactionImage(PlayerManager::Instance().GetPlayer(1)->GetFaction()));
        m_playerLabels[1]->setIconSize(QSize(k_factionImageSize, k_factionImageSize));

        m_descriptionLayout->addWidget(m_playerLabels[0]);
        m_descriptionLayout->addWidget(m_optionsButton);
        m_descriptionLayout->addWidget(m_helpButton);
        m_descriptionLayout->addWidget(m_playerLabels[1]);

        m_description->setLayout(m_descriptionLayout);

        for (U32 x = 0; x < k_mapSize; ++x)
        {
            for (U32 y = 0; y < k_mapSize; ++y)
            {
                m_buttons[x][y]->setToolTip(QString("%1 | %2").arg(x).arg(y));
                m_buttons[x][y]->setIconSize(QSize(60, 60));
                QObject::connect(m_buttons[x][y], SIGNAL(clicked()), m_signalMapper, SLOT(map()));
                m_signalMapper->setMapping(m_buttons[x][y], QString("%1%2").arg(x).arg(y));
                m_mapLayout->addWidget(m_buttons[x][y], x, y);
            }
        }
        QObject::connect(m_signalMapper, SIGNAL(mapped(QString)), this, SLOT(SelectCase(QString)));

        InitPlayer(0);
        InitPlayer(1);

        UpdateButtons();


        m_layout->addWidget(m_description);
        m_layout->addLayout(m_mapLayout);

        setLayout(m_layout);
        setWindowIcon(ImageManager::Instance().GetWindowIconImage());
    }

    MainWindow::~MainWindow()
    {
        delete m_signalMapper;
    }

    void MainWindow::UpdateButtons()
    {
        for (U32 x = 0; x < k_mapSize; ++x)
        {
            for (U32 y = 0; y < k_mapSize; ++y)
            {
                if (m_map[x][y] == nullptr)
                {
                    m_buttons[x][y]->setIcon(ImageManager::Instance().GetSpaceImage());
                }
                else
                {
                    auto faction = m_map[x][y]->GetFaction();
                    auto size = m_map[x][y]->GetSize();
                    m_buttons[x][y]->setIcon(ImageManager::Instance().GetSpaceShipImage(faction, size));
                }
            }
        }


        if (m_selectioned == nullptr)
        {
            for (U32 x = 0; x < k_mapSize; ++x)
            {
                for (U32 y = 0; y < k_mapSize; ++y)
                {
                    if (m_map[x][y] == nullptr)
                    {
                        m_buttons[x][y]->setEnabled(false);
                    }
                    else if (m_map[x][y]->GetOwner() == m_turnIndexPlayer)
                    {
                        m_buttons[x][y]->setEnabled(true);
                    }
                    else
                    {
                        m_buttons[x][y]->setEnabled(false);
                    }
                }
            }
        }
        else
        {
            for (U32 x = 0; x < k_mapSize; ++x)
            {
                for (U32 y = 0; y < k_mapSize; ++y)
                {
                    if (m_selectioned->VerifyMove(Position(x, y)))
                    {
                        if (m_map[x][y] != nullptr && m_map[x][y]->GetOwner() == m_turnIndexPlayer)
                        {
                            m_buttons[x][y]->setEnabled(false);
                        }
                        else
                        {
                            m_buttons[x][y]->setEnabled(true);
                        }
                    }
                    else
                    {
                        m_buttons[x][y]->setEnabled(false);
                    }
                }
            }
        }

        if (m_turnIndexPlayer == 0)
        {
            m_playerLabels[0]->setEnabled(true);
            m_playerLabels[1]->setEnabled(false);
        }
        else
        {
            m_playerLabels[0]->setEnabled(false);
            m_playerLabels[1]->setEnabled(true);
        }
    }

    void MainWindow::InitPlayer(const PlayerIndex& playerIndex)
    {
        U8 baseX = 0;
        S8 offsetX = 0;

        switch (playerIndex)
        {
            case 0:
                baseX = 0;
                offsetX = 1;
                break;
            case 1:
                baseX = k_mapSize - 1;
                offsetX = -1;
                break;
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }

        auto player = PlayerManager::Instance().GetPlayer(playerIndex);
        switch (player->GetFaction())
        {
            case Faction::Empire:
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Empire, SpaceShip::Size::Small, Position(baseX, 1)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Empire, SpaceShip::Size::Big, Position(baseX, 3)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Empire, SpaceShip::Size::Big, Position(baseX + offsetX, 2)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Empire, SpaceShip::Size::Big, Position(baseX + offsetX, 3)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Empire, SpaceShip::Size::Big, Position(baseX + offsetX, 4)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Empire, SpaceShip::Size::Big, Position(baseX + offsetX, 5)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Empire, SpaceShip::Size::Big, Position(baseX, 4)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Empire, SpaceShip::Size::Small, Position(baseX, 6)));
                break;
            case Faction::Rebel:
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Rebel, SpaceShip::Size::Small, Position(baseX, 1)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Rebel, SpaceShip::Size::Big, Position(baseX + offsetX, 2)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Rebel, SpaceShip::Size::Small, Position(baseX, 3)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Rebel, SpaceShip::Size::Small, Position(baseX, 4)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Rebel, SpaceShip::Size::Big, Position(baseX + offsetX, 5)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Rebel, SpaceShip::Size::Small, Position(baseX, 6)));
                break;
            case Faction::Republic:
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Republic, SpaceShip::Size::Small, Position(baseX, 1)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Republic, SpaceShip::Size::Small, Position(baseX + offsetX, 2)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Republic, SpaceShip::Size::Big, Position(baseX + offsetX, 3)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Republic, SpaceShip::Size::Big, Position(baseX + offsetX, 4)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Republic, SpaceShip::Size::Small, Position(baseX + offsetX, 5)));
                player->AddSpaceShip(std::make_shared<SpaceShip>(playerIndex, Faction::Republic, SpaceShip::Size::Small, Position(baseX, 6)));
                break;
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }

        for (auto& vaisseau : player->GetSpaceShips())
        {
            m_map[vaisseau->GetPosition().GetX()][vaisseau->GetPosition().GetY()] = vaisseau;
        }
    }

    void MainWindow::SelectDestinationCase(const Position& position)
    {
        const U32& x = position.GetX();
        const U32& y = position.GetY();

        assert(m_selectioned->VerifyMove(position));
        if (m_map[x][y] == nullptr)
        {
            SoundManager::Instance().PlayMoveSound(m_selectioned->GetSize());
        }
        else
        {
            SoundManager::Instance().PlayShootSound(m_selectioned->GetSize());

            PlayerManager::Instance().GetPlayer(m_map[x][y]->GetOwner())->RemoveSpaceShip(m_map[x][y]);
            m_map[x][y] = nullptr;
        }

        m_map[m_selectioned->GetPosition().GetX()][m_selectioned->GetPosition().GetY()] = nullptr;
        m_selectioned->Move(position);
        m_map[m_selectioned->GetPosition().GetX()][m_selectioned->GetPosition().GetY()] = m_selectioned;
        m_selectioned = nullptr;

        if (m_turnIndexPlayer == 0)
        {
            m_turnIndexPlayer = 1;
        }
        else
        {
            m_turnIndexPlayer = 0;
        }

        UpdateButtons();
    }

    void MainWindow::ShowOptionsWindow()
    {
        OptionWindow::Instance().exec();
    }

    void MainWindow::ShowHelpButton()
    {
        HelpWindow::Instance().exec();
    }

    void MainWindow::SelectCase(const QString& text)
    {
        U32 xy = text.toUInt();
        U32 y = xy % 10;
        U32 x = (xy - y) / 10;

        if (m_selectioned == nullptr)
        {
            assert(m_map[x][y] != nullptr);
            assert(m_map[x][y]->GetOwner() == m_turnIndexPlayer);
            m_selectioned = m_map[x][y];
            UpdateButtons();
        }
        else
        {
            SelectDestinationCase(Position(x, y));
        }
    }
}
