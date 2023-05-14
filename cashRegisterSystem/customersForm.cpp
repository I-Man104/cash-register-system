#include "cashRegisterSystem.h"
void cashRegisterSystem::on_customers_clicked() {

    search();
    m_ui->formsStackedWidget->setCurrentIndex(4);
}




void cashRegisterSystem::on_backFromCustomers_clicked() {
    m_ui->formsStackedWidget->setCurrentIndex(1);
}


void cashRegisterSystem::on_Search_btn_clicked()
{
    m_ui->tableView->model()->removeRows(0, m_ui->tableView->model()->rowCount());
    search();
}

void cashRegisterSystem::search()
{

   
    phonesearch = m_ui->phoneSearch->text().toStdString();
    namesearch = m_ui->nameSearch->text().toStdString();
    rank = m_ui->ranksearch->currentIndex();
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydatabase.db", &m_ProductsDB);
    if (rc != SQLITE_OK) {
        QMessageBox::warning(this, "oh no", "Cannot open database");
        sqlite3_close(m_ProductsDB);
    }
    string ss = "SELECT * FROM customers WHERE 1=1";
    if (!namesearch.empty()) {
        ss += " AND name LIKE '%" + namesearch + "%'";
    }
    if (!phonesearch.empty()) {
        ss += " AND phone_number LIKE '%" + phonesearch + "%'";
    }
    if (rank != NULL) {
        if (rank == 2) {
            ss += " AND class = '\u0639\u0645\u064A\u0644 \u0645\u0647\u0645'";
        }
        else if (rank == 3) {
            ss += " AND class = '\u0637\u0627\u0644\u0628'";
        }else if (rank == 1) {
            ss += " AND class = '\u0639\u0645\u064A\u0644 \u0639\u0627\u062F\u064A'";
        }
    }
    QString query = QString::fromStdString(ss);
    rc = sqlite3_prepare_v2(m_ProductsDB, query.toUtf8().constData(), -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        QMessageBox::warning(this, "oh no", query);
        sqlite3_finalize(stmt);
        sqlite3_close(m_ProductsDB);
    }

    QStandardItemModel* model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({ "الفئة", "اجمالي المدفوع", "رقم الهاتف", "الاسم" });
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        const char* phone_number = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int total_paid = sqlite3_column_int(stmt, 3);
        const char* customerClass = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

        QList<QStandardItem*> items;
        items.append(new QStandardItem(QString(customerClass)));
        items.append(new QStandardItem(QString::number(total_paid)));
        items.append(new QStandardItem(QString(phone_number)));
        items.append(new QStandardItem(QString(name)));

        for (int i = 0; i < items.count(); ++i) {
            // Set the Qt::ItemIsEditable flag to false for each item
            items.at(i)->setFlags(items.at(i)->flags() & ~Qt::ItemIsEditable);
            items.at(i)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        }

        model->appendRow(items);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(m_ProductsDB);

    m_ui->tableView->setModel(model);
    m_ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignRight);
    m_ui->tableView->horizontalHeader()->setStretchLastSection(true);
    m_ui->tableView->verticalHeader()->setStretchLastSection(true);
    int row_count = model->rowCount();
    for (int i = 0; i < row_count; ++i) {
        m_ui->tableView->setRowHeight(i, 35);
    }
  /*  m_ui->tableView->setMinimumHeight(35 * row_count + m_ui->tableView->horizontalHeader()->height() + 2);
    m_ui->tableView->setMaximumHeight(200);*/
    int size = 35 * row_count + m_ui->tableView->horizontalHeader()->height() + 2;
    if (size > 651) {
        m_ui->tableView->setGeometry(0, 0, 981, 651);
    }
    else {
        m_ui->tableView->setGeometry(0, 0, 981, size);
    }
    
    m_ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

}

