#include <string>
#include <iostream>
#include <map>
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

Journalist::Journalist(){
    media_="UNKNOWN";
    Person();
}

Journalist::Journalist(const std::string& name, int birth_year, const std::string& media){
    media_=media;
    SetName(name);
    SetBirthYear(birth_year);
}

bool Journalist::SetMedia(const std::string& media){
    bool r;
    if(media==""){
        media_="UNKNOWN";
        r=false;
    }
    else{
        media_=media;
        r=true;
    }
    return r;
}

bool Cyclist::SetComment(const std::string& self_report){
    bool r;
    if(self_report==""){
        r=false;
    }
    else{
        self_report_=self_report;
        r=true;
    }
    return r;
}

std::string Cyclist::GetComment(){
    std::string comment="COMENTARIO CICLISTA\n"+self_report_+"\n";
    return comment;
}

std::string Cyclist::GetRole(){
    std::string role=GetName()+","+std::to_string(GetBirthYear())+","+team_+","+cyclist_id_+"\n";
    return role;
}

bool Director::SetComment(const std::string& team_report){
    bool r;
    if(team_report==""){
        r=false;
    }
    else{
        team_report_=team_report;
        r=true;
    }
    return r;
}

std::string Director::GetComment(){
    std::string comment="COMENTARIO DIRECTOR\n"+team_report_+"\n";
    return comment;
}

std::string Director::GetRole(){
    std::string role=GetName()+","+std::to_string(GetBirthYear())+","+team_+","+uci_license_id_+","+std::to_string(director_since_)+"\n";
    return role;
}

bool Journalist::SetComment(const std::string& id, const std::string& report){
    bool r;
    if(id==""||report==""){
        r=false;
    }
    else{
        comments_[id]=report;
        r=true;
    }
    return r;
}

std::string Journalist::GetComment(){
    std::map<std::string, std::string>::iterator it;
    std::string comment="COMENTARIO JOURNALIST\n";
    for(it=comments_.begin(); it!=comments_.end(); it++){
        comment+=it->first+","+it->second+"\n";
    }
    return comment;
}

std::string Journalist::GetRole(){
    std::string role=GetName()+","+std::to_string(GetBirthYear())+","+media_+"\n";
    return role;
}

std::string PrintComment(IRole *objeto){
    return objeto->GetRole() + objeto->GetComment();
}