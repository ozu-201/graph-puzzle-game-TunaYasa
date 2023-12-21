//
// Created by ty021731 on 12/21/2023.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string line;

    ifstream myfile("C:\\Users\\TEMP\\CLionProjects\\graph-puzzle-game-TunaYasa\\src\\turkish-dictionary.txt");

    while(getline(myfile, line)){
        myfile >> line;
        if(line.length() == 3 || line.length() == 4 || line.length() == 5){
            cout << line + "\n";
        }
    }
    myfile.close();

    string line2;

    ifstream myfile2("C:\\Users\\TEMP\\CLionProjects\\graph-puzzle-game-TunaYasa\\src\\english-dictionary.txt");

    while(getline(myfile2, line2)){
        myfile2 >> line2;
        if(line2.length() == 3 || line2.length() == 4 || line2.length() == 5){
            cout << line2 + "\n";
        }
    }
    myfile2.close();
}