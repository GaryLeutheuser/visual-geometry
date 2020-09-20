#ifndef PLOT_H
#define PLOT_H

#include <QPainter>
#include <QWidget>
#include <list>

#include "visual_geometry.h"

class Plot : public QWidget {
    private:
        std::list<QPoint> points;
        std::list<QLine> lines;

    public:
        Plot(QWidget *parent = 0);
        void setPoints(std::list<QPoint> points);
        void setLines(std::list<QLine> lines);

    protected:
        void paintEvent(QPaintEvent *event);
        void drawElements(QPainter *qp);
};

#endif
