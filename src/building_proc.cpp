#include <string>
#include "include/building.hpp"

using namespace std;


int main(int argc, char* argv[]){
    building_manager building_manager_(argv[0]);
    try
    {
        building_manager_.run();
        cout << building_manager_.abbas << endl;
    }
    catch(const std::exception& e)
    {
        logError(e.what());
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}