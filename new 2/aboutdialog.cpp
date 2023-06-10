#include "aboutdialog.h"
#include "QtWidgets/qboxlayout.h"
#include "ui_aboutdialog.h"

AboutWidget::AboutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutWidget)
{
    ui->setupUi(this);

    QHBoxLayout* layout = ui->horizontalLayout;
    layout->addWidget(new iconWidget, 2);
}

AboutWidget::~AboutWidget()
{
    delete ui;
}
