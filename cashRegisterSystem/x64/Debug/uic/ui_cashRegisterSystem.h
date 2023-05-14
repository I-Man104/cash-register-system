/********************************************************************************
** Form generated from reading UI file 'cashRegisterSystem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHREGISTERSYSTEM_H
#define UI_CASHREGISTERSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cashRegisterSystem2Class
{
public:
    QWidget *centralWidget;
    QStackedWidget *formsStackedWidget;
    QWidget *login;
    QLineEdit *username_field;
    QLabel *passwod_label;
    QPushButton *login_btn;
    QLineEdit *password_field;
    QLabel *username_label;
    QWidget *main_form;
    QPushButton *snacks;
    QStackedWidget *ProductsStackedWidget;
    QWidget *page_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaSnacksContents;
    QWidget *page_4;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaDrinksContents;
    QWidget *page_5;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaVegetablesContents;
    QWidget *page_6;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaFruitsContents;
    QPushButton *fruits;
    QPushButton *vegetables;
    QPushButton *drinks;
    QPushButton *AddNewCustomer;
    QFrame *frame;
    QScrollArea *scrollArea_9;
    QWidget *cartContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *cartVerticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *sell;
    QPushButton *retrieve;
    QLineEdit *phone_number;
    QLabel *label;
    QPushButton *cancel_order;
    QLabel *price_before_const;
    QLabel *price_after_const;
    QLabel *price_before;
    QLabel *price_after;
    QPushButton *check_discount;
    QPushButton *customers;
    QWidget *admin_form;
    QFrame *control_frame;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_3;
    QPlainTextEdit *item_name_item;
    QLabel *label_4;
    QPlainTextEdit *item_price_item;
    QPlainTextEdit *item_quantity_item;
    QPushButton *add_item;
    QPushButton *remove_item;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *remove_quantity;
    QPushButton *add_quantity;
    QComboBox *item_name_quantity;
    QLabel *label_20;
    QPlainTextEdit *item_quantity_quantity;
    QLabel *label_21;
    QComboBox *item_type_item;
    QLabel *label_22;
    QFrame *total_operations_frame;
    QScrollArea *scrollArea_7;
    QWidget *total_operations_contents;
    QFrame *return_operations_frame;
    QScrollArea *scrollArea_6;
    QWidget *return_operations_contents;
    QFrame *sell_operations_frame;
    QScrollArea *scrollArea_5;
    QWidget *sell_operations_contents;
    QLabel *label_23;
    QLabel *label_25;
    QLabel *label_24;
    QTextBrowser *day_total_income;
    QLabel *label_26;
    QWidget *creating_customer_account;
    QPushButton *add_new;
    QPushButton *go_back;
    QLineEdit *new_customer_name;
    QLineEdit *new_customer_phone;
    QLabel *nameLable;
    QLabel *phoneLable;
    QLabel *classLable;
    QComboBox *class_box;
    QWidget *page;
    QLineEdit *nameSearch;
    QLineEdit *phoneSearch;
    QComboBox *ranksearch;
    QPushButton *Search_btn;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QScrollArea *results;
    QWidget *scrollAreaWidgetContents;
    QTableView *tableView;
    QPushButton *backFromCustomers;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *cashRegisterSystem2Class)
    {
        if (cashRegisterSystem2Class->objectName().isEmpty())
            cashRegisterSystem2Class->setObjectName("cashRegisterSystem2Class");
        cashRegisterSystem2Class->resize(1261, 747);
        centralWidget = new QWidget(cashRegisterSystem2Class);
        centralWidget->setObjectName("centralWidget");
        formsStackedWidget = new QStackedWidget(centralWidget);
        formsStackedWidget->setObjectName("formsStackedWidget");
        formsStackedWidget->setGeometry(QRect(0, 0, 1251, 691));
        login = new QWidget();
        login->setObjectName("login");
        username_field = new QLineEdit(login);
        username_field->setObjectName("username_field");
        username_field->setGeometry(QRect(460, 150, 200, 31));
        passwod_label = new QLabel(login);
        passwod_label->setObjectName("passwod_label");
        passwod_label->setGeometry(QRect(700, 210, 91, 31));
        passwod_label->setStyleSheet(QString::fromUtf8("font-weight:bold;\n"
"font-size:18px;"));
        login_btn = new QPushButton(login);
        login_btn->setObjectName("login_btn");
        login_btn->setGeometry(QRect(510, 280, 100, 61));
        login_btn->setStyleSheet(QString::fromUtf8("font-weight:bold;\n"
"font-size:18px;"));
        password_field = new QLineEdit(login);
        password_field->setObjectName("password_field");
        password_field->setGeometry(QRect(460, 210, 201, 31));
        password_field->setEchoMode(QLineEdit::Normal);
        username_label = new QLabel(login);
        username_label->setObjectName("username_label");
        username_label->setGeometry(QRect(680, 150, 111, 31));
        username_label->setStyleSheet(QString::fromUtf8("font-weight:bold;\n"
"font-size:18px;\n"
""));
        formsStackedWidget->addWidget(login);
        main_form = new QWidget();
        main_form->setObjectName("main_form");
        snacks = new QPushButton(main_form);
        snacks->setObjectName("snacks");
        snacks->setGeometry(QRect(930, 20, 71, 41));
        snacks->setStyleSheet(QString::fromUtf8(""));
        ProductsStackedWidget = new QStackedWidget(main_form);
        ProductsStackedWidget->setObjectName("ProductsStackedWidget");
        ProductsStackedWidget->setGeometry(QRect(440, 80, 801, 481));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 0, 771, 481));
        scrollArea->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaSnacksContents = new QWidget();
        scrollAreaSnacksContents->setObjectName("scrollAreaSnacksContents");
        scrollAreaSnacksContents->setGeometry(QRect(0, 0, 769, 479));
        scrollArea->setWidget(scrollAreaSnacksContents);
        ProductsStackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        scrollArea_2 = new QScrollArea(page_4);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(10, 0, 771, 481));
        scrollArea_2->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaDrinksContents = new QWidget();
        scrollAreaDrinksContents->setObjectName("scrollAreaDrinksContents");
        scrollAreaDrinksContents->setGeometry(QRect(0, 0, 769, 479));
        scrollArea_2->setWidget(scrollAreaDrinksContents);
        ProductsStackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        scrollArea_3 = new QScrollArea(page_5);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setGeometry(QRect(10, 0, 771, 481));
        scrollArea_3->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaVegetablesContents = new QWidget();
        scrollAreaVegetablesContents->setObjectName("scrollAreaVegetablesContents");
        scrollAreaVegetablesContents->setGeometry(QRect(0, 0, 769, 479));
        scrollArea_3->setWidget(scrollAreaVegetablesContents);
        ProductsStackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        scrollArea_4 = new QScrollArea(page_6);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setGeometry(QRect(10, 0, 771, 481));
        scrollArea_4->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaFruitsContents = new QWidget();
        scrollAreaFruitsContents->setObjectName("scrollAreaFruitsContents");
        scrollAreaFruitsContents->setGeometry(QRect(0, 0, 769, 479));
        scrollArea_4->setWidget(scrollAreaFruitsContents);
        ProductsStackedWidget->addWidget(page_6);
        fruits = new QPushButton(main_form);
        fruits->setObjectName("fruits");
        fruits->setGeometry(QRect(750, 20, 71, 41));
        fruits->setStyleSheet(QString::fromUtf8(""));
        vegetables = new QPushButton(main_form);
        vegetables->setObjectName("vegetables");
        vegetables->setGeometry(QRect(840, 20, 71, 41));
        vegetables->setStyleSheet(QString::fromUtf8(""));
        drinks = new QPushButton(main_form);
        drinks->setObjectName("drinks");
        drinks->setGeometry(QRect(660, 20, 81, 41));
        drinks->setStyleSheet(QString::fromUtf8(""));
        AddNewCustomer = new QPushButton(main_form);
        AddNewCustomer->setObjectName("AddNewCustomer");
        AddNewCustomer->setGeometry(QRect(450, 580, 161, 41));
        frame = new QFrame(main_form);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 80, 361, 561));
        frame->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        scrollArea_9 = new QScrollArea(frame);
        scrollArea_9->setObjectName("scrollArea_9");
        scrollArea_9->setGeometry(QRect(0, 0, 361, 411));
        scrollArea_9->setWidgetResizable(true);
        cartContents = new QWidget();
        cartContents->setObjectName("cartContents");
        cartContents->setGeometry(QRect(0, 0, 359, 409));
        verticalLayoutWidget = new QWidget(cartContents);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 361, 411));
        cartVerticalLayout = new QVBoxLayout(verticalLayoutWidget);
        cartVerticalLayout->setSpacing(6);
        cartVerticalLayout->setContentsMargins(11, 11, 11, 11);
        cartVerticalLayout->setObjectName("cartVerticalLayout");
        cartVerticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        cartVerticalLayout->addItem(verticalSpacer);

        scrollArea_9->setWidget(cartContents);
        sell = new QPushButton(frame);
        sell->setObjectName("sell");
        sell->setGeometry(QRect(230, 500, 120, 31));
        retrieve = new QPushButton(frame);
        retrieve->setObjectName("retrieve");
        retrieve->setGeometry(QRect(130, 500, 101, 31));
        phone_number = new QLineEdit(frame);
        phone_number->setObjectName("phone_number");
        phone_number->setGeometry(QRect(100, 420, 171, 31));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 420, 71, 31));
        label->setStyleSheet(QString::fromUtf8("border: none;"));
        cancel_order = new QPushButton(frame);
        cancel_order->setObjectName("cancel_order");
        cancel_order->setGeometry(QRect(10, 500, 101, 31));
        price_before_const = new QLabel(frame);
        price_before_const->setObjectName("price_before_const");
        price_before_const->setGeometry(QRect(238, 450, 111, 31));
        price_before_const->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-size: 14px"));
        price_after_const = new QLabel(frame);
        price_after_const->setObjectName("price_after_const");
        price_after_const->setGeometry(QRect(60, 450, 111, 31));
        price_after_const->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: #c92a2a;\n"
"font-weight: bold;\n"
"font-size: 14px;"));
        price_before = new QLabel(frame);
        price_before->setObjectName("price_before");
        price_before->setGeometry(QRect(180, 450, 61, 31));
        price_before->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-size: 14px"));
        price_after = new QLabel(frame);
        price_after->setObjectName("price_after");
        price_after->setGeometry(QRect(10, 450, 51, 31));
        price_after->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: #c92a2a;\n"
"font-weight: bold;\n"
"font-size: 14px;"));
        check_discount = new QPushButton(frame);
        check_discount->setObjectName("check_discount");
        check_discount->setGeometry(QRect(10, 420, 71, 31));
        customers = new QPushButton(main_form);
        customers->setObjectName("customers");
        customers->setGeometry(QRect(1060, 580, 161, 41));
        formsStackedWidget->addWidget(main_form);
        admin_form = new QWidget();
        admin_form->setObjectName("admin_form");
        control_frame = new QFrame(admin_form);
        control_frame->setObjectName("control_frame");
        control_frame->setGeometry(QRect(10, 30, 1231, 201));
        control_frame->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));
        control_frame->setFrameShape(QFrame::StyledPanel);
        control_frame->setFrameShadow(QFrame::Raised);
        line = new QFrame(control_frame);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 80, 1231, 20));
        line->setStyleSheet(QString::fromUtf8("border-top:1px;"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(control_frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1080, 10, 131, 81));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"border:none;"));
        label_3 = new QLabel(control_frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1080, 110, 131, 81));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"border:none;"));
        item_name_item = new QPlainTextEdit(control_frame);
        item_name_item->setObjectName("item_name_item");
        item_name_item->setGeometry(QRect(880, 40, 151, 41));
        label_4 = new QLabel(control_frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(960, 10, 71, 20));
        label_4->setStyleSheet(QString::fromUtf8("border: none;"));
        item_price_item = new QPlainTextEdit(control_frame);
        item_price_item->setObjectName("item_price_item");
        item_price_item->setGeometry(QRect(690, 40, 151, 41));
        item_quantity_item = new QPlainTextEdit(control_frame);
        item_quantity_item->setObjectName("item_quantity_item");
        item_quantity_item->setGeometry(QRect(500, 40, 151, 41));
        add_item = new QPushButton(control_frame);
        add_item->setObjectName("add_item");
        add_item->setGeometry(QRect(30, 10, 181, 31));
        remove_item = new QPushButton(control_frame);
        remove_item->setObjectName("remove_item");
        remove_item->setGeometry(QRect(30, 60, 181, 31));
        label_5 = new QLabel(control_frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(770, 10, 71, 20));
        label_5->setStyleSheet(QString::fromUtf8("border: none;"));
        label_6 = new QLabel(control_frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(580, 10, 71, 20));
        label_6->setStyleSheet(QString::fromUtf8("border: none;"));
        label_7 = new QLabel(control_frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(390, 10, 71, 20));
        label_7->setStyleSheet(QString::fromUtf8("border: none;"));
        remove_quantity = new QPushButton(control_frame);
        remove_quantity->setObjectName("remove_quantity");
        remove_quantity->setGeometry(QRect(30, 160, 181, 31));
        add_quantity = new QPushButton(control_frame);
        add_quantity->setObjectName("add_quantity");
        add_quantity->setGeometry(QRect(30, 110, 181, 31));
        item_name_quantity = new QComboBox(control_frame);
        item_name_quantity->setObjectName("item_name_quantity");
        item_name_quantity->setGeometry(QRect(690, 140, 341, 41));
        label_20 = new QLabel(control_frame);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(950, 110, 71, 20));
        label_20->setStyleSheet(QString::fromUtf8("border: none;"));
        item_quantity_quantity = new QPlainTextEdit(control_frame);
        item_quantity_quantity->setObjectName("item_quantity_quantity");
        item_quantity_quantity->setGeometry(QRect(500, 140, 151, 41));
        label_21 = new QLabel(control_frame);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(570, 110, 71, 20));
        label_21->setStyleSheet(QString::fromUtf8("border: none;"));
        item_type_item = new QComboBox(control_frame);
        item_type_item->setObjectName("item_type_item");
        item_type_item->setGeometry(QRect(310, 40, 151, 41));
        label_22 = new QLabel(admin_form);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(1070, 0, 161, 20));
        label_22->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;"));
        total_operations_frame = new QFrame(admin_form);
        total_operations_frame->setObjectName("total_operations_frame");
        total_operations_frame->setGeometry(QRect(10, 280, 401, 341));
        total_operations_frame->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));
        total_operations_frame->setFrameShape(QFrame::StyledPanel);
        total_operations_frame->setFrameShadow(QFrame::Raised);
        scrollArea_7 = new QScrollArea(total_operations_frame);
        scrollArea_7->setObjectName("scrollArea_7");
        scrollArea_7->setGeometry(QRect(0, 0, 401, 341));
        scrollArea_7->setWidgetResizable(true);
        total_operations_contents = new QWidget();
        total_operations_contents->setObjectName("total_operations_contents");
        total_operations_contents->setGeometry(QRect(0, 0, 399, 339));
        scrollArea_7->setWidget(total_operations_contents);
        return_operations_frame = new QFrame(admin_form);
        return_operations_frame->setObjectName("return_operations_frame");
        return_operations_frame->setGeometry(QRect(420, 280, 411, 341));
        return_operations_frame->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));
        return_operations_frame->setFrameShape(QFrame::StyledPanel);
        return_operations_frame->setFrameShadow(QFrame::Raised);
        scrollArea_6 = new QScrollArea(return_operations_frame);
        scrollArea_6->setObjectName("scrollArea_6");
        scrollArea_6->setGeometry(QRect(0, 0, 411, 341));
        scrollArea_6->setWidgetResizable(true);
        return_operations_contents = new QWidget();
        return_operations_contents->setObjectName("return_operations_contents");
        return_operations_contents->setGeometry(QRect(0, 0, 409, 339));
        scrollArea_6->setWidget(return_operations_contents);
        sell_operations_frame = new QFrame(admin_form);
        sell_operations_frame->setObjectName("sell_operations_frame");
        sell_operations_frame->setGeometry(QRect(840, 280, 401, 341));
        sell_operations_frame->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));
        sell_operations_frame->setFrameShape(QFrame::StyledPanel);
        sell_operations_frame->setFrameShadow(QFrame::Raised);
        scrollArea_5 = new QScrollArea(sell_operations_frame);
        scrollArea_5->setObjectName("scrollArea_5");
        scrollArea_5->setGeometry(QRect(0, 0, 401, 341));
        scrollArea_5->setWidgetResizable(true);
        sell_operations_contents = new QWidget();
        sell_operations_contents->setObjectName("sell_operations_contents");
        sell_operations_contents->setGeometry(QRect(0, 0, 399, 339));
        scrollArea_5->setWidget(sell_operations_contents);
        label_23 = new QLabel(admin_form);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(1130, 240, 111, 31));
        label_23->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;"));
        label_25 = new QLabel(admin_form);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(700, 240, 131, 31));
        label_25->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;"));
        label_24 = new QLabel(admin_form);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(160, 240, 251, 31));
        label_24->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;"));
        day_total_income = new QTextBrowser(admin_form);
        day_total_income->setObjectName("day_total_income");
        day_total_income->setGeometry(QRect(10, 640, 261, 41));
        label_26 = new QLabel(admin_form);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(280, 640, 101, 41));
        label_26->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;"));
        formsStackedWidget->addWidget(admin_form);
        creating_customer_account = new QWidget();
        creating_customer_account->setObjectName("creating_customer_account");
        add_new = new QPushButton(creating_customer_account);
        add_new->setObjectName("add_new");
        add_new->setGeometry(QRect(700, 470, 121, 51));
        go_back = new QPushButton(creating_customer_account);
        go_back->setObjectName("go_back");
        go_back->setGeometry(QRect(400, 470, 131, 51));
        new_customer_name = new QLineEdit(creating_customer_account);
        new_customer_name->setObjectName("new_customer_name");
        new_customer_name->setGeometry(QRect(520, 140, 201, 41));
        new_customer_phone = new QLineEdit(creating_customer_account);
        new_customer_phone->setObjectName("new_customer_phone");
        new_customer_phone->setGeometry(QRect(520, 200, 201, 41));
        nameLable = new QLabel(creating_customer_account);
        nameLable->setObjectName("nameLable");
        nameLable->setGeometry(QRect(730, 150, 71, 16));
        phoneLable = new QLabel(creating_customer_account);
        phoneLable->setObjectName("phoneLable");
        phoneLable->setGeometry(QRect(730, 210, 71, 16));
        classLable = new QLabel(creating_customer_account);
        classLable->setObjectName("classLable");
        classLable->setGeometry(QRect(730, 300, 81, 16));
        class_box = new QComboBox(creating_customer_account);
        class_box->setObjectName("class_box");
        class_box->setGeometry(QRect(520, 290, 201, 41));
        class_box->setEditable(false);
        formsStackedWidget->addWidget(creating_customer_account);
        page = new QWidget();
        page->setObjectName("page");
        nameSearch = new QLineEdit(page);
        nameSearch->setObjectName("nameSearch");
        nameSearch->setGeometry(QRect(10, 70, 231, 31));
        phoneSearch = new QLineEdit(page);
        phoneSearch->setObjectName("phoneSearch");
        phoneSearch->setGeometry(QRect(10, 180, 231, 31));
        ranksearch = new QComboBox(page);
        ranksearch->addItem(QString());
        ranksearch->addItem(QString());
        ranksearch->addItem(QString());
        ranksearch->addItem(QString());
        ranksearch->setObjectName("ranksearch");
        ranksearch->setGeometry(QRect(10, 290, 231, 22));
        Search_btn = new QPushButton(page);
        Search_btn->setObjectName("Search_btn");
        Search_btn->setGeometry(QRect(40, 410, 171, 31));
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(80, 30, 91, 31));
        label_8->setStyleSheet(QString::fromUtf8("font-weight:bold;\n"
"font-size:18px;"));
        label_9 = new QLabel(page);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(60, 140, 131, 31));
        label_9->setStyleSheet(QString::fromUtf8("font-weight:bold;\n"
"font-size:18px;"));
        label_10 = new QLabel(page);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(80, 250, 81, 31));
        label_10->setStyleSheet(QString::fromUtf8("font-weight:bold;\n"
"font-size:18px;"));
        results = new QScrollArea(page);
        results->setObjectName("results");
        results->setGeometry(QRect(270, 40, 981, 651));
        results->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));
        results->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 979, 649));
        tableView = new QTableView(scrollAreaWidgetContents);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 0, 981, 651));
        results->setWidget(scrollAreaWidgetContents);
        backFromCustomers = new QPushButton(page);
        backFromCustomers->setObjectName("backFromCustomers");
        backFromCustomers->setGeometry(QRect(40, 650, 171, 31));
        formsStackedWidget->addWidget(page);
        cashRegisterSystem2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(cashRegisterSystem2Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1261, 22));
        cashRegisterSystem2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(cashRegisterSystem2Class);
        mainToolBar->setObjectName("mainToolBar");
        cashRegisterSystem2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(cashRegisterSystem2Class);
        statusBar->setObjectName("statusBar");
        cashRegisterSystem2Class->setStatusBar(statusBar);

        retranslateUi(cashRegisterSystem2Class);

        formsStackedWidget->setCurrentIndex(1);
        ProductsStackedWidget->setCurrentIndex(1);
        item_type_item->setCurrentIndex(-1);
        class_box->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(cashRegisterSystem2Class);
    } // setupUi

    void retranslateUi(QMainWindow *cashRegisterSystem2Class)
    {
        cashRegisterSystem2Class->setWindowTitle(QCoreApplication::translate("cashRegisterSystem2Class", "cashRegisterSystem2", nullptr));
        passwod_label->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\330\261\331\202\331\205 \330\247\331\204\330\263\330\261\331\212", nullptr));
        login_btn->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\257\330\256\331\210\331\204", nullptr));
        password_field->setText(QString());
        username_label->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\263\331\205 \330\247\331\204\331\205\330\263\330\252\330\256\330\257\331\205", nullptr));
        snacks->setText(QCoreApplication::translate("cashRegisterSystem2Class", "snacks", nullptr));
        fruits->setText(QCoreApplication::translate("cashRegisterSystem2Class", "fruits", nullptr));
        vegetables->setText(QCoreApplication::translate("cashRegisterSystem2Class", "vegetables", nullptr));
        drinks->setText(QCoreApplication::translate("cashRegisterSystem2Class", "drinks", nullptr));
        AddNewCustomer->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\266\330\247\331\201\330\251 \330\271\331\205\331\212\331\204", nullptr));
        sell->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\250\331\212\330\271", nullptr));
        retrieve->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\263\330\252\330\261\330\254\330\247\330\271", nullptr));
        label->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\261\331\202\331\205 \330\247\331\204\331\205\331\210\330\250\330\247\331\212\331\204", nullptr));
        cancel_order->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\330\272\330\247\330\241 \330\247\331\204\330\247\331\210\330\261\330\257\330\261", nullptr));
        price_before_const->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\330\263\330\271\330\261 \331\202\330\250\331\204 \330\247\331\204\330\256\330\265\331\205:", nullptr));
        price_after_const->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\330\263\330\271\330\261 \330\250\330\271\330\257 \330\247\331\204\330\256\330\265\331\205:", nullptr));
        price_before->setText(QCoreApplication::translate("cashRegisterSystem2Class", "0", nullptr));
        price_after->setText(QCoreApplication::translate("cashRegisterSystem2Class", "0", nullptr));
        check_discount->setText(QCoreApplication::translate("cashRegisterSystem2Class", "check", nullptr));
        customers->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\331\202\330\247\330\246\331\205\330\251 \330\247\331\204\330\271\331\205\331\204\330\247\330\241", nullptr));
        label_2->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\266\330\247\331\201\330\251/\330\255\330\260\331\201 \330\272\330\261\330\266:", nullptr));
        label_3->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\266\330\247\331\201\330\251/\330\255\330\260\331\201 \331\203\331\205\331\212\330\251:", nullptr));
        label_4->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\263\331\205 \330\247\331\204\330\272\330\261\330\266", nullptr));
        add_item->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\266\330\247\331\201\330\251", nullptr));
        remove_item->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\255\330\260\331\201", nullptr));
        label_5->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\330\263\330\271\330\261", nullptr));
        label_6->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\331\203\331\205\331\212\330\251", nullptr));
        label_7->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\331\206\331\210\330\271", nullptr));
        remove_quantity->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\255\330\260\331\201", nullptr));
        add_quantity->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\266\330\247\331\201\330\251", nullptr));
        label_20->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\263\331\205 \330\247\331\204\330\272\330\261\330\266", nullptr));
        label_21->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\331\203\331\205\331\212\330\251", nullptr));
        label_22->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\330\252\330\255\331\203\331\205 \331\201\331\212 \330\247\331\204\330\250\330\266\330\247\330\271\330\251:", nullptr));
        label_23->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\271\331\205\331\204\331\212\330\247\330\252 \330\247\331\204\330\250\331\212\330\271:", nullptr));
        label_25->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\271\331\205\331\204\331\212\330\247\330\252 \330\247\330\263\330\252\330\261\330\254\330\247\330\271:", nullptr));
        label_24->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\254\331\205\330\247\331\204\331\212 \330\271\331\205\331\204\331\212\330\247\330\252 \330\247\331\204\330\250\331\212\330\271 \331\210 \330\247\331\204\330\247\330\263\330\252\330\261\330\254\330\247\330\271:", nullptr));
        label_26->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\254\331\205\330\247\331\204\331\212 \330\247\331\204\331\212\331\210\331\205", nullptr));
        add_new->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\266\330\247\331\201\330\251", nullptr));
        go_back->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\271\331\210\330\257\330\251", nullptr));
        nameLable->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\330\263\331\205 \330\247\331\204\330\271\331\205\331\212\331\204", nullptr));
        phoneLable->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\261\331\202\331\205 \330\247\331\204\331\205\331\210\330\250\330\247\331\212\331\204", nullptr));
        classLable->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\252\330\265\331\206\331\212\331\201 \330\247\331\204\330\271\331\205\331\212\331\204", nullptr));
        class_box->setCurrentText(QString());
        ranksearch->setItemText(0, QCoreApplication::translate("cashRegisterSystem2Class", "\330\247\331\204\331\203\331\204", nullptr));
        ranksearch->setItemText(1, QCoreApplication::translate("cashRegisterSystem2Class", "\330\271\331\205\331\212\331\204 \330\271\330\247\330\257\331\212", nullptr));
        ranksearch->setItemText(2, QCoreApplication::translate("cashRegisterSystem2Class", "\330\271\331\205\331\212\331\204 \331\205\331\207\331\205", nullptr));
        ranksearch->setItemText(3, QCoreApplication::translate("cashRegisterSystem2Class", "\330\267\330\247\331\204\330\250", nullptr));

        Search_btn->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\250\330\255\330\253", nullptr));
        label_8->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\250\330\255\330\253 \330\250\330\247\331\204\330\247\330\263\331\205", nullptr));
        label_9->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\250\330\255\330\253 \330\250\330\261\331\202\331\205 \330\247\331\204\331\207\330\247\330\252\331\201", nullptr));
        label_10->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\250\330\255\330\253 \330\250\330\247\331\204\331\201\330\246\330\251", nullptr));
        backFromCustomers->setText(QCoreApplication::translate("cashRegisterSystem2Class", "\330\271\331\210\330\257\330\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cashRegisterSystem2Class: public Ui_cashRegisterSystem2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHREGISTERSYSTEM_H
