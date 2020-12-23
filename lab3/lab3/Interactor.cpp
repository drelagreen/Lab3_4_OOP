
#include "Interactor.h"

int Interactor::GetIndex() {
    int index = 0;
    std::cout << "Index of shape (0-9)>\n";
    std::cin >> index;
    if (index < 0 || index > 9) {
        throw Exception("Incorrect index!");
    }
    return index;
}

void Interactor::Loop() {
    while (_run) {
        ShowMenu();
        int o;
        std::cout << "> ";
        std::cin >> o;
        try {
            Execute(o);
        } catch (std::exception &e) {
            std::cout << e.what() <<std::endl;
        }
    }
}

void Interactor::Execute(int o) {
    switch (o) {
        case 1: {
            int creationMode;
            int index = GetIndex();

            std::cout << "1 - Square or Rectangle\n2 - Triangle>\n";
            std::cin >> creationMode;

            if (creationMode == 1) {
                std::cout << "Diagonal coordinates:\n";
                double x1, x2, y1, y2;
                std::cout << "X1 Y1>\n";
                std::cin >> x1 >> y1;
                std::cout << "X2 Y2\n";
                std::cin >> x2 >> y2;
                if (x1 == x2 || y1 == y2) {
                    std::cout << "Incorrect coordinates!\n";
                    break;
                }
                auto p1 = new Point(x1, y1);
                auto p2 = new Point(x2, y2);

                Point* pArray[2]{p1, p2};
                delete _shapes[index];
                _shapes[index] = ShapeFactory::createShape(2, pArray);
                std::cout << "\nOK\n";

            } else if (creationMode == 2) {
                std::cout << "Triangle coordinates:\n";
                double x1, x2, x3, y1, y2, y3;

                std::cout << "X1 Y1>\n";
                std::cin >> x1 >> y1;
                std::cout << "X2 Y2\n";
                std::cin >> x2 >> y2;
                std::cout << "X3 Y3\n";
                std::cin >> x3 >> y3;

                if (x1 == x2 && x2 == x3 || y1 == y2 && y1 == y3 || (y1 - y2) * x3 + (x2 - x1) * y3 + (x1 * y2 - x2 * y1) == 0) {
                    std::cout << "Incorrect coordinates!\n";
                    break;
                }
                auto p1 = new Point(x1, y1);
                auto p2 = new Point(x2, y2);
                auto p3 = new Point(x3, y3);

                Point* pArray[3]{p1,p2,p3};
                delete _shapes[index];
                _shapes[index] = ShapeFactory::createShape(3, pArray);
                std::cout << "OK\n";
            }
            break;
        }
        case 2: {
            int index = GetIndex();
            delete _shapes[index];
            _shapes[index] = nullptr;
            std::cout << "OK\n";

            break;
        }
        case 3: {
            for (int i = 0; i < 10; i++) {
                std::cout << "\nShape #" << i << "\n";
                if (!_shapes[i]){
                    std::cout<<"Null\n";
                    continue;
                }
                std::cout << "Type: " << _shapes[i]->GetType() << "\n"
                          << "Coordinates: \n";
                for (int j = 0; j < _shapes[i]->GetPointsCount(); j++) {
                    std::cout << "    Point #" << j << " X = " << _shapes[i]->GetPoint(j)->x << " Y = "
                              << _shapes[i]->GetPoint(j)->y << "\n";
                }
                std::cout
                        << "Center of mass: X = " << _shapes[i]->GetCenter().x << " Y = "
                        << _shapes[i]->GetCenter().y << "\n"
                        << "Area: " << _shapes[i]->GetArea() << "\n";
            }

            break;
        }
        case 4: {
            int index = GetIndex();
            if (!_shapes[index]){
                std::cout << "This shape has not been initialized!\n";
                break;
            }
            double x, y;
            std::cout << "X > \n";
            std::cin >> x;
            std::cout << "Y > \n";
            std::cin >> y;
            _shapes[index]->Move(x, y);
            std::cout << "OK\n";
            break;
        }
        case 5: {
            std::cout<<"Shape 1>\n";
            int index1 = GetIndex();
            if (!_shapes[index1]){
                std::cout << "Shape "<<index1<<" has not been initialized!\n";
                break;
            }
            std::cout<<"Shape 2>\n";
            int index2 = GetIndex();
            if (!_shapes[index2]){
                std::cout << "Shape "<<index2<<" has not been initialized!\n";
                break;
            }

            if (!ShapeUtil::CheckIntersection(*_shapes[index1], *_shapes[index2])){
                std::cout << "Shapes do not intersect each other. INTERSECTION - FALSE\n";
            } else {
                std::cout << "Shapes intersect each other. INTERSECTION - TRUE\n";
            };

            break;
        }
        case 0:
            _run = false;
            break;
        default:
            break;
    }
}

void Interactor::ShowMenu() {
    std::cout
            << "\n1 - Create new Shape\n"
            << "2 - Remove Shape\n"
            << "3 - Print info\n"
            << "4 - Move Shape\n"
            << "5 - Check intersection\n"
            << "0 - Exit\n";
}


Interactor::~Interactor() {
    for(auto & _shape : _shapes){
        delete _shape;
    }
}
