#include "Triangle.h"

Triangle::Triangle(Point **points) : Shape(3, points) {
    /*
     * | |x0-x2  y0-y2| | = abs(...)
     * | |x1-x2  y1-y2| |
     * */
    _area = (points[0]->x - points[2]->x)*(points[1]->y - points[2]->y) - (points[0]->y - points[2]->y)*(points[1]->x - points[2]->x);
    if (_area<0) _area = -_area;
}
Point Triangle::GetCenter() {
    Point p;
    p.x = (_points[0]->x+_points[1]->x+_points[2]->x)/3;
    p.y = (_points[0]->y+_points[1]->y+_points[2]->y)/3;
    return p;
}


