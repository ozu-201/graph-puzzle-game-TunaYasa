#include "Array/Graph/Graph.h"
#include <windows.h>
#include <iostream>
using namespace array;

int main(){
    Graph g = Graph(2500);

    // For english dictionary
    std::string filePath = "C:\\Users\\TEMP\\CLionProjects\\graph-puzzle-game-TunaYasa\\english-dictionary.txt";
    g.readAndNumberWords(filePath, 3);
    g.shortestPath("aba","bar");

    // For turkish dictionary
    std::string filePath2 = "C:\\Users\\TEMP\\CLionProjects\\graph-puzzle-game-TunaYasa\\turkish-dictionary.txt";
    g.readAndNumberWords(filePath2, 3);
    g.shortestPath("aba","bar");

    SetConsoleOutputCP(65001); // to make turkish dictionary

}