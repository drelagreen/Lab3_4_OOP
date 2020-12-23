
#include "ShapeFactory.h"

Shape *ShapeFactory::createShape(int count, Point **points) {
    if (count == 2) { //diagonal
        Point* shPoints[4];
        if (points[0]->y > points[1]->y)
            std::swap(points[0], points[1]);
        shPoints[0] = points[0];
        shPoints[2] = points[1];
        shPoints[1] = new Point(shPoints[0]->x, shPoints[2]->y);
        shPoints[3] = new Point(shPoints[2]->x, shPoints[0]->y);

        if (shPoints[1]->y - shPoints[0]->y == shPoints[3]->x - shPoints[0]->x) {
            auto *square = new Square(shPoints);
            return square;
        } else {
            auto *rectangle = new Rectangle(shPoints);
            return rectangle;
        }
    } else if (count == 3){
        auto *triangle = new Triangle(points);
        return triangle;
    } else {
        return nullptr;
    }
}
