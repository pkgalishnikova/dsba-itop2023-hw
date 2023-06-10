#ifndef RELEVANTDIOALOG_H
#define RELEVANTDIOALOG_H

#include <QDialog>

namespace Ui {
class relevantDioalog;
}

class relevantDioalog : public QDialog
{
    Q_OBJECT

public:
    explicit relevantDioalog(QWidget *parent = nullptr);
    ~relevantDioalog();
    void setData(const QString &bestTeam, const QString &bestHeight, const QString &bestWeight, const QString &bestCountry);

private slots:
//    void on_pushButton_clicked();

private:
    Ui::relevantDioalog *ui;
};

#endif // RELEVANTDIOALOG_H
