#pragma once

#include <iostream>
#include "Shape.h"
#include "ShapeFactory.h"
#include "Exception.h"
#include "ShapeUtil.h"

class Interactor {
private:
    bool _run = true;
    Shape *_shapes[10]{nullptr};
public:
    void ShowMenu();

    void Execute(int o);

    void Loop();

    static int GetIndex();

    ~Interactor();
};


