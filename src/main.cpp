#include "MenuWindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Chess::MenuWindow::Instance().show();

    return app.exec();
}
