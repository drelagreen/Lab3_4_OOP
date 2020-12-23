#pragma once

#include <string>
#include <cstring>
#include "Point.h"
#include "cmath"
class Shape {
private:
    int _count = 0;
protected:
    double _area = 0;
    Point **_points = nullptr;
    Shape(int count, Point **points);
public:
    virtual Point GetCenter()=0;

    double GetArea() const;

    virtual std::string GetType() const = 0;

    void Move(double x, double y);

    int GetPointsCount() const;

    Point* GetPoint(int p) const;

    virtual ~Shape();
};
