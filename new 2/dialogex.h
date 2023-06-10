#ifndef DIALOGEX_H
#define DIALOGEX_H

#include <QDialog>

namespace Ui {
class DialogEx;
}

class DialogEx : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEx(QWidget *parent = nullptr);
    ~DialogEx();
    QList<QString> getData();

private:
    Ui::DialogEx *ui;
};

#endif // DIALOGEX_H
