#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QDialog>

namespace Ui {
class aboutWidget;
}

class aboutWidget : public QDialog
{
    Q_OBJECT

public:
    explicit aboutWidget(QWidget *parent = nullptr);
    ~aboutWidget();

private:
    Ui::aboutWidget *ui;
};

#endif // ABOUTWIDGET_H
