#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>

namespace Ui {
class filterDialog;
}

class filterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit filterDialog(QWidget *parent = nullptr);
    ~filterDialog();
private slots:
    void on_filterComboBox_currentTextChanged(const QString &arg1);
private:
    Ui::filterDialog *ui;
};

#endif // FILTERDIALOG_H
