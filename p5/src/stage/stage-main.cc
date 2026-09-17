#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "catalog.h"
#include "stage.h"

int main() {
    CyclistCatalog catalog;

    if (!catalog.Load("../data/cyclists.csv")) {
        std::cerr << "Error: No se pudo cargar el archivo cyclists.csv" << std::endl;
        return 1;
    }

    std::cout << "Catálogo cargado con " << catalog.Size() << " ciclistas." << std::endl;

    Stage stage(1);
    stage.Simulate(catalog.Data());

    std::cout << "\n--- Resultados de la Etapa ---" << std::endl;
    std::cout << "Nombre,ID,Retraso (s)" << std::endl;

    const std::map<std::string, int>& delay_map = stage.GetDelays();

    std::vector<Cyclist> all_cyclists = catalog.Data();

    for (const auto& cyclist : all_cyclists) {
        std::string id = cyclist.GetCyclistId();
        
        try {
            int delay = delay_map.at(id);
            std::cout << cyclist.GetName() << ","
                      << id << ","
                      << delay << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: El ciclista " << id << " no fue encontrado en el mapa de retrasos." << std::endl;
        }
    }

    return 0;
}