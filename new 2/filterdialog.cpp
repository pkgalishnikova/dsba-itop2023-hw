#include "filterdialog.h"
#include "ui_filterdialog.h"

filterDialog::filterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filterDialog)
{
    ui->setupUi(this);
}

filterDialog::~filterDialog()
{
    delete ui;
}

void filterDialog::on_filterComboBox_currentTextChanged(const QString &arg1)
{
    prModel->setTargetField(arg1);
}
