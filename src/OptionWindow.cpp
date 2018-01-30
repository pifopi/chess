#include "ImageManager.h"
#include "OptionWindow.h"
#include "SoundManager.h"

#include <QCheckBox>
#include <QBoxLayout>

namespace Chess
{
    OptionWindow& OptionWindow::Instance()
    {
        static OptionWindow instance;
        return instance;
    }

    OptionWindow::OptionWindow()
        : m_soundCheckBox(new QCheckBox("Activate the main sound"))
        , m_layout(new QVBoxLayout)
    {
        m_soundCheckBox->setChecked(false);
        QObject::connect(m_soundCheckBox, SIGNAL(stateChanged(int)), this, SLOT(PlaySound(int)));

        m_layout->addWidget(m_soundCheckBox);

        setLayout(m_layout);
        setWindowIcon(ImageManager::Instance().GetWindowIconImage());
    }

    void OptionWindow::PlaySound(const int& state)
    {
        switch (state)
        {
            case Qt::Unchecked:
                SoundManager::Instance().StopMainSound();
                break;
            case Qt::Checked:
                SoundManager::Instance().PlayMainSound();
                break;
            default:
                break;
        }
    }
}
