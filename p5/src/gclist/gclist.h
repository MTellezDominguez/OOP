#ifndef GCLIST_H
#define GCLIST_H

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

struct GCEntry{
    Cyclist *c;
    int total_delay;
};

class GCList{
    private:
        std::list<GCEntry> gc_;
    public:
        GCList(CyclistCatalog &c);
        void ApplyStage(Stage s);
        int Size();
        std::string GetClassification(int n);
        const std::list<GCEntry>& GetClassification() const;
};

#endif