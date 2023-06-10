#include "mainwindow.h"
#include "dialogex.h"
#include "finddialog.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include "compairsondialog.h"
#include "relevantdioalog.h"
#include <QMenu>
#include "aboutwidget.h"
#include <QTranslator>
#include <QCompleter>

QString MainWindow::loadCurrentFolderFromFile()
{
    QFile inputFile("./settings_file.txt");
    if (!inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        return QString("");
    }
    QTextStream inputStream(&inputFile);

    return inputStream.readLine();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), tModel(new TableModule), prModel(new ProxyModel)
{
    ui->setupUi(this);
    setWindowTitle("NBA Basketball App");
//    prModel->setSourceModel(tModel);
//        _aboutWidget = new aboutWidget(this);
//    ui->tableView->setModel(prModel);
//    ui->tableView->setSortingEnabled(true);
//    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    _translator = new QTranslator(this);
//    ui->tableView->hideColumn(0);
//    ui->tableView->hideColumn(4);
//    ui->tableView->hideColumn(5);
//    ui->tableView->hideColumn(6);
//    ui->tableView->hideColumn(8);
//    ui->tableView->hideColumn(9);
//    ui->tableView->hideColumn(10);
//    ui->tableView->hideColumn(12);
//    ui->tableView->hideColumn(13);
//    ui->tableView->hideColumn(14);
//    ui->tableView->hideColumn(15);
//    ui->filterAgeComboBox->addItems(tModel->getAgesList());
//    ui->filterTeamComboBox->addItems(tModel->getTeamList());
//    ui->filterGamesPlayedComboBox->addItems(tModel->getGamesPlayedList());
//    ui->filterPointsComboBox->addItems(tModel->getPointsList());
//    ui->filterReboundsComboBox->addItems(tModel->getReboundsList());
//    ui->filterAssistsComboBox->addItems(tModel->getAssistsList());
//    ui->filterSeasonComboBox->addItems(tModel->getSeasonsList());
    QObject::connect(ui->pushButtonRemoveRow, &QPushButton::clicked, this, &MainWindow::removeModelRow);

    QObject::connect(ui->tableView, &QAbstractItemView::clicked, this, &MainWindow::highlightDataItem);
    QObject::connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openDataFile);
    QObject::connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAboutDialog);
    QObject::connect(ui->actionEnglish, &QAction::triggered, this, &MainWindow::translateEnglish);
//    QObject::connect(ui->actionExit, &QAction::triggered, this, &MainWindow::exitTheApp);
    QObject::connect(ui->actionRussian, &QAction::triggered, this, &MainWindow::translateRussian);
//    QObject::connect(ui->searchPushButton, &QPushButton::clicked, this, &MainWindow::findPlayer);
    DialogEx dialog;
    compairsonDialog compDialog;
    _currentFolder = loadCurrentFolderFromFile();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tModel;
    delete prModel;
}

//QString MainWindow::extractDir(QString file)
//{
//    return file;
//}

void MainWindow::saveCurrentFolderToFile(const QString& _currentFolder)
{
    QFile outputFile("./settings_file.txt");
    if (!outputFile.open(QFile::WriteOnly | QFile::Text))
    {
        return;
    }
    QTextStream outputStream(&outputFile);
    outputStream << _currentFolder;
}

void MainWindow::openDataFile()
{
    if (_currentFolder.isEmpty())
    {
        _currentFolder = ".";
    }

    QString fileName = QFileDialog::getOpenFileName(this, "Open data file", _currentFolder, "*.csv");
//    QMessageBox::warning(this, "Error", fileName, QMessageBox::Ok);

    _currentFolder = fileName;
    saveCurrentFolderToFile(_currentFolder);


    if (!tModel->reloadDataFromFile(fileName))
    {
        QMessageBox::warning(this, "Error", "Cannot open file", QMessageBox::Ok);
    }

    prModel->setSourceModel(tModel);
    ui->tableView->setModel(prModel);
    _aboutWidget = new aboutWidget(this);
    QIcon winIcon(":/img/basketball-player.ico");
    this->setWindowIcon(winIcon);
//    searchPushButton = new QPushButton(tr("&Find"));
//    searchPushButton->setEnabled(false);
//    findDialog = new FindDialog(this);
//    _translator = new QTranslator(this);
//    ui->tableView->horizontalHeader()->setSectionResizeMode(Qt::Re)
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(8);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);
    ui->tableView->hideColumn(12);
    ui->tableView->hideColumn(13);
    ui->tableView->hideColumn(14);
    ui->tableView->hideColumn(15);
    ui->tableView->hideColumn(17);
    ui->filterAgeComboBox->addItems(tModel->getAgesList());
    ui->filterTeamComboBox->addItems(tModel->getTeamList());
    ui->filterGamesPlayedComboBox->addItems(tModel->getGamesPlayedList());
    ui->filterPointsComboBox->addItems(tModel->getPointsList());
    ui->filterReboundsComboBox->addItems(tModel->getReboundsList());
    ui->filterAssistsComboBox->addItems(tModel->getAssistsList());
    ui->filterSeasonComboBox->addItems(tModel->getSeasonsList());
}

