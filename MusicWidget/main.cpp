#include "AllWidget.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("G:\\Widget\\favicon.ico"));
    Widget w;
    w.show();

    return a.exec();
}
