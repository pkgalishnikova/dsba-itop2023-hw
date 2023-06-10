#ifndef ICONWIDGET_H
#define ICONWIDGET_H
#include <QWidget>

class iconWidget : public QWidget
{
    Q_OBJECT
public:
    explicit iconWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event) override;
    void drawCircle(QPainter &painter, int x, int y);
signals:

};

#endif // ICONWIDGET_H
