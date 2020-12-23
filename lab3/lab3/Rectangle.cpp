
#include "Rectangle.h"

Rectangle::Rectangle(Point **points) : Shape(4, points) {
    _area = (_points[3]->x - _points[0]->x) * (_points[1]->y - _points[0]->y);
}

Point Rectangle::GetCenter() {
    Point p;
    p.x = _points[0]->x + (_points[2]->x - _points[0]->x) / 2;
    p.y = _points[0]->y + (_points[2]->y - _points[0]->y) / 2;
    return p;
}

std::string Rectangle::GetType() const {
    return "Rectangle";
}
