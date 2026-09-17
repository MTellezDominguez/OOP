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

GCList::GCList(CyclistCatalog &c){
    int s=c.Size();
    for(int i=0; i<s; i++){
        struct GCEntry aux;
        aux.c=&c.Data()[i];
        aux.total_delay=0;
        gc_.push_back(aux);
    }
}

void GCList::ApplyStage(Stage s){
    std::map<std::string, int> delays=s.GetDelays();
    for(GCEntry &aux : gc_){
        auto it = delays.find((aux.c)->GetCyclistId());
        if(it != delays.end()){
            aux.total_delay += it->second;
        }
    }

    gc_.sort([](const GCEntry& a, const GCEntry& b){
        if (a.total_delay != b.total_delay) {
            return a.total_delay < b.total_delay;
        }
        return a.c->GetCyclistId() < b.c->GetCyclistId();
    });
}

int GCList::Size(){
    int cont=0;
    for(GCEntry &aux : gc_){
        cont++;
    }
    return cont;
}

const std::list<GCEntry>& GCList::GetClassification() const {
    return gc_;
}

std::string GCList::GetClassification(int n){
    std::string classification="";
    int cont=1;
    for(GCEntry &aux : gc_){
        if(cont == n) break;
        classification+=std::to_string(cont) + "." + aux.c->GetName() + "," + aux.c->GetCyclistId() + std::to_string(aux.total_delay) + "\n";
        cont++;
    }
    return classification;
}

void GCList::NormalizeDelays(){
    if (gc_.empty()) {
    return;
    }
    auto first_delay=gc_.front().total_delay;
    for(GCEntry &aux : gc_){
        aux.total_delay=aux.total_delay-first_delay;
    }
}