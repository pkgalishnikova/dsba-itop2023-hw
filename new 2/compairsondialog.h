#ifndef COMPAIRSONDIALOG_H
#define COMPAIRSONDIALOG_H

#include <QDialog>

namespace Ui {
class compairsonDialog;
}

class compairsonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit compairsonDialog(QWidget *parent = nullptr);
    ~compairsonDialog();
//    void highlightDataItem(const QModelIndex& clickIndex);
    void setData1(const QString &labelText1, const QString &labelText2, const QString &labelText3, const QString &labelText4);
    void setData2(const QString &labelText1, const QString &labelText2, const QString &labelText3, const QString &labelText4);

private:
    Ui::compairsonDialog *ui;
};

#endif // COMPAIRSONDIALOG_H
