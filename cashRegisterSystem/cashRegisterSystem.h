#pragma once
#ifndef CASH_REGISTER_SYSTEM_H
#define CASH_REGISTER_SYSTEM_H

#include <QtWidgets/QWidget>
#include <QGridLayout>
#include <QMessageBox>
#include <QString>
#include <Qlabel>
#include <QPushButton>
#include "ui_cashRegisterSystem.h"
#include "sqlite/sqlite3.h"
#include <QtCore>


using namespace std;

class cashRegisterSystem : public QWidget
{
    Q_OBJECT

public:
    cashRegisterSystem(QWidget* parent = nullptr);
    ~cashRegisterSystem();
    QHash<QPushButton*, QHBoxLayout*> mbuttonToLayoutMap;


private:
    Ui::TestShitClass* m_ui;
    sqlite3* m_db;
    bool m_type[4];
    void populateProductList(QVBoxLayout*, const char*);

private slots:
    void on_snacks_clicked();
    void on_vegetables_clicked();
    void on_fruits_clicked();
    void on_drinks_clicked();
    void on_login_btn_clicked();
    void on_search_clicked();
    void on_back_clicked();
};
#endif // CASH_REGISTER_SYSTEM_H