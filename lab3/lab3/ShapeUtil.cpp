
#include "ShapeUtil.h"

bool ShapeUtil::CheckIntersectionOfTwoLines(Point p1, Point p2, Point p3, Point p4) {
    if (p2.x < p1.x) {
        std::swap(p1, p2);
    }

    if (p4.x < p4.x) {
        std::swap(p3, p4);
    }

    if (p2.x < p3.x) {
        return false;
    }

    if ((p1.x - p2.x == 0) && (p3.x - p4.x == 0)) {
        if (p1.x == p3.x) {
            if (!((std::max(p1.y, p2.y) < std::min(p3.y, p4.y)) ||
                  (std::min(p1.y, p2.y) > std::max(p3.y, p4.y)))) {
                return true;
            }
        }
        return false;
    }

    if (p1.x - p2.x == 0) {
        double Xa = p1.x;
        double A2 = (p3.y - p4.y) / (p3.x - p4.x);
        double b2 = p3.y - A2 * p3.x;
        double Ya = A2 * Xa + b2;
        if (p3.x <= Xa && p4.x >= Xa && std::min(p1.y, p2.y) <= Ya &&
            std::max(p1.y, p2.y) >= Ya) {
            return true;
        }
        return false;
    }

    if (p3.x - p4.x == 0) {
        double Xa = p3.x;
        double A1 = (p1.y - p2.y) / (p1.x - p2.x);
        double b1 = p1.y - A1 * p1.x;
        double Ya = A1 * Xa + b1;
        if (p1.x <= Xa && p2.x >= Xa && std::min(p3.y, p4.y) <= Ya &&
            std::max(p3.y, p4.y) >= Ya) {
            return true;
        }
        return false;
    }

    double A1 = (p1.y - p2.y) / (p1.x - p2.x);
    double A2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b1 = p1.y - A1 * p1.x;
    double b2 = p3.y - A2 * p3.x;

    if (A1 == A2) {
        return false;
    }

    double Xa = (b2 - b1) / (A1 - A2);

    if ((Xa < std::max(p1.x, p3.x)) || (Xa > std::min(p2.x, p4.x))) {
        return false;
    } else {
        return true;
    }
}

bool ShapeUtil::CheckIntersection(const Shape &s1, const Shape &s2) {
    Point p1, p2;
    Point p3, p4;
    for (int i = 0; i < s1.GetPointsCount(); i++) {
        p1 = *s1.GetPoint(i);
        if (i != s1.GetPointsCount() - 1) {
            p2 = *s1.GetPoint(i + 1);
        } else {
            p2 = *s1.GetPoint(0);
        }
        for(int j = 0; j < s2.GetPointsCount(); j++){
            p3 = *s2.GetPoint(i);
            if (j != s2.GetPointsCount() - 1) {
                p4 = *s2.GetPoint(j + 1);
            } else {
                p4 = *s2.GetPoint(0);
            }
            bool x = CheckIntersectionOfTwoLines(p1,p2,p3,p4);
            if (x){
                return true;
            }
        }
    }
    return false;
}
