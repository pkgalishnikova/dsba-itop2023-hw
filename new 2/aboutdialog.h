#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "iconwidget.h"

#include <QWidget>
#include <QPainter>

namespace Ui {
class AboutWidget;
}

class AboutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AboutWidget(QWidget *parent = nullptr);
    ~AboutWidget();

private:
    Ui::AboutWidget *ui;
};

#endif // ABOUTDIALOG_H
