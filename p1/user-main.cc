#include <iostream>
#include <string>
#include "user.h"

User ReadUserFromConsole() {
    std::string id, name, surname, nationality;
    int d, m, y;

    std::cout << "Ingrese el ID del usuario: ";
    std::cin >> id;

    std::cin.ignore(); 

    std::cout << "Ingrese el nombre: ";
    std::getline(std::cin, name);

    std::cout << "Ingrese el apellido: ";
    std::getline(std::cin, surname);

    std::cout << "Ingrese la nacionalidad: ";
    std::getline(std::cin, nationality);

    std::cout << "Ingrese el día de nacimiento: ";
    std::cin >> d;

    std::cout << "Ingrese el mes de nacimiento: ";
    std::cin >> m;

    std::cout << "Ingrese el año de nacimiento: ";
    std::cin >> y;

    User u(id, surname, name, nationality, d, m, y);
    return u;
}

void PrintUserToConsole(const User& u) {
    std::cout << "ID: " << u.GetId() << std::endl;
    std::cout << "Nombre: " << u.GetName() << std::endl;
    std::cout << "Apellido: " << u.GetSurname() << std::endl;
    std::cout << "Nacionalidad: " << u.GetNationality() << std::endl;
    std::cout << "Fecha de nacimiento: " << u.GetDay() << "/" << u.GetMonth() << "/" << u.GetYear() << std::endl;
}

int main() {
    User u("ID_Inicial");
    
    std::cout << "Paso 1: Objeto User creado e inicializado." << std::endl;

    u = ReadUserFromConsole();
    
    std::cout << "Paso 2: Datos leídos desde consola." << std::endl;

    PrintUserToConsole(u);
    
    std::cout << "Paso 3: Datos mostrados en pantalla. Fin del programa." << std::endl;

    return 0;
}