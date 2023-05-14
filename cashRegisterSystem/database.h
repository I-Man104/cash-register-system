#ifndef DATABASE_H
#define DATABASE_H
#include "cashRegisterSystem.h"
#include <QMessageBox>
#include "./sqlite/sqlite3.h"
#include <string>
using namespace std;
class Database {
public:
    Database(const char* filename);
    ~Database();
    void initialize();
    void insertCustomerRows(string, string, int, string);
    void insertProdRows(string, string, int, string);
    void updateCustomerTotalPaid(string, float,char);
    void updateProductQuantity(string, int, char);
    void DeleteProdRow(string);
    private:
    sqlite3* m_db;
    int getRowCount(sqlite3*, const char*);
};

#endif /* DATABASE_H */