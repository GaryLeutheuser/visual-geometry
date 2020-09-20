#include "visual_geometry.h"

#include <iostream>
#include <QApplication>
#include <QWidget>

void VisualGeometry::HelloWorld(int argc, char * argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Lines");
    window.show();
    app.exec();
}
