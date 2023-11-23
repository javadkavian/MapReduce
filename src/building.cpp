#include "include/building.hpp"


using namespace std;

building_manager :: building_manager(string name_){
    name = name_;
}


string building_manager :: show_name(){
    return name;
}