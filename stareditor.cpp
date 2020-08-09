#include "stareditor.h"
#include <QPainter>
#include <QMouseEvent>

StarEditor::StarEditor(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);

    poly << QPoint(0, 85) << QPoint(75, 75)
         << QPoint(100, 10) << QPoint(125, 75)
         << QPoint(200, 85) << QPoint(150, 125)
         << QPoint(160, 190) << QPoint(100, 150)
         << QPoint(40, 190) << QPoint(50, 125)
         << QPoint(0, 85);
}

int StarEditor::getStarRating() const
{
    return starRating;
}

void StarEditor::setStarRating(int value)
{
    starRating = value;
}

void StarEditor::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    emit editingFinished();
}

void StarEditor::mouseMoveEvent(QMouseEvent *event)
{
    int rating = event->x()/20 + 1;

    if((rating != starRating) && (rating < 6)){
        starRating = rating;
        update();
    }
}

void StarEditor::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QBrush(Qt::green));
    painter.drawRect(rect());

    painter.setBrush(QBrush(Qt::yellow));

    painter.translate(rect().x(), rect().y() + 5);
    painter.scale(0.05, 0.05);

    for(int i = 0; i < starRating; i++){
        painter.drawPolygon(poly);
        painter.translate(220, 0);
    }


    painter.restore();
}

QSize StarEditor::sizeHint() const
{
    return QSize(100, 50);
}
