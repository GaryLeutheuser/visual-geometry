#include "visual_geometry.h"

visualgeometry::Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int visualgeometry::Point::getX(void) {
    return this->x;
}

int visualgeometry::Point::getY(void) {
    return this->y;
}

