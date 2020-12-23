#include <list>
#include <map>
#include "ElectionsRepo.h"
#include <set>

void ElectionsRepo::Read(const std::string &path) {
    std::ifstream in(path);
    std::string line;
    if (!in.is_open()) {
        std::cout<<"Can not open the file!\n";
    } else {
        std::string name1;
        std::string name2;
        std::string name3;
        std::string date;
        std::string work;
        std::string rating;
        while (getline(in, line)) {
            int nameEnd1 = line.find(' ', 0);
            name1 = line.substr(0, nameEnd1);

            int nameEnd2 = line.find(' ', nameEnd1 + 1);
            name2 = line.substr(nameEnd1 + 1, nameEnd2 - nameEnd1 - 1);

            int nameEnd = line.find(' ', nameEnd2 + 1);
            name3 = line.substr(nameEnd2 + 1, nameEnd - nameEnd2 - 1);

            int dateEnd = line.find(" \"", nameEnd + 1);
            date = line.substr(nameEnd + 1, dateEnd - nameEnd - 1);

            int workEnd = line.find("\" ", dateEnd + 1);
            work = line.substr(dateEnd + 2, workEnd - dateEnd - 2);

            int ratingEnd = line.length() - 1;
            rating = line.substr(workEnd + 2, ratingEnd - workEnd - 1);
            Elections e(GetNextID(),name1.append(" ").append(name2).append(" ").append(name3), date, work, rating);
            Save(e);
        }
    }
    in.close();
}

void ElectionsRepo::Save(const Elections &e) {
    if (!_localDatabase.contains(e.GetRating())) {
        std::set<Elections> s;
        s.insert(e);
        _localDatabase.insert(std::pair<double, std::set<Elections>>(e.GetRating(), s));
    } else {
        _localDatabase[e.GetRating()].insert(e);
    }
    _localIDs.insert(std::pair(e.getID(), e));
}

void ElectionsRepo::Write(const std::string &path) {
    std::ofstream out(path);
    if (out.is_open())
        for (const auto &set : _localDatabase) {
            for (auto e : set.second) {
                out << e.GetFullName() << " "
                    << e.GetBirthDate() << " \""
                    << e.GetJob() << "\" "
                    << e.GetRating() << "\n";
            }
        }
    else {
        std::cout<<"Can not open the file!\n";
    }
    out.close();
}

int ElectionsRepo::GetNextID() {
    return _id++;
}

void ElectionsRepo::Remove(int id) {
    int size = _localDatabase.size();

    for (auto i = _localDatabase.begin(); i != _localDatabase.end(); i++){
        auto j = i->second.begin();
        auto end = i->second.end();
        for (; j != end; j++){
            if (j->getID() == id){
                i->second.erase(j);
                if (i->second.empty()){
                    _localDatabase.erase(i);
                }
                std::cout<<"Erased!\n";
                return;
            }
        }
    }
    std::cout<<"Not found!\n";
}

std::map<double, std::set<Elections>>::iterator ElectionsRepo::GetBeginIterator() {
    return _localDatabase.begin();
}

std::map<double, std::set<Elections>>::iterator ElectionsRepo::GetEndIterator() {
    return _localDatabase.end();
}
