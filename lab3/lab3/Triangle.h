#pragma once
#include "Shape.h"

class Triangle : public Shape {
public:
    explicit Triangle(Point* points[3]);

    Point GetCenter() override;

    std::string GetType() const override {
        return "Triangle";
    }
};
