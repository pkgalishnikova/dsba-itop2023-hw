#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

class QLineEdit;
class QPushButton;

namespace Ui
{
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();
    QString getFindText();
public slots:
    void findClicked();
private:
    Ui::FindDialog *ui;
    QLineEdit *lineEdit;
    QPushButton *findButton;
    QString findText;
};

#endif // FINDDIALOG_H
