#include "test_ui_CRS.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    test_ui_CRS w;
    w.show();
    return a.exec();
}
