#include "cashRegisterSystem.h"
#include "database.h"
#include <QtWidgets/QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cashRegisterSystem w;
    Database* db = new Database("mydatabase.db");
    db->initialize();
    Database bs("mydatabase.db");
    w.show();
   // bs.insertProdRows("chips", "5", 30, "snacks");
    //bs.DeleteProdRow("chips");
    QFile styleSheetFile("./Integrid.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    w.setStyleSheet(styleSheet);

    return a.exec();
}
