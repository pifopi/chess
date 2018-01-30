#include "ImageManager.h"
#include "MainWindow.h"
#include "Player.h"
#include "PlayerManager.h"
#include "PlayerSelectionWindow.h"

#include <cassert>
#include <QApplication>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Chess
{
    PlayerSelectionWindow& PlayerSelectionWindow::Instance()
    {
        static PlayerSelectionWindow instance;
        return instance;
    }

    PlayerSelectionWindow::PlayerSelectionWindow()
        : m_playerNameLabel(new QLabel("Player 1, what is your name ?"))
        , m_playerName(new QLineEdit("Player"))
        , m_factionLabel(new QLabel)
        , m_leftButton(new QPushButton)
        , m_factionButton(new QPushButton)
        , m_rightButton(new QPushButton)
        , m_factionDescriptionLabel(new QLabel)
        , m_nextButton(new QPushButton("&Next"))
        , m_quitButton(new QPushButton("&Quit"))
        , m_layoutFaction(new QHBoxLayout)
        , m_layout(new QVBoxLayout)
    {
        m_playerName->setMaximumWidth(300);

        UpdateFaction(Faction::Empire);

        m_leftButton->setIcon(QIcon("LeftArrow.png"));
        QObject::connect(m_leftButton, SIGNAL(clicked()), this, SLOT(LeftButtonClicked()));

        m_factionButton->setIconSize(QSize(400, 400));

        m_rightButton->setIcon(QIcon("RightArrow.png"));
        QObject::connect(m_rightButton, SIGNAL(clicked()), this, SLOT(RightButtonClicked()));

        m_layoutFaction->addWidget(m_leftButton);
        m_layoutFaction->addWidget(m_factionButton);
        m_layoutFaction->addWidget(m_rightButton);

        QObject::connect(m_nextButton, SIGNAL(clicked()), this, SLOT(NextButtonClicked()));

        QObject::connect(m_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

        m_layout->addWidget(m_playerNameLabel, 0, Qt::AlignCenter);
        m_layout->addWidget(m_playerName, 0, Qt::AlignCenter);
        m_layout->addWidget(m_factionLabel, 0, Qt::AlignCenter);
        m_layout->addLayout(m_layoutFaction);
        m_layout->addWidget(m_factionDescriptionLabel, 0, Qt::AlignCenter);
        m_layout->addWidget(m_nextButton);
        m_layout->addWidget(m_quitButton);

        setLayout(m_layout);
        setWindowIcon(ImageManager::Instance().GetWindowIconImage());
    }

    void PlayerSelectionWindow::UpdateFaction(const Faction& faction)
    {
        m_faction = faction;
        m_factionButton->setIcon(ImageManager::Instance().GetFactionImage(m_faction));
        switch (m_faction)
        {
            case Faction::Empire:
                m_factionLabel->setText("Empire");
                m_factionDescriptionLabel->setText("L'empire utilise le coté obscur de la force avec ses fameux Sith ! Vive Dark Vador. L'empire dispose de 6 vaisseaux lourds et de 2 vaisseaux légers");
                break;
            case Faction::Rebel:
                m_factionLabel->setText("Rebel");
                m_factionDescriptionLabel->setText("Les rebelles vous surprendront par leur puissance et Han Solo vous aimera bien ! Les rebelles disposent de 2 vaisseaux lourds et de 4 vaisseaux légers");
                break;
            case Faction::Republic:
                m_factionLabel->setText("Republic");
                m_factionDescriptionLabel->setText("La république est faible, vous voulez vraiment jouer avec eux ??? La république dispose de 2 vaisseaux lourds et de 4 vaisseaux légers");
                break;
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }
    }

    void PlayerSelectionWindow::LeftButtonClicked()
    {
        switch (m_faction)
        {
            case Faction::Empire:
                UpdateFaction(Faction::Republic);
                break;
            case Faction::Rebel:
                UpdateFaction(Faction::Empire);
                break;
            case Faction::Republic:
                UpdateFaction(Faction::Rebel);
                break;
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }
    }

    void PlayerSelectionWindow::RightButtonClicked()
    {
        switch (m_faction)
        {
            case Faction::Empire:
                UpdateFaction(Faction::Rebel);
                break;
            case Faction::Rebel:
                UpdateFaction(Faction::Republic);
                break;
            case Faction::Republic:
                UpdateFaction(Faction::Empire);
                break;
            default:
                assert(false);
                exit(EXIT_FAILURE);
        }
    }

    void PlayerSelectionWindow::NextButtonClicked()
    {
        if (PlayerManager::Instance().GetPlayer(0) == nullptr)
        {
            PlayerManager::Instance().SetPlayer(0, std::make_shared<Player>(m_faction, m_playerName->text()));

            m_playerNameLabel->setText("Player 2, what is your name ?");
            m_playerName->setText("Player");
            UpdateFaction(Faction::Empire);
        }
        else
        {
            PlayerManager::Instance().SetPlayer(1, std::make_shared<Player>(m_faction, m_playerName->text()));

            hide();
            MainWindow::Instance().show();
        }
    }
}
