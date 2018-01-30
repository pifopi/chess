#pragma once

#include "Utils.h"

#include <array>
#include <QDialog>

class QLabel;
class QPushButton;
class QVBoxLayout;

namespace Chess
{
    class HelpWindow
        : public QDialog
        , public NonCopyable
    {
        Q_OBJECT
    public:
        static HelpWindow& Instance();

    private:
        HelpWindow();

        U32 m_tipNumber;
        std::array<QString, 5> m_tips;

        QPushButton* m_yodaButton;
        QLabel* m_text;
        QPushButton* m_nextInstruction;
        QVBoxLayout* m_layout;

        private slots:
        void YodaButtonClicked();
        void NextInstructionButtonClicked();
    };
}
