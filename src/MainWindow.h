#pragma once

#include "Position.h"
#include "SpaceShip.h"
#include "Utils.h"

#include <array>
#include <memory>
#include <QWidget>

class QGridLayout;
class QHBoxLayout;
class QPushButton;
class QSignalMapper;
class QVBoxLayout;

namespace
{
    static const Chess::U32 k_mapSize = 8;
}

namespace Chess
{
    class MainWindow
        : public QWidget
        , public NonCopyable
    {
        Q_OBJECT
    public:
        static MainWindow& Instance();

    private:
        MainWindow();
        ~MainWindow();

        void InitPlayer(const PlayerIndex& playerIndex);
        void SelectDestinationCase(const Position& position);
        void UpdateButtons();

        PlayerIndex m_turnIndexPlayer;
        std::array<std::array<std::shared_ptr<SpaceShip>, k_mapSize>, k_mapSize> m_map;
        std::shared_ptr<SpaceShip> m_selectioned;


        std::array<QPushButton*, 2> m_playerLabels;
        QPushButton* m_optionsButton;
        QPushButton* m_helpButton;
        QSignalMapper* m_signalMapper;
        QGridLayout* m_mapLayout;
        std::array<std::array<QPushButton*, k_mapSize>, k_mapSize> m_buttons;
        QWidget* m_description;
        QVBoxLayout* m_descriptionLayout;
        QHBoxLayout* m_layout;

        private slots:
        void ShowOptionsWindow();
        void ShowHelpButton();
        void SelectCase(const QString& text);
    };
}
