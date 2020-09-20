#include "visual_geometry.h"

typedef visualgeometry::Point Point;

visualgeometry::Line::Line(Point begin, Point end) {
    this->begin = begin;
    this->end = end;
}

Point visualgeometry::Line::getBegin(void) {
    return this->begin;
}

Point visualgeometry::Line::getEnd(void) {
    return this->end;
}
