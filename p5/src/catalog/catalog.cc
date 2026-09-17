#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits.h>
#include "persons.h"
#include "catalog.h"

bool CyclistCatalog::Load(const std::string& path) {
    Cyclist c;
    std::string name, birth_s, id, team;
    int birthyear = 0;
    cyclists_.clear(); // Elimina todos los elementos si hubiera
    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }
    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line); // Define un stream de lectura a partir de line
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, id, ',')) continue;
        if (!std::getline(iss, team)) continue;
        birthyear = std::stoi(birth_s);
        c.SetName(name);
        c.SetBirthYear(birthyear);
        c.SetCyclistId(id);
        c.SetTeam(team);
        cyclists_.push_back(c); // se hace una copia al final del vector
    }
    return !cyclists_.empty();
}

int CyclistCatalog::Size() const{
    return cyclists_.size();
}

std::vector<Cyclist> CyclistCatalog::Data() const{
    return cyclists_;
}

bool DirectorCatalog::Load(const std::string& path) {
    Director c;
    std::string name, birth_s, id, team, since;
    int birthyear = 0, directorsince = 0;
    director_.clear(); // Elimina todos los elementos si hubiera
    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }
    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line); // Define un stream de lectura a partir de line
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, id, ',')) continue;
        if (!std::getline(iss, team, ',')) continue;
        if (!std::getline(iss, since)) continue;
        birthyear = std::stoi(birth_s);
        directorsince = std::stoi(since);
        c.SetName(name);
        c.SetBirthYear(birthyear);
        c.SetUciLicenseId(id);
        c.SetTeam(team);
        c.SetDirectorSince(directorsince);
        director_.push_back(c); // se hace una copia al final del vector
    }
    return !director_.empty();
}

int DirectorCatalog::Size() {
    return director_.size();
}

std::vector<Director> DirectorCatalog::Data() {
    return director_;
}

std::string CyclistCatalog::GetTeam(const std::string& cyclist_id){
    int s=Size();
    for(int i=0; i<s; i++){
        if(cyclist_id == cyclists_[i].GetCyclistId()){
            return cyclists_[i].GetTeam();
        }
    }
    std::cout<<"Error en el ID\n";
    exit(EXIT_FAILURE);
}

std::vector<Cyclist> CyclistCatalog::GetByTeam(const std::string& team){
    int s=Size();
    int cont=0;
    for(int i=0; i<s;i++){
        if(team== cyclists_[i].GetTeam()){
            cont++;
        }
    }
    std::vector<Cyclist> vectorequipo(cont);
    int j=0; 
    for(int i=0; i<s;i++){
        if(team == cyclists_[i].GetTeam()){
            vectorequipo[j]=cyclists_[i];
            j++;
        }
    }
    return vectorequipo;
}

std::vector<Cyclist> CyclistCatalog::GetYoungest(){
    int s=Size();
    int comp=INT_MIN;
    int cont=0;
    for(int i=0; i<s; i++){
        if(comp < cyclists_[i].GetBirthYear()){
            comp=cyclists_[i].GetBirthYear();
        }
    }
    for(int i=0; i<s; i++){
        if(comp == cyclists_[i].GetBirthYear()){
            cont++;
        }
    }
    std::vector<Cyclist> youngests(cont);
    cont=0;
    for(int i=0; i<s; i++){
        if(comp == cyclists_[i].GetBirthYear()){
            youngests[cont]=cyclists_[i];
            cont++;
        }
    }
    return youngests;
}

void CyclistCatalog::Add(Cyclist cyclist){
    cyclists_.push_back(cyclist);
}