#ifndef __BUILDING__
#define __BUILDING__
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "globals.hpp"
#include "log.hpp"


class building_manager {
    public:
        building_manager(std :: string name_);
        std :: string show_name();
    private:
        std :: string name;
        std :: map <std :: string, resource> resource_report;
};

#endif