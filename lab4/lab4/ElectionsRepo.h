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
    int _id;
    std::map<double, std::set<Elections>> _localDatabase;
    std::map<const int, Elections> _localIDs;
public:
    void Read(const std::string &path);

    void Write(const std::string &path);

    void Save(const Elections &e);

    void Remove(int id);

    std::map<double, std::set<Elections>>::iterator GetBeginIterator();

    std::map<double, std::set<Elections>>::iterator GetEndIterator();

    int GetNextID();

};
