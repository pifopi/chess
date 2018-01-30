#include "MenuWindow.h"

#include <QApplication>

//#include "vld.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Chess::MenuWindow::Instance().show();

    return app.exec();
}
