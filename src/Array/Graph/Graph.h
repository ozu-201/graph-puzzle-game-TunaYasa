//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include "../../General/AbstractGraph.h"
#include "../../List/Graph/Edge.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

namespace array{
    class Graph : public AbstractGraph{
    private:
        int** edges;
        int index;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void readAndNumberWords(const std::string & filePath, int wordLength);
        std::vector<std::string> words;
        std::vector<int> nums;
        bool isOneLetterDifference(const std::string word1, const std::string word2);
        void shortestPath(std::string startString, std::string endString);
    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode) override;
    };

}


#endif //DATASTRUCTURES_CPP_GRAPH_H
