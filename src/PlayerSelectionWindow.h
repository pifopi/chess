#pragma once

#include "Utils.h"

#include <QWidget>

class QHBoxLayout;
class QLabel;
class QLineEdit;
class QPushButton;
class QVBoxLayout;

namespace Chess
{
    class PlayerSelectionWindow
        : public QWidget
        , public NonCopyable
    {
        Q_OBJECT
    public:
        static PlayerSelectionWindow& Instance();

    private:
        PlayerSelectionWindow();

        void UpdateFaction(const Faction& faction);

        Faction m_faction;

        QLabel* m_playerNameLabel;
        QLineEdit* m_playerName;
        QLabel* m_factionLabel;
        QPushButton* m_leftButton;
        QPushButton* m_factionButton;
        QPushButton* m_rightButton;
        QLabel* m_factionDescriptionLabel;
        QPushButton* m_nextButton;
        QPushButton* m_quitButton;
        QHBoxLayout* m_layoutFaction;
        QVBoxLayout* m_layout;

        private slots:
        void LeftButtonClicked();
        void RightButtonClicked();
        void NextButtonClicked();
    };
}
