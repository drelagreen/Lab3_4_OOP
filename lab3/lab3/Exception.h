#pragma once
class Exception : public std::exception {
private:
    const char* reason;
public:
    explicit Exception(const char* reason) {
        this->reason = reason;
    }
    const char* what() const noexcept override {
        return reason;
    }
};