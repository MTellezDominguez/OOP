#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "persons.h"
#include "catalog.h"

int main(){
    Cyclist c1{"Thomas Pidcock", 1999, "Q36.5 Pro Cycling Team", "d1a1b001"};
    Cyclist c2{"Xabier Mikel Azparren", 1999, "Q36.5 Pro Cycling Team", "d1a1b002"};
    Cyclist c3{"Enekoitz Azparren", 2002, "Q36.5 Pro Cycling Team", "d1a1b003"};
    Cyclist c4{"Marcel Camprubí", 2001, "Q36.5 Pro Cycling Team", "d1a1b004"};

    CyclistCatalog c;
    c<<c1<<c2;
    c<<c3<<c4;

    int sizec = c.Size();
    std::vector<Cyclist> vc = c.Data();

    for (int i = 0; i < sizec; i++) {
        std::cout << i + 1 << ".-Nombre: " << vc[i].GetName() << " Nacimiento: " << vc[i].GetBirthYear() << " Equipo: " << vc[i].GetTeam() << " ID: " << vc[i].GetCyclistId() << "\n";
    }

    return 0;
}