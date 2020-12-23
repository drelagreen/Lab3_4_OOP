#pragma once

#include "Shape.h"
#include <cmath>

class ShapeUtil {
private:
    ShapeUtil() = default;
public:
    static bool CheckIntersectionOfTwoLines(Point p1, Point p2, Point p3, Point p4);

    static bool CheckIntersection(const Shape &s1, const Shape &s2);
};

