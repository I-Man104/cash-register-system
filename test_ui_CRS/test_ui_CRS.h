#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test_ui_CRS.h"

class test_ui_CRS : public QMainWindow
{
    Q_OBJECT

public:
    test_ui_CRS(QWidget *parent = nullptr);
    ~test_ui_CRS();

private:
    Ui::test_ui_CRSClass* ui;
};
