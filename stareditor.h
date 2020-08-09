#ifndef STAREDITOR_H
#define STAREDITOR_H

#include <QObject>
#include <QWidget>

class StarEditor : public QWidget
{
    Q_OBJECT
public:
    explicit StarEditor(QWidget *parent = nullptr);

    int getStarRating() const;
    void setStarRating(int value);

signals:
    void editingFinished();


    // QWidget interface
protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private :
    int starRating;
    QPolygon poly;

    // QWidget interface
public:
    QSize sizeHint() const;
};

#endif // STAREDITOR_H
