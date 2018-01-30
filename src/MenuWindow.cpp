#include "HelpWindow.h"
#include "ImageManager.h"
#include "MenuWindow.h"
#include "OptionWindow.h"
#include "PlayerSelectionWindow.h"

#include <QBoxLayout>
#include <QPushButton>

namespace Chess
{
    MenuWindow& MenuWindow::Instance()
    {
        static MenuWindow instance;
        return instance;
    }

    MenuWindow::MenuWindow()
        : m_showPlayerSelectionWindowButton(new QPushButton("&Start"))
        , m_showOptionsWindowButton(new QPushButton("&Options"))
        , m_showHelpWindowButton(new QPushButton("&Help"))
        , m_layout(new QVBoxLayout)

    {
        QFont police = QFont("Comic Sans MS", 80);

        m_showPlayerSelectionWindowButton->setFont(police);
        QObject::connect(m_showPlayerSelectionWindowButton, SIGNAL(clicked()), this, SLOT(ShowPlayerSelectionWindow()));

        m_showOptionsWindowButton->setFont(police);
        QObject::connect(m_showOptionsWindowButton, SIGNAL(clicked()), this, SLOT(ShowOptionsWindow()));

        m_showHelpWindowButton->setFont(police);
        QObject::connect(m_showHelpWindowButton, SIGNAL(clicked()), this, SLOT(ShowHelpWindow()));

        m_layout->addWidget(m_showPlayerSelectionWindowButton);
        m_layout->addWidget(m_showOptionsWindowButton);
        m_layout->addWidget(m_showHelpWindowButton);

        setLayout(m_layout);
        setWindowIcon(ImageManager::Instance().GetWindowIconImage());
    }

    void MenuWindow::ShowPlayerSelectionWindow()
    {
        hide();
        PlayerSelectionWindow::Instance().show();
    }

    void MenuWindow::ShowOptionsWindow()
    {
        OptionWindow::Instance().exec();
    }

    void MenuWindow::ShowHelpWindow()
    {
        HelpWindow::Instance().exec();
    }
}
