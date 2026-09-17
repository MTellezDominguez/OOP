#include <iostream>
#include "persons.h"

int main() {
    // Crear un ciclista
    Cyclist cyclist("Tadej Pogacar", 1998, "UAE Team Emirates", "SLO001");

    std::cout << "CICLISTA\n";
    std::cout << "Nombre: " << cyclist.GetName() << std::endl;
    std::cout << "Año de nacimiento: " << cyclist.GetBirthYear() << std::endl;
    std::cout << "Equipo: " << cyclist.GetTeam() << std::endl;
    std::cout << "ID de ciclista: " << cyclist.GetCyclistId() << std::endl;

    // Modificar datos del ciclista
    cyclist.SetTeam("Team Jumbo-Visma");
    cyclist.SetCyclistId("SLO002");

    std::cout << "\nDatos actualizados del ciclista:\n";
    std::cout << "Equipo: " << cyclist.GetTeam() << std::endl;
    std::cout << "ID de ciclista: " << cyclist.GetCyclistId() << std::endl;

    // Crear un director
    Director team_director("Marc Madiot", 1959, "Groupama-FDJ", "UCI12345", 2001);

    std::cout << "\nDIRECTOR\n";
    std::cout << "Nombre: " << team_director.GetName() << std::endl;
    std::cout << "Año de nacimiento: " << team_director.GetBirthYear() << std::endl;
    std::cout << "Equipo: " << team_director.GetTeam() << std::endl;
    std::cout << "Licencia UCI: " << team_director.GetUciLicenseId() << std::endl;
    std::cout << "Director desde: " << team_director.GetDirectorSince() << std::endl;

    return 0;
}
