
#include "Shape.h"

Shape::Shape(int count, Point **points) {
    _points = new Point*[count];
    memcpy (_points, points, sizeof(Point*)*count);
    this->_count = count;
}


void Shape::Move(double x, double y) {
    for (int i = 0; i < _count; i++) {
        _points[i]->x += x;
        _points[i]->y += y;
    }
}

Point *Shape::GetPoint(int p) const {
    return _points[p];
}

int Shape::GetPointsCount() const {
    return _count;
}

double Shape::GetArea() const {
    return _area;
}

Shape::~Shape() {
    for(int i =0; i< _count; i++){
        delete _points[i];
    }
    delete _points;
}

