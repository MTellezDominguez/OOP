#include <map>
#include <random>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits.h>
#include "persons.h"
#include "catalog.h"
#include "stage.h"

void Stage::Simulate(const std::vector<Cyclist>& cyclists) {
    

    if (cyclists.size() == 0) {
        std::cerr << "Error: No se puede simular con un vector vacío." << std::endl;
        return;
    }


    std::random_device rd;
    std::mt19937 gen(rd());


    int tam = cyclists.size() - 1; 
    std::uniform_int_distribution<int> winner_dist(0, tam);
    int random_index = winner_dist(gen);


    std::string winner_id = cyclists[random_index].GetCyclistId();
    delay_[winner_id] = 0;


    std::uniform_int_distribution<int> delay_dist(1, 400 * hard_);


    for (int i = 0; i < cyclists.size(); i++) {
        

        std::string current_id = cyclists[i].GetCyclistId();


        if (current_id != winner_id) {
            int random_delay = delay_dist(gen);
            
            delay_[current_id] = random_delay;
        }
    }

    return;
}

Stage::Stage(int hard){
    if(hard<=1){
        hard_=1;
    }else if(hard>=5){
        hard_=5;
    }else{
        hard_=hard;
    }
}

