#include "include/building.hpp"


using namespace std;

building_manager :: building_manager(string name_){
    name = name_;
}


void building_manager :: configure_resource_addresses(){
    water_address = "./buildings/" + name + "Water/.csv";
    gas_address = "./buildings/" + name + "/Gas.csv";
    elec_address = "./buildings/" + name + "/Electricity.csv";
}


void building_manager :: get_water_attributes(){
    int water_pipe_fds[2];
    if(pipe(water_pipe_fds) == -1){
        throw runtime_error(UN_PIPE_FAILED);
    }
    int pid = fork();
    if(pid > 0){
        close(water_pipe_fds[WRITE_END]);
        int return_status;
        logInfo(("water attributes of " + name + " is being collected...").c_str());
        wait(&return_status);
        if(return_status == FAILURE){
            throw runtime_error(name + WATER_FAILED);
        }
        char tmp[1024];
        memset(tmp, 0, 1024);
        read(water_pipe_fds[READ_END], tmp, 1024);
        

    }
    else if(pid == 0){
        close(STDOUT_FILENO);
        dup2(water_pipe_fds[WRITE_END], STDOUT_FILENO);
        close(water_pipe_fds[WRITE_END]);
        close(water_pipe_fds[READ_END]);
        execl(WATER_PROC_ADDR.c_str(), "reza", nullptr);
    }
    else{
        throw runtime_error(FORK_FAILED);
    }
}


void building_manager :: run(){
    configure_resource_addresses();
    get_water_attributes();
}