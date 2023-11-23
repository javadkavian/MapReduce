#ifndef __GLOBAL__
#define __GLOBAL__



typedef struct building{
    std :: string name;
}building;


const int INIT_ARG_CNT = 2;
const int READ_END = 0;
const int WRITE_END = 1;
const std :: string ADDR_UNAVAILABLE = "address not provided";
const std :: string MAIN_SERVER = "main_server_name";
const std :: string FETCHING_BUILD = "fetching buildings...";
const std :: string DIR_DOESNT_EXIST = "directory doesn't exist!";
const std :: string UN_PIPE_FAILED = "failed to create unnamed pipe";
const std :: string BUILDING_FAILED = "building failed to gather information";
const std :: string FORK_FAILED = "failed to fork!";
const char BUILDING_CHILD [] = "./building";

#endif