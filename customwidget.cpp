#include "customwidget.h"

#include <QPainter>

CustomWidget::CustomWidget(QWidget* parent)
    : QWidget(parent)
{
}

void CustomWidget::paintEvent(QPaintEvent* /* event */)
{
    QPainter painter(this);
    painter.setBrush(Qt::GlobalColor::gray);
    painter.drawRect(QRect(0, 0, this->width() - 1, this->height() - 1));
    painter.setBrush(QBrush(QColorConstants::Svg::yellow, Qt::SolidPattern));
    painter.setPen(QPen(Qt::yellow, 5, Qt::CustomDashLine));
    painter.drawEllipse(60,60,60,60);
    painter.setPen(QPen(Qt::yellow, 5, Qt::CustomDashLine));
    painter.drawLine(90, 35, 90, 145);
    painter.drawLine(35, 90, 145, 90);
    painter.drawLine(50, 50, 130, 130);
    painter.drawLine(130, 50, 50, 130);
}
