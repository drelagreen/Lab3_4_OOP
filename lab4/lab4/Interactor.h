#pragma once
#include "ElectionsRepo.h"
#include <iostream>
#include "vector"
#include "list"
#include <algorithm>
#include <map>
using namespace std;
class Interactor {
private:
    ElectionsRepo* _fileSystem;

    bool run = true;
    void PrintInfo(bool lgToSmall, double limiter);
public:
    void Loop();

    explicit Interactor(ElectionsRepo *fileSystem);

    ~Interactor(){
        delete _fileSystem;
    }
};

