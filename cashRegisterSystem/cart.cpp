#include "cashRegisterSystem.h"

void cashRegisterSystem::on_name_button_clicked(int quantity, QString name, float pricePerEach) {
    float totalPrice = pricePerEach * quantity;
    QFrame* frame = new QFrame;
    QHBoxLayout* layout = new QHBoxLayout(frame);
    frame->setMaximumHeight(50);
    QLabel* names = new QLabel(name);
    names->setStyleSheet("border: none; font-size:16px; font-weight:bold;");

    QLabel* quantities = new QLabel(tr("x%1").arg(quantity));
    quantities->setStyleSheet("border: none; font-size:16px;");

    QLabel* pricesPerEach = new QLabel(tr("%1").arg(pricePerEach));
    pricesPerEach->setStyleSheet("border: none; font-size:16px;");

    QLabel* totPrice = new QLabel(tr("%1").arg(totalPrice));
    totPrice->setStyleSheet("border: none; font-size:16px;");

    Delete_button.push_back(new QPushButton("\u062D\u0630\u0641"));
    layout->addWidget(names);
    layout->addWidget(quantities);
    layout->addWidget(pricesPerEach);
    layout->addWidget(totPrice);
    layout->addWidget(Delete_button.back());
    layout->setAlignment(Qt::AlignTop);
    Delete_button.back()->setObjectName("btnName_1");
    m_ui->cartVerticalLayout->addWidget(frame);
    TotalBalanceForOperation += totalPrice;
    m_ui->price_before->setText(QString::number(TotalBalanceForOperation));
    m_ui->price_after->setText(QString::number(TotalBalanceForOperation));

    QWidget* scrollWidget = m_ui->scrollArea_9->widget();
    QVBoxLayout* scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());

    if (!scrollLayout) {
        // Create a new layout if one doesn't exist
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    scrollLayout->insertItem(0, spacer);
    scrollLayout->insertWidget(1, frame);

    connect(Delete_button.back(), &QPushButton::clicked, [this, d = Delete_button.back(), totPrice, names]() {
        Delete_On_Click(d, totPrice->text().toFloat(), names->text());
        });

    if (i % 2 == 1)
        frame->setStyleSheet("QFrame{background-color:rgba(184, 184, 184, 255)}");

    MappingLayout.insert(Delete_button.back(), frame);

    if (myHash.contains(name))
        myHash[name] += quantity;
    else
        myHash.insert(name, quantity);

    i++;

    // Add a spacer at the end of the layout to prevent the last item from sticking to the top
    QSpacerItem* bottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollLayout->addItem(bottomSpacer);

}

void cashRegisterSystem::Delete_On_Click(QPushButton* del, float totalPrice, QString name) {
    myHash.remove(name);
    QFrame* layout = MappingLayout.take(del);
    withDiscount = on_check_discount_clicked();

    TotalBalanceForOperation -= totalPrice;
    TotalBalanceForOperationDiscounted = 0.9 * TotalBalanceForOperation;

    if (withDiscount == true) m_ui->price_after->setText(QString::number(TotalBalanceForOperationDiscounted));
    else m_ui->price_after->setText(QString::number(TotalBalanceForOperation));
    m_ui->price_before->setText(QString::number(TotalBalanceForOperation));

    while (layout->layout()->count() != 0) {
        QLayoutItem* item = layout->layout()->takeAt(0);
        delete item->widget();
        delete item;
    }
    delete layout;
}

bool cashRegisterSystem::on_check_discount_clicked() {
    sqlite3_stmt* stmt;
    float price = (m_ui->price_after->text()).toFloat();
    int rc = sqlite3_open("mydatabase.db", &m_customersDB);
    if (rc != SQLITE_OK) {
        QMessageBox::warning(this, "oh no", "Cannot open database");
        sqlite3_close(m_customersDB);
    }
    std::stringstream ss;
    ss << "select class from Customers where phone_number ='" << m_ui->phone_number->text().toStdString() << "'";
    QMessageBox mess;
    QString query = QString::fromStdString(ss.str());
    rc = sqlite3_prepare_v2(m_customersDB, query.toUtf8().constData(), -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        QMessageBox::warning(this, "oh no", query);
        sqlite3_finalize(stmt);
        sqlite3_close(m_customersDB);
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* Class = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        size_t len = strlen(Class);
       
        if (strcmp(Class, "\u0637\u0627\u0644\u0628") == 0 || strcmp(Class, "\u0639\u0645\u064A\u0644 \u0645\u0647\u0645") == 0)
        {
            price = price * 0.9;
            m_ui->price_after->setText(QString::number(price));
            m_ui->check_discount->setDisabled(true);
            sqlite3_finalize(stmt);
            sqlite3_close(m_customersDB);
            return true;
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(m_customersDB);
    return false;
}

void cashRegisterSystem::on_cancel_order_clicked()
{
    DeleteAll();
}

void cashRegisterSystem::on_sell_clicked()
{
    payOperation('+');
}

void cashRegisterSystem::on_retrieve_clicked()
{
    payOperation('-');
}



void cashRegisterSystem::payOperation(char type) {
    
    Database db("mydatabase.db");
    db.updateCustomerTotalPaid(m_ui->phone_number->text().toStdString(), m_ui->price_after->text().toFloat(), type);
    QHashIterator<QString, int> i(myHash);
    while (i.hasNext()) {
        i.next();
        db.updateProductQuantity(i.key().toStdString(), i.value(), updateType(type));
    }
    DeleteAll();
    db.~Database();
}

void cashRegisterSystem::DeleteAll() {
    QLayout* layout = m_ui->cartContents->layout(); // Get the layout of the scroll area widget
    QLayoutItem* child;
    while ((child = layout->takeAt(0)) != nullptr) {
        QWidget* widget = child->widget();
        if (widget) {
            layout->removeWidget(widget);
            delete widget;
        }
        delete child;
    }
    layout->addItem(new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));  // Add a spacer item to the layout
    myHash.clear();
    TotalBalanceForOperation = 0;
    m_ui->price_after->setText(QString::number(TotalBalanceForOperation));
    m_ui->price_before->setText(QString::number(TotalBalanceForOperation));
    m_ui->check_discount->setDisabled(false);
    withDiscount = false;
}

char cashRegisterSystem::updateType(char type) {
    return  (type == '-') ? '+' : '-';
}
