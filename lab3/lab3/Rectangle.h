#pragma once

#include <cmath>
#include "Shape.h"
#include <string>

class Rectangle : public Shape {

public:
    explicit Rectangle(Point *points[4]);

    Point GetCenter() override;

    std::string GetType() const override;
};

