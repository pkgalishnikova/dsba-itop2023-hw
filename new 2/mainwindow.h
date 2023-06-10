#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QtCore/qcoreapplication.h"
#include "QtWidgets/qlineedit.h"
#include "tablemodule.h"
#include "proxymodel.h"
#include <QMainWindow>
#include "aboutwidget.h"
#include <QMenu>
#include "compairsondialog.h"
#include "finddialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openDataFile();
    void on_pushButton_clicked();
    void removeModelRow();
    void on_filterAgeComboBox_currentTextChanged(const QString &arg1);
    void on_filterTeamComboBox_currentTextChanged(const QString &arg1);
    void on_filterGamesPlayedComboBox_currentTextChanged(const QString &arg1);
    void on_filterPointsComboBox_currentTextChanged(const QString &arg1);
    void on_filterReboundsComboBox_currentTextChanged(const QString &arg1);
    void on_filterAssistsComboBox_currentTextChanged(const QString &arg1);
    void on_filterSeasonComboBox_currentTextChanged(const QString &arg1);
    void highlightDataItem(const QModelIndex& index);
//    void on_searchPushButton_clicked();
    void on_relevantPushButton_clicked();
//    void on_comparePushButton_clicked();
    void translateEnglish();
    void translateRussian();
    void showAboutDialog();
//    void findPlayer();
//    void exitTheApp();
    void on_comparePushButton_clicked();
    void on_pushButton_2_clicked();
    QString loadCurrentFolderFromFile();
    void saveCurrentFolderToFile(const QString& _currentFolder);
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    TableModule *tModel;
    ProxyModel *prModel;
    QString _currentFolder;
    aboutWidget* _aboutWidget;
    QMenu *helpMenu;
    QAction *helpAction;
    QTranslator* _translator;
    compairsonDialog compDialog;
//    FindDialog *findDialog;
//    QPushButton *searchPushButton;
//    QLineEdit *nameLine, *gamesLine;
};
#endif // MAINWINDOW_H
