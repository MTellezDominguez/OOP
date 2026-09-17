#ifndef STAGE_H
#define STAGE_H

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits.h>
#include "persons.h"
#include "catalog.h"

class Stage{
    private:
        std::map<std::string, int> delay_;
        int hard_;
    public:
        void Simulate(const std::vector<Cyclist>& cyclists);
        Stage(int hard);
        std::map<std::string, int> GetDelays(){return delay_;}
        int GetHard(){return hard_;}
};



#endif