#include "test_ui_CRS.h"

test_ui_CRS::test_ui_CRS(QWidget *parent)
    : QMainWindow(parent), m_ui(new Ui::test_ui_CRSClass)
{
    m_ui->setupUi(this);
    m_ui->categories_list->setLayoutDirection(Qt::RightToLeft);
    showCategoriesList();
    showAllProducts();
}

test_ui_CRS::~test_ui_CRS()
{
    delete m_ui;
}

void test_ui_CRS::showCategoriesList() {
    QFile file("categories.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        m_ui->categories_list->addItem(line);

        categories.append(makeLabel(line));
    }
    connect(m_ui->categories_list, &QListWidget::currentRowChanged, [=](int row) {
        itemClickedHandler(row);
        });
}

void test_ui_CRS::itemClickedHandler(int row) {
    int yMargin = m_ui->products_scroll_area->height() - categories[row]->height();
    m_ui->products_scroll_area->ensureWidgetVisible(categories[row], 0, yMargin);
}

QLabel* test_ui_CRS::makeLabel(QString content) {
    QLabel* label = new QLabel(content,this);
    label->setStyleSheet("font-size:20px;");
    return label;
}

void test_ui_CRS::populateProductList(QVBoxLayout* productsVerticalLayout, QLabel* productType,
    QVBoxLayout* cartVerticalLayout, QLabel* priceBefore, QLabel* priceAfter,
    QScrollArea* cartScrollArea, QPushButton* checkButton,
    QLineEdit* phoneNumberField)
{
    //adding products label
    productsVerticalLayout->addWidget(productType);

    //preparing for adding products grid layout
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydatabase.db", &m_ProductsDB);
    if (rc != SQLITE_OK) {
        QMessageBox::warning(this, "oh no", "Cannot open database");
        sqlite3_close(m_ProductsDB);
    }
    std::stringstream ss;
    ss << "select * from products where type ='" << productType->text().toStdString() << "'";
    QString query = QString::fromStdString(ss.str());
    rc = sqlite3_prepare_v2(m_ProductsDB, query.toUtf8().constData(), -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        QMessageBox::warning(this, "oh no", query);
        sqlite3_finalize(stmt);
        sqlite3_close(m_ProductsDB);
    }
    //Creating a grid layout...

    int verticalItems = 0;
    int horizontalItems = 5;
    QLabel* nameLabel;
    QVector<QPushButton*> add_button;
    QDoubleSpinBox* quantityBox;
    int i = 0;
    QGridLayout* grid = new QGridLayout(this);
    grid->setAlignment( Qt::AlignRight);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        double quantity = sqlite3_column_double(stmt, 1);
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        const char* price = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        QFrame* frame = new QFrame;
        QVBoxLayout* vboxLayout = new QVBoxLayout(frame);
        nameLabel = new QLabel(QString::fromUtf8(name));
        nameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        nameLabel->setStyleSheet("border: none; font-size:16px; font-weight:bold;");

        //Assigning the strings to widgets...
        add_button.push_back(new QPushButton("Add To Cart!"));

        quantityBox = new QDoubleSpinBox();
        QLabel* lab = new QLabel(QString("Price: %1").arg(QString::fromUtf8(price)));
        lab->setStyleSheet("border: none; font-size:16px;");

        float price_val = lab->text().split(" ")[1].toFloat();
        //Setting up the lable style sheet
        //Creating horizontal line with desired properties...
        //Setting up the pushbutton with the on-hover changes...
        add_button.back()->setObjectName("btnName_1");
        quantityBox->setValue(1.00f);
        lab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        //Setting up quantityBox proberties
        quantityBox->setObjectName("quantityBox_1");

        connect(add_button.back(), &QPushButton::clicked, [this, quantityBox, nameLabel, price_val, cartVerticalLayout, priceBefore,
            priceAfter, cartScrollArea, checkButton, phoneNumberField]() {
                on_name_button_clicked(quantityBox->value(), nameLabel->text(), price_val, cartVerticalLayout, priceBefore,
                    priceAfter, cartScrollArea, checkButton, phoneNumberField);
            });
        quantityBox->setMinimum(1);
        quantityBox->setMaximum(9999999);

        vboxLayout->addWidget(nameLabel);
        vboxLayout->addWidget(lab);
        vboxLayout->addWidget(quantityBox);
        vboxLayout->addWidget(add_button.back());
        frame->setStyleSheet("border: 1px solid black;");
        if (i % 2 == 1) frame->setStyleSheet("QFrame{background-color:rgba(184, 184, 184, 255); border: 1px solid black;}");
        frame->setMaximumSize(149, 156);
        //adding all the widgets to the previously cretaed grid layout...
        grid->addWidget(frame, verticalItems, horizontalItems);
        horizontalItems--;
        if (horizontalItems == 0)
        {
            verticalItems++;
            horizontalItems = 5;
        }
        i++;
    }
    productsVerticalLayout->addLayout(grid);

    sqlite3_finalize(stmt);
    sqlite3_close(m_ProductsDB);
}

void test_ui_CRS::showAllProducts() {
    for (auto category : categories)
        populateProductList(m_ui->productsVerticalLayout, category, m_ui->cartVerticalLayout, m_ui->price_before, m_ui->price_after, m_ui->cartScrollArea, m_ui->checkDiscount, m_ui->phone_number);
}

void test_ui_CRS::on_name_button_clicked(double quantity, QString name, float pricePerEach,
    QVBoxLayout* cartVerticalLayout, QLabel* priceBefore, QLabel* priceAfter,
    QScrollArea* cartScrollArea, QPushButton* checkButton, QLineEdit* phoneNumberField)
{
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
    cartVerticalLayout->addWidget(frame);
    TotalBalanceForOperation += totalPrice;

    priceBefore->setText(QString::number(TotalBalanceForOperation));
    priceAfter->setText(QString::number(TotalBalanceForOperation));

    QWidget* scrollWidget = cartScrollArea->widget();
    QVBoxLayout* scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());

    if (!scrollLayout) {
        // Create a new layout if one doesn't exist
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    scrollLayout->insertItem(0, spacer);
    scrollLayout->insertWidget(1, frame);

    connect(Delete_button.back(), &QPushButton::clicked, [this, btn = Delete_button.back(), totalPrice, names, quantity, priceBefore, priceAfter,
        checkButton, phoneNumberField]() {
        Delete_On_Click(btn, totalPrice, names->text(), quantity, priceBefore, priceAfter,
            checkButton, phoneNumberField);
    });

    if (i % 2 == 1) frame->setStyleSheet("QFrame{background-color:rgba(185, 185, 190, 255)}");
    if (i % 2 == 0) frame->setStyleSheet("QFrame{background-color:rgba(220, 220, 225, 255)}");

    i++;

    // Add a spacer at the end of the layout to prevent the last item from sticking to the top
    QSpacerItem* bottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollLayout->addItem(bottomSpacer);

}

void test_ui_CRS::Delete_On_Click(QPushButton* del, float totalPrice, QString name, int quantity,
    QLabel* priceBefore, QLabel* priceAfter,
    QPushButton* checkButton, QLineEdit* phoneNumberField)
{
}