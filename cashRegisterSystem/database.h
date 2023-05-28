#ifndef DATABASE_H
#define DATABASE_H
#include "cashRegisterSystem.h"
#include <QMessageBox>
#include "./sqlite/sqlite3.h"
#include <string>

#include <chrono>
#include <iomanip>
#include <sstream>

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
    void insertOrUpdateOperation(string, int, float, string, char);
    void DeleteProdRow(string);
    bool checkPhoneNumber(const string, QString& );
    void editProductPrice(string, string);
    string selectProductPrice(string);

    static string getTodayDate();
    private:
    sqlite3* m_db;

    void insertOperation(string, int, float, string, string, string);
    void updateOperation(string, int, float, string, string, string);
    bool isRowExist(string, string, string, string);

};

#endif /* DATABASE_H */