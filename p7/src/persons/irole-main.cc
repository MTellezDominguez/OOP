#include <iostream>
#include "persons.h"

int main() {
    Cyclist c1("Miguel Indurain", 1964, "Banesto", "ESP-1991");
    Director d1("Eusebio Unzue", 1955, "Movistar Team", "UCI-DIR-001", 1980);
    Journalist j1("Antonio Alix", 1970, "Eurosport");

    c1.SetComment("Hoy las piernas han respondido bien en la montana");
    d1.SetComment("La estrategia del equipo ha funcionado a la perfeccion");

    j1.SetComment("ESP-1991", "Indurain mantiene el liderato con solidez");
    j1.SetComment("SLO-2020", "Pogacar ha atacado tres veces sin exito");
    j1.SetComment("DEN-2022", "Vingegaard se mantiene a la expectativa");

    std::cout << PrintComment(&c1);
    std::cout << PrintComment(&d1);
    std::cout << PrintComment(&j1);

    return 0;
}