#pragma once
struct Point{
    double x = 0;
    double y = 0;
    Point(double x, double y){
        this->y = y;
        this->x = x;
    }
    Point()= default;
};