#ifndef __GATHER_DATA__
#define __GATHER_DATA__

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include "globals.hpp"
#include "named_pipe.hpp"
#include "log.hpp"





class gather_data{
    public:
        gather_data(std :: string dir_);
        void run();
        void make_building_processes();
        void fetch_buildings();
        // void make_bills_process();

    private:
        std :: vector <building> buildings;
        std :: string dir;
        NamedPipeServer server_pipe;
        int number_of_buildings;
};


#endif