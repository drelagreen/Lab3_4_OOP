#include "Elections.h"

Elections::Elections(std::string fullname, std::string birthDate, std::string work, const std::string &rating) {
    this->_fullName = std::move(fullname);
    this->_birthDate = std::move(birthDate);
    this->_job = std::move(work);
    this->_rating = std::stod(rating);
}

double Elections::GetRating() const {
    return _rating;
}

std::string Elections::GetBirthDate() {
    return _birthDate;
}

std::string Elections::GetJob() {
    return _job;
}

std::string Elections::GetFullName() {
    return _fullName;
}

bool Elections::operator<(const Elections &e) const{
    if (_rating < e._rating) {
        return true;
    } else {
        if (_rating == e._rating && _fullName < e._fullName) {
            return true;
        } else {
            if (_rating == e._rating && _fullName == e._fullName && _job < e._job) {
                return true;
            } else {
                if (_rating == e._rating && _fullName == e._fullName && _job == e._job && _birthDate < e._birthDate) {
                    return true;
                }
            }
        }
    }
    return false;
}

std::string Elections::ToString() {
    return "Elections { "
           "fullName: '" + _fullName +
           "', birthDate: '" + _birthDate +
           "', job: '" + _job +
           "', rating: '" + std::to_string(_rating) +
           "' }";
}

