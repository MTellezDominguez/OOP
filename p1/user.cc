#include "user.h"
#include <string>

User::User(std::string id) {
    id_ = id;

    name_ = "";
    surname_ = "";
    nationality_ = "";
    d_ = 0;
    m_ = 0;
    y_ = 0;
    complete_ = false;   
}

User::User(std::string id, std::string surname, std::string name, std::string nationality, int d, int m, int y) {
    id_ = id;
    surname_ = surname;
    name_ = name;
    nationality_ = nationality;
    d_ = d;
    m_ = m;
    y_ = y;


    if (id_.empty() || name_.empty() || surname_.empty() || nationality_.empty() || d_ < 1 || m_ < 1 || y_ < 1) {
        complete_ = false;
    }
    else {
        complete_ = true;
    }
}

std::string User::GetId() const {
    return id_;
}

std::string User::GetSurname() const {
    return surname_;
}

std::string User::GetName() const {
    return name_;
}

std::string User::GetNationality() const {
    return nationality_;
}

int User::GetDay() const {
    return d_;
}

int User::GetMonth() const {
    return m_;
}

int User::GetYear() const {
    return y_;
}

bool User::GetComplete() const {
    return complete_;
}

bool User::SetId(std::string id) {
    if (id.empty()) {
        return false;
    }
    id_ = id;
    return true;
}

bool User::SetSurname(std::string surname) {
    if (surname.empty()) {
        return false;
    }
    surname_ = surname;
    return true;
}

bool User::SetName(std::string name) {
    if (name.empty()) {
        return false;
    }
    name_ = name;
    return true;
}

bool User::SetNationality(std::string nationality) {
    if (nationality.empty()) {
        return false;
    }
    nationality_ = nationality;
    return true;
}

bool User::SetDay(int d) {
    if (d < 1) {
        return false;
    }
    d_ = d;
    return true;
}

bool User::SetMonth(int m) {
    if (m < 1) {
        return false;
    }
    m_ = m;
    return true;
}

bool User::SetYear(int y) {
    if (y < 1) {
        return false;
    }
    y_ = y;
    return true;
}

