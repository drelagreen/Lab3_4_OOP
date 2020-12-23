#pragma once
#include <string>

class Elections {
private:
    std::string _fullName;
    std::string _birthDate;
    std::string _job;
    double _rating;
public:
    Elections(std::string fullname, std::string birthDate, std::string work, const std::string &rating);

    std::string ToString();

    bool operator<(const Elections &e) const;

    std::string GetFullName();

    std::string GetJob();

    std::string GetBirthDate();

    double GetRating() const;
};