void MainWindow::translateEnglish()
{
    qApp->removeTranslator(_translator);
    ui->retranslateUi(this);
}

void MainWindow::translateRussian()
{
    if (_translator->load("new_ru.ts"))
        qApp->installTranslator(_translator);
    ui->retranslateUi(this);
}


void MainWindow::on_pushButton_clicked()
{
    DialogEx dialog;
    if (dialog.exec())
    {
        tModel->appendRow(dialog.getData());
    }

}

void MainWindow::on_filterAgeComboBox_currentTextChanged(const QString &arg1)
{
    prModel->setAgeTargetField(arg1);
}

void MainWindow::on_filterTeamComboBox_currentTextChanged(const QString &arg1)
{
    prModel->setTeamTargetField(arg1);
}

void MainWindow::removeModelRow()
{
    QModelIndex removeIndex = ui->tableView->currentIndex();
    int rowToRemove = prModel->mapToSource(removeIndex).row();

    if (!tModel->removeRow(rowToRemove))
    {
        QMessageBox::warning(this, "Error", "Incorrect index (doesn't exist)", QMessageBox::Ok);
    }
}

void MainWindow::on_filterGamesPlayedComboBox_currentTextChanged(const QString &arg1)
{
    prModel->setGamesPlayedTargetField(arg1);
}


void MainWindow::on_filterPointsComboBox_currentTextChanged(const QString &arg1)
{
    prModel->setPointsTargetField(arg1);
}


void MainWindow::on_filterReboundsComboBox_currentTextChanged(const QString &arg1)
{
    prModel->setReboundsTargetField(arg1);
}


void MainWindow::on_filterAssistsComboBox_currentTextChanged(const QString &arg1)
{
    prModel->setAssistsTargetField(arg1);
}


void MainWindow::on_filterSeasonComboBox_currentTextChanged(const QString &arg1)
{
    prModel->setSeasonTargetField(arg1);
}


void MainWindow::highlightDataItem(const QModelIndex& clickIndex)
{
    int row = prModel->mapToSource(clickIndex).row();
    QModelIndex index = tModel->index(row, 1);
    ui->NameMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 4);
    ui->HeightMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 5);
    ui->WeightMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 6);
    ui->CollegeMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 8);
    ui->DraftYMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 9);
    ui->DraftRMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 10);
    ui->DraftNMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 12);
    ui->PtsMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 13);
    ui->RebMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 14);
    ui->AstMainLabel->setText(tModel->data(index).toString());
    index = tModel->index(row, 15);
    ui->NRMainLabel->setText(tModel->data(index).toString());
}

void MainWindow::on_relevantPushButton_clicked()
{
    relevantDioalog revDialog;
    ui->tableView->sortByColumn(17, Qt::DescendingOrder);
    QString bestTeam = tModel->findBestTeam();
    QString bestHight = tModel->findBestHight();
    QString bestWeight = tModel->findBestWeight();
    QString bestCountry = tModel->findBestCountry();
    revDialog.setData(bestTeam, bestHight, bestWeight, bestCountry);
    if (revDialog.exec())
    {}
}

void MainWindow::showAboutDialog()
{
    _aboutWidget->show();
}

void MainWindow::on_comparePushButton_clicked()
{

    QString erName2 = ui->NameMainLabel->text();
    QString erPts2 = ui->PtsMainLabel->text();
    QString erReb2 = ui->RebMainLabel->text();
    QString erAst2 = ui->AstMainLabel->text();
    compDialog.setData2(erName2, erPts2, erReb2, erAst2);

    if (compDialog.exec())
    {}
}


void MainWindow::on_pushButton_2_clicked()
{
    QString erName = ui->NameMainLabel->text();
    QString erPts = ui->PtsMainLabel->text();
    QString erReb = ui->RebMainLabel->text();
    QString erAst = ui->AstMainLabel->text();

    compDialog.setData1(erName, erPts, erReb, erAst);
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


