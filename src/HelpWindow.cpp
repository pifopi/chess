#include "HelpWindow.h"
#include "ImageManager.h"

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

namespace Chess
{
    HelpWindow& HelpWindow::Instance()
    {
        static HelpWindow instance;
        return instance;
    }

    HelpWindow::HelpWindow()
        : m_tipNumber(0)
        , m_tips
    {
        "May the Force be with you.",
        "Do or do not. There is no try.",
        "When nine hundred years old you reach, look as good you will not.",
        "If no mistakes you have made yet losing you are... a different game you should play.",
        "When you look at the dark side, careful you must be... for the dark side looks back."
    }
        , m_yodaButton(new QPushButton)
        , m_text(new QLabel(m_tips[0]))
        , m_nextInstruction(new QPushButton("Next Instruction"))
        , m_layout(new QVBoxLayout)
    {
        m_yodaButton->setIcon(QIcon("yoda.png"));
        m_yodaButton->setIconSize(QSize(514, 385));
        QObject::connect(m_yodaButton, SIGNAL(clicked()), this, SLOT(YodaButtonClicked()));

        QObject::connect(m_nextInstruction, SIGNAL(clicked()), this, SLOT(NextInstructionButtonClicked()));

        m_layout->addWidget(m_yodaButton);
        m_layout->addWidget(m_text);
        m_layout->addWidget(m_nextInstruction);

        setLayout(m_layout);
        setWindowIcon(ImageManager::Instance().GetWindowIconImage());
    }

    void HelpWindow::YodaButtonClicked()
    {
        m_text->setText("Duct Tape... The force is like.\nBoth a light side and a dark side it has.\nBinds the universe together it does !");
    }

    void HelpWindow::NextInstructionButtonClicked()
    {
        m_tipNumber = (m_tipNumber + 1) % m_tips.size();
        m_text->setText(m_tips.at(m_tipNumber));
    }
}
