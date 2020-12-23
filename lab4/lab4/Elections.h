#pragma once
#include <string>

class Elections {
private:
    int _id;
    std::string _fullName;
    std::string _birthDate;
    std::string _job;
    double _rating;
public:
    Elections(int id, std::string fullname, std::string birthDate, std::string work, const std::string &rating);

    std::string ToString() const;

    bool operator<(const Elections &e) const;

    std::string GetFullName() const;

    std::string GetJob() const;

    std::string GetBirthDate() const;

    double GetRating() const;

    int getID() const;
};
