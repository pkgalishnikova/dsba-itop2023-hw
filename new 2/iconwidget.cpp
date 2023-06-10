#include "iconwidget.h"
#include <QPainter>

iconWidget::iconWidget(QWidget *parent) : QWidget{parent}
{

}

void iconWidget::paintEvent(QPaintEvent*)
{
QPainter painter(this);

painter.setPen(Qt::black);
painter.setBrush(QColor(255, 215, 0));

painter.drawEllipse(QRectF(50, 50, 200, 200));
painter.drawEllipse(QRectF(70, 70, 120, 120));
painter.drawArc(QRectF(50, 50, 100, 100), 60*16, 240*16);

QImage jordanImage(":/img/basketball-player.png");
painter.drawImage(QRectF(75, 65, 50, 70), jordanImage);

painter.end();


}
void iconWidget::drawCircle(QPainter &painter, int x, int y)
{
    QBrush circleBrush = QBrush(QColor(231, 94, 0));
    QPen circlePen = QPen(Qt::black);
    painter.setBrush(circleBrush);
    painter.setPen(circlePen);
    painter.drawEllipse(x, y, 25, 25);
}

