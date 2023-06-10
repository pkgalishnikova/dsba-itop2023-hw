#include "aboutwidget.h"
#include "iconwidget.h"
#include "ui_aboutwidget.h"

aboutWidget::aboutWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutWidget)
{
    ui->setupUi(this);

    setWindowTitle("About a project");

    QGridLayout* layout = ui->gridLayout;
    iconWidget* iconW = new iconWidget;
    iconW->setAttribute(Qt::WA_DeleteOnClose);
    layout->addWidget(new iconWidget, 0, 1);

    for (int i = 0; i < layout->columnCount(); ++i)
        layout->setColumnStretch(i, 1);
}

aboutWidget::~aboutWidget()
{
    delete ui;
}
