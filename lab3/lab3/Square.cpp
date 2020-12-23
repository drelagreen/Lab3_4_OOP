
#include "Square.h"

Square::Square(Point **points) : Shape(4, points) {
    _area = pow(_points[3]->x - _points[0]->x, 2);
}

Point Square::GetCenter() {
    Point p;
    p.x = _points[0]->x + (_points[2]->x - _points[0]->x) / 2;
    p.y = _points[0]->y + (_points[2]->y - _points[0]->y) / 2;
    return p;
}

std::string Square::GetType() const {
    return "Square";
}
