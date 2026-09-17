#ifndef PERSONS_H
#define PERSONS_H

#include <string>
#include <map>

class IRole{
    public:
        virtual std::string GetRole()=0;
        virtual std::string GetComment()=0;
};

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

class Cyclist : public Person, public IRole {
private:
    std::string team_;
    std::string cyclist_id_;
    std::string self_report_;
public:
    // Constructores
    Cyclist();
    Cyclist(const std::string& name, int birth_year, const std::string& team, const std::string& cyclist_id);

    // Getters
    std::string GetTeam() const { return team_; }
    std::string GetCyclistId() const { return cyclist_id_; }
    std::string GetComment() override;
    std::string GetRole() override;

    // Setters
    void SetTeam(const std::string& team);
    void SetCyclistId(const std::string& cyclist_id);
    bool SetComment(const std::string& self_report);
};

class Director : public Person, public IRole {
private:
    std::string team_;
    std::string uci_license_id_;
    int director_since_;
    std::string team_report_;
public:
    // Constructores 
    Director();
    Director(const std::string& name, int birth_year, const std::string& team, const std::string& uci_license_id, int director_since);

    // Getters
    std::string GetTeam() const { return team_; }
    std::string GetUciLicenseId() const { return uci_license_id_; }
    int GetDirectorSince() const { return director_since_; }
    std::string GetComment() override;
    std::string GetRole() override;

    // Setters
    void SetTeam(const std::string& team);
    void SetUciLicenseId(const std::string& uci_license_id);
    void SetDirectorSince(int director_since);
    bool SetComment(const std::string& team_report);
};

class Journalist : public Person, public IRole {
private:
    std::string media_;
    std::map<std::string, std::string> comments_;
public:
    Journalist();
    Journalist(const std::string& name, int birth_year, const std::string& media);
    std::string GetMedia() const {return media_;}
    bool SetMedia(const std::string& media);
    bool SetComment(const std::string& id, const std::string& report);
    std::string GetComment() override;
    std::string GetRole() override;
};


std::string PrintComment(IRole *objeto);
#endif // PERSONS_H