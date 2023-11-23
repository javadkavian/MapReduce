#ifndef __BUILDING__
#define __BUILDING__
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <sys/wait.h>
#include "globals.hpp"
#include "log.hpp"


class building_manager {
    public:
        building_manager(std :: string name_);
        void configure_resource_addresses();
        void run();
        void get_water_attributes();
    private:
        std :: string name;
        std :: map <std :: string, resource> resource_report;
        std :: string water_address;
        std :: string gas_address;
        std :: string elec_address;
        std :: string water_attributes;
        std :: string gas_attributes;
        std :: string elec_attributes;
};

#endif