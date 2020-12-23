#pragma once

#include <cmath>
#include "Shape.h"
#include <string>
#include "Point.h"

class Square : public Shape{
public:
    explicit Square(Point* points[4]);

    Point GetCenter() override;

    std::string GetType() const override;
};
