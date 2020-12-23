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
            Elections e(name1.append(" ").append(name2).append(" ").append(name3), date, work, rating);
            Save(e);
        }
    }
    in.close();
}

void ElectionsRepo::Save(const Elections &e) {
    std::set<Elections> s;
    if (!_localDatabase.contains(e.GetRating())) {
        s.insert(e);
        _localDatabase.insert(std::pair<double, std::set<Elections>>(e.GetRating(), s));
    } else {
        s = _localDatabase[e.GetRating()];
        s.insert(e);
        _localDatabase[e.GetRating()] = s;
    }
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
