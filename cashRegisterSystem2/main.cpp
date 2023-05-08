#include "cashRegisterSystem.h"
#include <QtWidgets/QApplication>
#include<QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cashRegisterSystem w;
    w.show();
    QFile styleSheetFile("./Integrid.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    w.setStyleSheet(styleSheet);
    return a.exec();
}
