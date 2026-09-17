#ifndef USER_H
#define USER_H

#include <string>

class User {
    private:
        std::string id_;
        std::string surname_;
        std::string name_;
        std::string nationality_;
        int d_;
        int m_;
        int y_;
        bool complete_;

    public:
        User(std::string id);
        User(std::string id, std::string surname, std::string name, std::string nationality, int d, int m, int y);

        std::string GetId() const;
        std::string GetSurname() const;
        std::string GetName() const;
        std::string GetNationality() const;
        int GetDay() const;
        int GetMonth() const;
        int GetYear() const;
        bool GetComplete() const;

        bool SetId(std::string id);
        bool SetSurname(std::string surname);
        bool SetName(std::string name);
        bool SetNationality(std::string nationality);
        bool SetDay(int d);
        bool SetMonth(int m);
        bool SetYear(int y);
};

User ReadUserFromConsole();
void PrintUserToConsole(const User& user);

#endif