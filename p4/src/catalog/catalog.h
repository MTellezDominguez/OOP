#ifndef CATALOG_H
#define CATALOG_H

#include <stdio.h>
#include <string>
#include <vector>
#include "persons.h"

class CyclistCatalog {
private:
    std::vector<Cyclist> cyclists_;
public:
    bool Load(const std::string& path);
    int Size() const;
    std::vector<Cyclist> Data() const;
    std::string GetTeam(const std::string& cyclist_id );
    std::vector<Cyclist> GetByTeam(const std::string& team);
    std::vector<Cyclist> GetYoungest();
};

class DirectorCatalog {
private:
    std::vector<Director> director_; 
public:
    bool Load(const std::string& path); 
    int Size();
    std::vector<Director> Data(); 
};

#endif //CATALOG_H