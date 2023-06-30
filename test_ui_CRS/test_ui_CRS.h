#pragma once

#include <QtWidgets/QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <sstream>
#include "sqlite/sqlite3.h"
#include "ui_test_ui_CRS.h"


class test_ui_CRS : public QMainWindow
{
    Q_OBJECT

public:
    test_ui_CRS(QWidget *parent = nullptr);
    ~test_ui_CRS();
private:
    float TotalBalanceForOperation = 0;
    float TotalBalanceForOperationDiscounted = 0;
    int i = 0;
    QVector<QPushButton*> Delete_button;
    


    void Delete_On_Click(QPushButton*, float, QString, int, QLabel*, QLabel*, QPushButton*, QLineEdit*);





    sqlite3* m_ProductsDB;
    Ui::test_ui_CRSClass* m_ui;
    QList<QLabel*> categories;
    void showCategoriesList();
    void populateProductList(QVBoxLayout*, QLabel*, QVBoxLayout*, QLabel*, QLabel*, QScrollArea*, QPushButton*, QLineEdit*);
    void showAllProducts();
    QLabel* makeLabel(QString content);
public slots:
    void itemClickedHandler(int item);

    void on_name_button_clicked(double, QString, float, QVBoxLayout*, QLabel*, QLabel*, QScrollArea*, QPushButton*, QLineEdit*);
};
