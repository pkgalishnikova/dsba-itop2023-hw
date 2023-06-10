#include "relevantdioalog.h"
#include "ui_relevantdioalog.h"
#include "tablemodule.h"

relevantDioalog::relevantDioalog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::relevantDioalog)
{
    ui->setupUi(this);
    setWindowTitle("Frequently asked questions");

}

relevantDioalog::~relevantDioalog()
{
    delete ui;
}


void relevantDioalog::setData(const QString &bestTeam, const QString &bestHeight, const QString &bestWeight, const QString &bestCountry)
{
    ui->teamLabel->setText(bestTeam);
    ui->heightLabel->setText(bestHeight);
    ui->weightLabel->setText(bestWeight);
    ui->countryLabel->setText(bestCountry);
}

