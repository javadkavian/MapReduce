#include "include/gather_data.hpp"
#include <dirent.h>
using namespace std;


gather_data :: gather_data(string dir_):server_pipe(MAIN_SERVER){
    dir = dir_;
}

void gather_data :: run(){
    // make_bills_process();
    make_building_processes();
}

void gather_data :: make_building_processes() {
    fetch_buildings();
    for(auto building : buildings){
        int pipe_fds[2];
        if(pipe(pipe_fds) == -1){
            throw runtime_error(UN_PIPE_FAILED);
        }
        int pid = fork();
        if(pid > 0){
            close(pipe_fds[WRITE_END]);
            int return_status;
            logInfo(("waiting for " + building.name + " to gather information...").c_str());
            wait(&return_status);
            if(return_status == FAILURE){
                throw runtime_error(building.name + BUILDING_FAILED);
            }
            logInfo((building.name + " finished information gathering").c_str());
            char tmp[1024];
            memset(tmp, 0, 1024);
            read(pipe_fds[READ_END], tmp, 1024);
            printf("%s", tmp);
        }
        else if(pid == 0){
            close(STDOUT_FILENO);
            dup2(pipe_fds[WRITE_END], STDOUT_FILENO);
            close(pipe_fds[WRITE_END]);
            close(pipe_fds[READ_END]);
            execl(BUILD_PROC_ADDR.c_str(), building.name.c_str(),nullptr);
        }
        else{
            throw runtime_error(FORK_FAILED);
        }
    }
}


void gather_data :: fetch_buildings() {
    logInfo(FETCHING_BUILD.c_str());
    DIR* dir_;
    struct dirent* ent;
    if((dir_ = opendir(dir.c_str())) == NULL){
        throw runtime_error(DIR_DOESNT_EXIST);
    }
    vector <string> building_names;
    while((ent = readdir(dir_)) != NULL){
        building_names.push_back(string(ent->d_name));
    }
    building_names.erase(find(building_names.begin(), building_names.end(), "."));
    building_names.erase(find(building_names.begin(), building_names.end(), ".."));
    building_names.erase(find(building_names.begin(), building_names.end(), "bills.csv"));
    building_names.erase(find(building_names.begin(), building_names.end(), ".DS_Store"));

    for(auto name : building_names){
        building new_building;
        new_building.name = name;
        buildings.push_back(new_building);
    }
    number_of_buildings = buildings.size();
    logInfo(("There exists " + to_string(number_of_buildings) + " building in this company").c_str());
    closedir(dir_);
}