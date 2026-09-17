#ifndef PERSONS_H
#define PERSONS_H

#include <string>

class Person {
private:
    std::string name_;
    int birth_year_;
public:
    // Constructores
    Person() { name_ = "UNKNOWN"; birth_year_ = -1; }
    Person(const std::string& name, int birth_year) { name_ = name; birth_year_ = birth_year; }

    // Getters
    std::string GetName() const { return name_; }
    int GetBirthYear() const { return birth_year_; }

    // Setters
    void SetName(const std::string name);
    void SetBirthYear(int birth_year);
};

class Cyclist : public Person {
private:
    std::string team_;
    std::string cyclist_id_;
public:
    // Constructores
    Cyclist();
    Cyclist(const std::string& name, int birth_year, const std::string& team, const std::string& cyclist_id);

    // Getters
    std::string GetTeam() const { return team_; }
    std::string GetCyclistId() const { return cyclist_id_; }

    // Setters
    void SetTeam(const std::string& team);
    void SetCyclistId(const std::string& cyclist_id);
};

class Director : public Person { 
private:
    std::string team_;
    std::string uci_license_id_;
    int director_since_;
public:
    // Constructores 
    Director();
    Director(const std::string& name, int birth_year, const std::string& team, const std::string& uci_license_id, int director_since);

    // Getters
    std::string GetTeam() const { return team_; }
    std::string GetUciLicenseId() const { return uci_license_id_; }
    int GetDirectorSince() const { return director_since_; } 

    // Setters
    void SetTeam(const std::string& team);
    void SetUciLicenseId(const std::string& uci_license_id);
    void SetDirectorSince(int director_since);
};

#endif // PERSONS_H