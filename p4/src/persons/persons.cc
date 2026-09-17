#include <string>
#include <iostream>
#include "persons.h"

void Person::SetName(const std::string name){
    name_ = name;
}

void Person::SetBirthYear(int birth_year){
    birth_year_ = birth_year;
}

Cyclist::Cyclist(){
    team_ = "UNKNOWN";
    cyclist_id_ = "UNKNOWN";
    Person();
}

Cyclist::Cyclist(const std::string& name, int birth_year, const std::string& team, const std::string& cyclist_id){
    team_ = team;
    cyclist_id_ = cyclist_id;
    SetName(name);
    SetBirthYear(birth_year);
}

void Cyclist::SetTeam(const std::string &team){
    team_ = team;
}

void Cyclist::SetCyclistId(const std::string &cyclist_id){
    cyclist_id_ = cyclist_id;
}

Director::Director(){
    Person();
    team_ = "UNKNOWN";
    director_since_ = -1;
    uci_license_id_ = "UNKNOWN";
}

Director::Director(const std::string& name, int birth_year, const std::string& team, const std::string& uci_license_id, int director_since){
    SetName(name);
    SetBirthYear(birth_year);
    team_ = team;
    uci_license_id_ = uci_license_id;
    director_since_ = director_since;
}

void Director::SetTeam(const std::string& team){
    team_ = team;
}

void Director::SetUciLicenseId(const std::string& uci_license_id){
    uci_license_id_ = uci_license_id;
}

void Director::SetDirectorSince(int director_since){
    director_since_ = director_since;
}