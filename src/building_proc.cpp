#include <string>
#include "include/building.hpp"

using namespace std;


int main(int argc, char* argv[]){
    string name = argv[0];
    // string path = "./buildings/" + name + "/Gas.csv";
    building_manager building_manager_(name);
    cout << building_manager_.show_name() << endl;
    exit(EXIT_SUCCESS);
}