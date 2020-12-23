#include "Elections.h"
#include "ElectionsRepo.h"

Elections::Elections(int id,std::string fullname, std::string birthDate, std::string work, const std::string &rating) {
    this->_fullName = std::move(fullname);
    this->_birthDate = std::move(birthDate);
    this->_job = std::move(work);
    this->_rating = std::stod(rating);
    _id = id;
}

double Elections::GetRating() const {
    return _rating;
}

std::string Elections::GetBirthDate() const{
    return _birthDate;
}

std::string Elections::GetJob() const{
    return _job;
}

std::string Elections::GetFullName() const{
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

std::string Elections::ToString() const{

    return "Elections { "
           "id: '"+ std::to_string(_id)+
           "', fullName: '" + _fullName +
           "', birthDate: '" + _birthDate +
           "', job: '" + _job +
           "', rating: '" + std::to_string(_rating) +
           "' }";
}

int Elections::getID() const {
    return _id;
}

