#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "persons.h"
#include "catalog.h"

int main() {
    CyclistCatalog c;
    DirectorCatalog d;
    d.Load("../data/directors.csv");
    c.Load("../data/cyclists.csv");
    int sizec = c.Size();
    std::vector<Cyclist> vc = c.Data();
    int sized = d.Size();
    std::vector<Director> vd = d.Data();
    int i;
    for (i = 0; i < sizec; i++) {
        std::cout << i + 1 << ".-Nombre: " << vc[i].GetName() << " Nacimiento: " << vc[i].GetBirthYear() << " Equipo: " << vc[i].GetTeam() << " ID: " << vc[i].GetCyclistId() << "\n";
    }
    std::cout << "\n\nSe han cargado " << i << " ciclistas\n\n";
    int cont = 0;
    for (auto& i : vd) {
        std::cout << "Nombre: " << i.GetName() << " Nacimiento: " << i.GetBirthYear() << " Equipo: " << i.GetTeam() << " ID: " << i.GetUciLicenseId() << " Desde: " << i.GetDirectorSince() << "\n";
        cont++;
    }
    std::cout << "\n\nSe han cargado " << cont << " directores\n\n";

    std::string nequipo;
    std::cout<< "Introduzca el nombre de un equipo para mostrarle sus ciclistas:\n";
    std::getline(std::cin, nequipo);
    std::vector<Cyclist> equipo=c.GetByTeam(nequipo);
    for (auto& i : equipo) {
        std::cout << "Nombre: " << i.GetName() << " Nacimiento: " << i.GetBirthYear() << " Equipo: " << i.GetTeam() << " ID: " << i.GetCyclistId() << "\n";
        cont++;
    }
    std::cout<<"\nA continuación se mostraran los datos del ciclista/ciclistas más jóvenes:\n";
    std::vector<Cyclist> jovenes=c.GetYoungest();
    for (auto& i : jovenes) {
        std::cout << "Nombre: " << i.GetName() << " Nacimiento: " << i.GetBirthYear() << " Equipo: " << i.GetTeam() << " ID: " << i.GetCyclistId() << "\n";
        cont++;
    }

    return 0;
}