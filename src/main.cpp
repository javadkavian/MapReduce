#include <iostream>
#include "include/log.hpp"
#include "include/globals.hpp"
#include "include/gather_data.hpp"
using namespace std;



int main(int argc, char const* argv[]){
    if(argc < INIT_ARG_CNT){
        logError(ADDR_UNAVAILABLE.c_str());
        exit(EXIT_FAILURE);
    }
    string buildings_dir = argv[INIT_ARG_CNT - 1];
    gather_data gather_data_(buildings_dir);
    try
    {
        gather_data_.run();
    }
    catch(const std::exception& e)
    {
        logError(e.what());
        exit(EXIT_FAILURE);
    }
    
    
    exit(EXIT_SUCCESS);
}