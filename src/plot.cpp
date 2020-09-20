#include "plot.h"
#include "visual_geometry.h"

#include <QPainter>
#include <QWidget>
#include <QPoint>
#include <QLine>

Plot::Plot(QWidget *parent)
    : QWidget(parent)
{ }

void Plot::setPoints(std::list<QPoint> points) {
    this->points = points;
}

void Plot::setLines(std::list<QLine> lines) {
    this->lines = lines;
}

void Plot::paintEvent(QPaintEvent *e) {
    
  Q_UNUSED(e);
  
  QPainter qp(this);
  drawElements(&qp);
}

void Plot::drawElements(QPainter *qp) {
  QPen pen(Qt::black, 5, Qt::SolidLine);
  qp->setPen(pen);

  for (QPoint point : this->points) {
      qp->drawPoint(point.x(), point.y());
  }

  for (QLine line : this->lines) {
      qp->drawLine(line.x1(), line.y1(), line.x2(), line.y2());
  }
}
