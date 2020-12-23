#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Elections.h"
#include <set>
#include <map>

class ElectionsRepo {
private:
    std::map<double, std::set<Elections>> _localDatabase;
public:
    void Read(const std::string &path);

    void Write(const std::string &path);

    void Save(const Elections &e);

    auto GetBeginIterator() {
            return _localDatabase.begin();

    }

    auto GetEndIterator(){
        return _localDatabase.end();
    }
};
