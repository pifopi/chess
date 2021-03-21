#pragma once

#include "Utils.h"

#include <QDialog>

class QCheckBox;
class QVBoxLayout;

namespace Chess
{
    class OptionWindow
        : public QDialog
        , public NonCopyable
    {
        Q_OBJECT
    public:
        static OptionWindow& Instance();

    private:
        OptionWindow();

        QCheckBox* m_soundCheckBox;
        QVBoxLayout* m_layout;

    private slots:
        void PlaySound(const int& state);
    };
}
