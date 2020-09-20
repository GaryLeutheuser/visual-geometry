#include "visual_geometry.h"
#include "plot.h"

#include <QApplication>
#include <iostream>
#include <list>

typedef visualgeometry::Point Point;
typedef visualgeometry::Line Line;
typedef visualgeometry::Display Display;

Display::Display(std::list<Point> points, std::list<Line> lines) {
    this->points = points;
    this->lines = lines;
}

void Display::DrawPlot(void) {
    // No need for argc/argv. Pass in 0 / empty list.
    int fake_argc = 0;
    char * fake_argv[0];
    QApplication app(fake_argc, fake_argv);

    // Set up the window.
    Plot window;

    // Set up the points.
    std::list<QPoint> qpoints;
    for (Point p : this->points) {
        qpoints.push_back(QPoint(p.getX(), p.getY()));
    }
    window.setPoints(qpoints);

    // Set up the lines.
    std::list<QLine> qlines;
    for (Line l : this->lines) {
        QPoint begin = QPoint(l.getBegin().getX(), l.getBegin().getY());
        QPoint end = QPoint(l.getEnd().getX(), l.getEnd().getY());
        qlines.push_back(QLine(begin, end));
    }
    window.setLines(qlines);

    window.setWindowTitle("Plot");
    window.show();

    // Run the application.
    app.exec();
}
