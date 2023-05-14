#include "cashRegisterSystem.h"

void cashRegisterSystem::on_add_item_clicked() {

	Database db("mydatabase.db");
	string Items_Names = m_ui->item_name_item->toPlainText().toUtf8().constData();
	string Items_Prices = m_ui->item_price_item->toPlainText().toUtf8().constData();
	int Quantity = m_ui->item_quantity_item->toPlainText().toInt();
	string type = m_ui->item_type_item->currentText().toUtf8().constData();
	db.insertProdRows(Items_Names, Items_Prices, Quantity, type);
	QMessageBox msg;
	msg.setText("\u0639\u0645\u0644\u064A\u0629 \u0646\u0627\u062C\u062D\u0629");
	msg.exec();
	m_ui->item_name_item->clear();
	m_ui->item_price_item->clear();
	m_ui->item_quantity_item->clear();
    m_ui->item_type_item->setCurrentIndex(0);

}
void cashRegisterSystem::on_add_quantity_clicked() {
    Database db("mydatabase.db");
    string item_name = m_ui->item_name_quantity->currentText().toUtf8().constData();
    int item_Quantity = m_ui->item_quantity_quantity->toPlainText().toInt();
    db.updateProductQuantity(item_name, item_Quantity,'+');
    QMessageBox msg;
    msg.setText("\u0639\u0645\u0644\u064A\u0629 \u0646\u0627\u062C\u062D\u0629");
    msg.exec();

    m_ui->item_quantity_quantity->clear();
    m_ui->item_name_quantity->setCurrentIndex(0);

}

void cashRegisterSystem::on_remove_item_clicked() {
    Database db("mydatabase.db");
    string Items_Names = m_ui->item_name_item->toPlainText().toUtf8().constData();
    db.DeleteProdRow(Items_Names);
    QMessageBox msg;
    msg.setText("\u062a\u0645 \u0627\u0644\u062d\u0630\u0641 \u0628\u0646\u062c\u0627\u062d");
    msg.exec();
    m_ui->item_name_item->clear();
}

void cashRegisterSystem::on_remove_quantity_clicked() {
    Database db("mydatabase.db");
    string item_name = m_ui->item_name_quantity->currentText().toUtf8().constData();
    int item_Quantity = m_ui->item_quantity_quantity->toPlainText().toInt();
    db.updateProductQuantity(item_name, item_Quantity, '-');
    QMessageBox msg;
    msg.setText("\u0639\u0645\u0644\u064A\u0629 \u0646\u0627\u062C\u062D\u0629");
    msg.exec();

    m_ui->item_quantity_quantity->clear();
    m_ui->item_name_quantity->setCurrentIndex(0);
}

void cashRegisterSystem::Show_Sell_window() {
    Show_window("sell", m_ui->sell_operations_contents);
}

