#ifndef __GLOBAL__
#define __GLOBAL__

#include <map>
#include <string>

typedef struct building{
    std :: string name;
}building;

typedef struct resource{
    std :: map <int, int> average_mothly_usuage;
    std :: map <int, int> usuage_in_peak_our;
    std :: map <int, int> total_monthly_usuage;
    std :: map <int, int> peak_our;
    std :: map <int, int> peack_mean_diffrence;
}resource;

const int INIT_ARG_CNT = 2;
const int READ_END = 0;
const int WRITE_END = 1;
const int FAILURE = 256;
const std :: string ADDR_UNAVAILABLE = "address not provided";
const std :: string MAIN_SERVER = "main_server_name";
const std :: string FETCHING_BUILD = "fetching buildings...";
const std :: string DIR_DOESNT_EXIST = "directory doesn't exist!";
const std :: string UN_PIPE_FAILED = "failed to create unnamed pipe";
const std :: string BUILDING_FAILED = " failed to gather information";
const std :: string FORK_FAILED = "failed to fork!";
const std :: string BUILD_PROC_ADDR = "./building_proc";
const std :: string WATER_PROC_ADDR = "./water";
const std :: string WATER_FAILED = " failed to gather water attributes";

#endif