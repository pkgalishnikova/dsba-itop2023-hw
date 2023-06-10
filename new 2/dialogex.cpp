#include "dialogex.h"
#include "ui_dialogex.h"

DialogEx::DialogEx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEx)
{
    ui->setupUi(this);
    setWindowTitle("Add a new player");
}

DialogEx::~DialogEx()
{
    delete ui;
}

QList<QString> DialogEx::getData()
{
    QList<QString> allLines(19,"0");
    allLines[0] = ui->IdEdit->text();
    allLines[1] = ui->playerLine->text();
    allLines[2] = ui->teamLine->text();
    allLines[3] = ui->ageLine->text();
    allLines[4] = ui->heightLine->text();
    allLines[5] = ui->weightLine->text();
    allLines[6] = ui->collegeLine->text();
    allLines[7] = ui->countryLine->text();
    allLines[8] = ui->draftYearLine->text();
    allLines[9] = ui->draftRoundLine->text();
    allLines[10] = ui->draftNumberLine->text();
    allLines[11] = ui->gpLine->text();
    allLines[12] = ui->ptsLine->text();
    allLines[13] = ui->rebLine->text();
    allLines[14] = ui->astLine->text();
    allLines[15] = ui->netRatingLine->text();
    allLines[16] = ui->seasonLine->text();
    return allLines;
}
