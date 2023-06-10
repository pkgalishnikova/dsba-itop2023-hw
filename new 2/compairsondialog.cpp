#include "compairsondialog.h"
#include "ui_compairsondialog.h"

compairsonDialog::compairsonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compairsonDialog)
{
    ui->setupUi(this);
    setWindowTitle("Compare two players");
}

compairsonDialog::~compairsonDialog()
{
    delete ui;
}

void compairsonDialog::setData1(const QString &labelText1, const QString &labelText2, const QString &labelText3, const QString &labelText4)
{
    ui->nameComp1->setText(labelText1);
    ui->ptsComp1->setText(labelText2);
    ui->rebComp1->setText(labelText3);
    ui->astComp1->setText(labelText4);
}

void compairsonDialog::setData2(const QString &labelText1, const QString &labelText2, const QString &labelText3, const QString &labelText4)
{
    ui->nameComp2->setText(labelText1);
    ui->ptsComp2->setText(labelText2);
    ui->rebComp2->setText(labelText3);
    ui->astComp2->setText(labelText4);
}

