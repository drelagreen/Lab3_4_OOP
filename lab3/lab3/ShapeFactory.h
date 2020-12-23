#pragma once

#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "exception"
class ShapeFactory {
public:
    static Shape* createShape(int count, Point** points);
};
