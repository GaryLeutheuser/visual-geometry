#ifndef VISUAL_GEOMETRY_H
#define VISUAL_GEOMETRY_H

#include <list>

namespace visualgeometry {
    class Point {
        public:
            Point(int x = 0, int y = 0);
            int getX(void);
            int getY(void);

        private:
            int x;
            int y;
    };

    class Line {
        public:
            Line(visualgeometry::Point begin, visualgeometry::Point end);
            visualgeometry::Point getBegin(void);
            visualgeometry::Point getEnd(void);

        private:
            visualgeometry::Point begin;
            visualgeometry::Point end;
    };    

    class Display {
        public:
            Display(std::list<visualgeometry::Point> points, std::list<visualgeometry::Line> lines);
            void DrawPlot(void);

        private:
            std::list<visualgeometry::Point> points;
            std::list<visualgeometry::Line> lines;
    };
}

#endif
