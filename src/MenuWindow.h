#pragma once

#include "Utils.h"

#include <QWidget>

class QPushButton;
class QVBoxLayout;

namespace Chess
{
    class MenuWindow
        : public QWidget
        , public NonCopyable
    {
        Q_OBJECT
    public:
        static MenuWindow& Instance();

    private:
        MenuWindow();

        QPushButton* m_showPlayerSelectionWindowButton;
        QPushButton* m_showOptionsWindowButton;
        QPushButton* m_showHelpWindowButton;
        QVBoxLayout* m_layout;

        private slots:
        void ShowPlayerSelectionWindow();
        void ShowOptionsWindow();
        void ShowHelpWindow();
    };
}
