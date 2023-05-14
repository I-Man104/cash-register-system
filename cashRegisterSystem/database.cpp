#include "database.h"
Database::Database(const char* filename) {
    int rc = sqlite3_open(filename, &m_db);
    if (rc != SQLITE_OK) {
        // Handle error
    }
}

Database::~Database() {
    sqlite3_close(m_db);
}

void Database::initialize() {
    // Create table
    const char* createProdTable = "CREATE TABLE IF NOT EXISTS Products (id INTEGER PRIMARY KEY,name TEXT NOT NULL, quantity INTEGER NOT NULL, price TEXT NOT NULL, type TEXT NOT NULL);";
    const char* createCustomerTable = "CREATE TABLE IF NOT EXISTS Customers (id INTEGER PRIMARY KEY,name TEXT NOT NULL, phone_number TEXT NOT NULL, total_paid INTEGER NOT NULL, class TEXT NOT NULL);";

    char* errMsg;
    int rc = sqlite3_exec(m_db, createProdTable, NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        QMessageBox msg;
        msg.setText("Error in initializing database");
        msg.exec();
    }
    int rc2 = sqlite3_exec(m_db, createCustomerTable, NULL, NULL, &errMsg);
    if (rc2 != SQLITE_OK) {
        QMessageBox msg;
        msg.setText("Error in initializing database");
        msg.exec();
    }
}

void Database::insertCustomerRows(string name, string phone_number, int total_paid, string Class)
{
    int id = getRowCount(m_db, "Customers") + 1;
    const char* insertProduct = sqlite3_mprintf("INSERT INTO Customers(id, name, phone_number, total_paid, class) VALUES(%d, '%q', '%q', %d, '%q');", id, name.c_str(), phone_number.c_str(), total_paid, Class.c_str());
    char* errMsg;
    int rc = sqlite3_exec(m_db, insertProduct, NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        QMessageBox msg;
        msg.setText(errMsg);
        msg.exec();
    }
}

void Database::updateCustomerTotalPaid(string phone_number, float additional_pay, char type)
{
    sqlite3_stmt* stmt;
    const char* gettingTotalPaid = "SELECT total_paid FROM Customers WHERE phone_number = ?";

    int rc = sqlite3_prepare_v2(m_db, gettingTotalPaid, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        QMessageBox msg;
        msg.setText("updateCustomerTotalPaid prepare wrong");
        msg.exec();
        return;
    }

    rc = sqlite3_bind_text(stmt, 1, phone_number.c_str(), -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        QMessageBox msg;
        msg.setText(sqlite3_errmsg(m_db));
        msg.exec();
        return;
    }

    float current_total = 0.0f;
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
        current_total = static_cast<float>(sqlite3_column_double(stmt, 0));
    sqlite3_finalize(stmt);
    float new_total = 0;
    if(type=='+')
        new_total = current_total + additional_pay;
    else if(type=='-')
         new_total = current_total - additional_pay;

    const char* update_query = "UPDATE Customers SET total_paid = ? WHERE phone_number = ?";
    sqlite3_prepare_v2(m_db, update_query, -1, &stmt, NULL);
    sqlite3_bind_double(stmt, 1, new_total);
    sqlite3_bind_text(stmt, 2, phone_number.c_str(), -1, SQLITE_TRANSIENT);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        QMessageBox msg;
        msg.setText(sqlite3_errmsg(m_db));
        msg.exec();
        return;
    }
    sqlite3_finalize(stmt);
}

void Database::updateProductQuantity(string name, int additional_quantity, char type) {

    sqlite3_stmt* stmt;
    const char* totalQuantity = "SELECT quantity FROM products WHERE name = ?";
    int rc = sqlite3_prepare_v2(m_db, totalQuantity, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        QMessageBox msg;
        msg.setText("updateProductQuantity prepare wrong");
        msg.exec();
        return;
    }
    rc = sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        QMessageBox msg;
        msg.setText(sqlite3_errmsg(m_db));
        msg.exec();
        return;
    }

    int currentQuantity = 0;
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
        currentQuantity = static_cast<int>(sqlite3_column_double(stmt, 0));
    sqlite3_finalize(stmt);
    int new_Quantity = 0;
    if (type == '+')
        new_Quantity = currentQuantity + additional_quantity;
    else if (type == '-')
        new_Quantity = currentQuantity - additional_quantity;

    const char* update_query = "UPDATE products SET quantity = ? where name = ?";
    sqlite3_prepare_v2(m_db, update_query, -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, new_Quantity);
    sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_TRANSIENT);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        QMessageBox msg;
        msg.setText(sqlite3_errmsg(m_db));
        msg.exec();
        return;
    }
    sqlite3_finalize(stmt);
}

void Database::insertProdRows(string name, string price, int quantity, string type)
{
    int id = getRowCount(m_db, "Products") + 1;
    const char* insertProduct = sqlite3_mprintf("INSERT INTO Products(id, name, price, quantity, type) VALUES(%d, '%q', '%q', %d, '%q');", id, name.c_str(), price.c_str(), quantity, type.c_str());
    char* errMsg;
    int rc = sqlite3_exec(m_db, insertProduct, NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        QMessageBox msg;
        msg.setText("Error in inserting row into product database");
        msg.exec();
    }
}

int Database::getRowCount(sqlite3* db, const char* tableName) {
    int rowCount = 0;
    sqlite3_stmt* stmt;

    const char* query = sqlite3_mprintf("SELECT COUNT(*) FROM %Q;", tableName);

    if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            rowCount = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_free((void*)query);
    return rowCount;
}

void Database::DeleteProdRow(string name) {
    sqlite3_stmt* stmt;
    const char* delete_query = "DELETE FROM products WHERE name = ?";
    int rc = sqlite3_prepare_v2(m_db, delete_query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        // handle error
        return;
    }

    rc = sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        // handle error
        return;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        // handle error
        return;
    }

    sqlite3_finalize(stmt);

}

void Database::insertOrUpdateOperation(string name, int quantity, float price, char t)
{
    string type = (t == '+') ? "sell" : "retrieve";
    if (isRowExist(name, type)) {
        updateOperation(name, quantity, price, type);
    }
    else {
        insertOperation(name, quantity, price, type);
    }

}

bool Database::isRowExist(string name, string type) {
    std::stringstream ss;
    ss << "SELECT COUNT(*) FROM Operations WHERE name = ? AND type = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(m_db, ss.str().c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return false;
    }
    if (sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return false;
    }
    if (sqlite3_bind_text(stmt, 2, type.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return false;
    }
    bool exists = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        exists = count > 0;
    }
    sqlite3_finalize(stmt);
    return exists;
}

void Database::insertOperation(string name, int quantity, float price, string type) {
    int id = getRowCount(m_db, "Operations") + 1;
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(m_db, "INSERT INTO operations (id, name, quantity, price, type) VALUES (?, ?, ?, ?, ?)", -1, &stmt, NULL) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_bind_int(stmt, 1, id) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_bind_int(stmt, 3, quantity) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_bind_double(stmt, 4, price) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_bind_text(stmt, 5, type.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}

void Database::updateOperation(string name, int quantity, float price, string type) {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(m_db, "UPDATE operations SET price = price + ?, quantity = quantity + ? WHERE name = ? AND type = ?", -1, &stmt, NULL) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_bind_double(stmt, 1, price) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_bind_int(stmt, 2, quantity) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_bind_text(stmt, 3, name.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_bind_text(stmt, 4, type.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return;
    }
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
}
void Database::SelectAllItemsFromTable(string type) {
   

}
