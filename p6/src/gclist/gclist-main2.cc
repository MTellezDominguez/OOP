#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include "persons.h"
#include "catalog.h"
#include "stage.h"
#include "gclist.h"

int main(){
    CyclistCatalog c;
    c.Load("../data/cyclists.csv");
    Stage s1(1);
    s1.Simulate(c.Data());
    std::cout << "\n--- Resultados de la Etapa ---" << std::endl;
    std::cout << "Nombre,ID,Retraso (s)" << std::endl;

    const std::map<std::string, int>& delay_map = s1.GetDelays();

    std::vector<Cyclist> all_cyclists = c.Data();

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

    GCList gc(c);
    gc.ApplyStage(s1);

    Stage s2(1);
    s2.Simulate(c.Data());
    std::cout << "\n--- Resultados de la Etapa 2---" << std::endl;
    std::cout << "Nombre,ID,Retraso (s)" << std::endl;

    const std::map<std::string, int>& delay_map2 = s2.GetDelays();

    for (const auto& cyclist : all_cyclists) {
        std::string id = cyclist.GetCyclistId();
        
        try {
            int delay = delay_map2.at(id);
            std::cout << cyclist.GetName() << ","
                      << id << ","
                      << delay << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: El ciclista " << id << " no fue encontrado en el mapa de retrasos." << std::endl;
        }
    }
    gc.ApplyStage(s2);
    std::string classificacion= gc.GetClassification(10);
    std::cout<<classificacion;
    return 0;
}