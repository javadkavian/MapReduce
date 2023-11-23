#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "include/globals.hpp"
using namespace std;

vector <vector<int>> initial_parser(string addr){
    vector <vector<int>> parsed_csv;
    ifstream file(addr);
    string line;
    getline(file, line);
    while(getline(file, line)) {
        istringstream iss(line);
        string token;
        vector <int> current_line;
        while(getline(iss, token, CSV_DELIM)) {
            current_line.push_back(atoi(token.c_str()));
        }
        parsed_csv.push_back(current_line);
    }
    return parsed_csv;
}

map <int, pair<int, int>> seperate_by_month(vector <vector<int>> parsed_csv){
    map <int, pair<int, int>> indexes;
    int current_month = parsed_csv[0][MONTH_INDEX];
    int begin = 0;
    int end;
    for(int i = 1 ; i < parsed_csv.size() ; i++){
        if(parsed_csv[i][MONTH_INDEX] != current_month){
            end = i - 1;
            pair<int, int> new_month(begin, end);
            indexes[current_month] = new_month;
            current_month = parsed_csv[i][MONTH_INDEX];
            begin = i;
        }
    }
    return indexes;

}

int main(int argc, char* argv[]) {
    vector <vector<int>> parsed_csv = initial_parser(argv[0]);
    map <int, pair<int, int>> indexes = seperate_by_month(parsed_csv);
    // map<int, pair<int, int>> :: iterator it = indexes.begin();
    // while(it!=indexes.end()){
    //     cout << it -> first << ">>" << it->second.first << ":" << it -> second.second << endl;
    //     ++it;
    // }
    return 0;
}