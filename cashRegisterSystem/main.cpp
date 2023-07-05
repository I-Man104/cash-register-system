#include "cashRegisterSystem.h"
#include "database.h"
#include <QtWidgets/QApplication>
#include <QFile>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    cashRegisterSystem w;
    Database* db = new Database("mydatabase.db");
    db->initialize();
    w.show();

    return a.exec();
}