void cashRegisterSystem::Show_retrieve_window() {
    Show_window("retrieve", m_ui->return_operations_contents);
}
void cashRegisterSystem::Show_total_window() {
    float TotalPrice;
    QVBoxLayout* VLayout = new QVBoxLayout(m_ui->total_operations_contents);
    QHashIterator<QString, QList<QVariant>> i(sellOperation);
    int quantity=0;
    float prices=0;
    int index = 0;
    while (i.hasNext()) {
        QFrame* f = new QFrame();
        QHBoxLayout* hLayout = new QHBoxLayout(f);
        i.next();
        if (retrieveOperation.contains(i.key())) {
            QList<QVariant> updatedValue = i.value();
            quantity = updatedValue.at(0).toInt() - retrieveOperation.value(i.key()).at(0).toInt();
            prices = updatedValue.at(1).toFloat() - retrieveOperation.value(i.key()).at(1).toFloat();
        }
        else {
            quantity = i.value().at(0).toInt();
            prices = i.value().at(1).toFloat();
        }
        if (index % 2 == 1) f->setStyleSheet("QFrame{background-color:rgba(184, 184, 184, 255)}");

        QLabel* name =new QLabel("\u0627\u0644\u0627\u0633\u0645 : "+i.key());
        QLabel* PriceLabel = new QLabel("\u0627\u0644\u0633\u0639\u0631 : " + QString::number(prices));
        QLabel* Quantitylabel = new QLabel("\u0627\u0644\u0643\u0645\u064a\u0629 :"+QString::number(quantity));
        name->setStyleSheet("border:none;");
        Quantitylabel->setStyleSheet("border:none;");
        PriceLabel->setStyleSheet("border:none;");
        hLayout->addWidget(Quantitylabel);
        hLayout->addWidget(PriceLabel);
        hLayout->addWidget(name);
        VLayout->addWidget(f);
        TotalPrice += prices;
        index++;
    }
    index = 0;
    QHashIterator<QString, QList<QVariant>> j(retrieveOperation);
    while (j.hasNext())
    {
        QFrame* f = new QFrame();
        QHBoxLayout* hLayout = new QHBoxLayout(f);
        j.next();
        
        if (!sellOperation.contains(j.key()))
        {
            quantity = j.value().at(0).toInt();
            prices = j.value().at(1).toFloat();
            QLabel* name = new QLabel("\u0627\u0644\u0627\u0633\u0645 : " + i.key());
            QLabel* PriceLabel = new QLabel("\u0627\u0644\u0633\u0639\u0631 :" + QString::number(prices));
            QLabel* Quantitylabel = new QLabel("\u0627\u0644\u0643\u0645\u064a\u0629 :" + QString::number(quantity));
            name->setStyleSheet("border:none;");
            Quantitylabel->setStyleSheet("border:none;");
            PriceLabel->setStyleSheet("border:none;");
            if (index % 2 == 1) f->setStyleSheet("QFrame{background-color:rgba(184, 184, 184, 255)}");
            hLayout->addWidget(Quantitylabel);
            hLayout->addWidget(PriceLabel);
            hLayout->addWidget(name);
            VLayout->addWidget(f);
            TotalPrice += prices;
            index++;
        }
        else
        {
            continue;
        }
    }
    m_ui->day_total_income->setStyleSheet("font-size:16px; font-weight:bold");
    m_ui->day_total_income->setText(QString::number(TotalPrice));
    m_ui->total_operations_contents->setLayout(VLayout);  
}
void cashRegisterSystem::Show_window(string type, QWidget* scrollContents) {
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydatabase.db", &m_OperationsDB);
    std::stringstream ss;
    ss << "select * from Operations where type = '"<<type<<"'";
    QString query = QString::fromStdString(ss.str());
    QVBoxLayout* VLayout = new QVBoxLayout(scrollContents);
    rc = sqlite3_prepare_v2(m_OperationsDB, query.toUtf8(), -1, &stmt, NULL);
    int i = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {

        QFrame* f = new QFrame();
        QHBoxLayout* hLayout = new QHBoxLayout(f);
        int id = sqlite3_column_int(stmt, 0);
        string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        int Quantity_Sell = sqlite3_column_int(stmt, 2);
        string price = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        float p = stof(price);
        QLabel* ids = new QLabel(QString("%1").arg(id));
        QLabel* names = new QLabel(QString("\u0627\u0644\u0627\u0633\u0645 : %1").arg(QString::fromUtf8(name)));
        QLabel* Quantities = new QLabel(QString("\u0627\u0644\u0643\u0645\u064a\u0629 : %1 ").arg(to_string(Quantity_Sell).c_str()));
        QLabel* pricesLabel = new QLabel(QString("\u0627\u0644\u0633\u0639\u0631 : %1").arg(QString::number(p*Quantity_Sell)));
        ids->setStyleSheet("border:none;");
        names->setStyleSheet("border:none;");
        Quantities->setStyleSheet("border:none;");
        pricesLabel->setStyleSheet("border:none;");
        if (i % 2 == 1) f->setStyleSheet("QFrame{background-color:rgba(184, 184, 184, 255)}");
        hLayout->addWidget(ids);
        hLayout->addWidget(Quantities);
        hLayout->addWidget(pricesLabel);
        hLayout->addWidget(names);
        VLayout->addWidget(f);
        i++;
        if (type == "sell") {
            InsertInHashOperations(sellOperation, QString::fromUtf8(name), (p*Quantity_Sell), Quantity_Sell);
        }
        else {
            InsertInHashOperations(retrieveOperation, QString::fromUtf8(name), p * Quantity_Sell, Quantity_Sell);
        }
    }
    scrollContents->setLayout(VLayout);
    sqlite3_finalize(stmt);
    sqlite3_close(m_OperationsDB);
}
void cashRegisterSystem::InsertInHashOperations(QHash< QString, QList<QVariant>> &Operation,QString name,float price,int Quantity_Sell) {
    QList<QVariant> values;

    if (Operation.contains(name)) {
        values = Operation[name];
        values[0] = values[0].toInt() + Quantity_Sell;
        values[1] = values[1].toFloat() + price;
        Operation[name] = values;
    }
    else {
        values << Quantity_Sell << price;
        Operation.insert(name, values);
    }
}

void cashRegisterSystem::Add_Item_names() {
    sqlite3* db;
    int rc = sqlite3_open("mydatabase.db", &db);
    if (rc == SQLITE_OK) {
        sqlite3_stmt* stmt;
        const char* query = "SELECT name FROM Products";
        rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

        if (rc == SQLITE_OK) {
            m_ui->item_name_quantity->clear();

            while (sqlite3_step(stmt) == SQLITE_ROW) {
                const char* value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

                m_ui->item_name_quantity->addItem(QString::fromUtf8(value));
            }
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }
}