//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include "Graph.h"
#include "../DisjointSet.h"
#include "../Queue.h"
#include "../Heap/Heap.h"
#include "../Heap/MinHeap.h"
#include <vector>

namespace array{


    Graph::Graph(int vertexCount) : AbstractGraph(vertexCount){
        edges = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            edges[i] = new int[vertexCount];
        }
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                edges[i][j] = 0;
            }
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < vertexCount; i++){
            delete[] edges[i];
        }
        delete[] edges;
    }

    void Graph::addEdge(int from, int to) {
        edges[from][to] = 1;
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        for (int toNode = 0; toNode < vertexCount; toNode++){
            if (edges[fromNode][toNode] > 0){
                if (!visited[toNode]){
                    visited[toNode] = true;
                    depthFirstSearch(visited, toNode);
                }
            }
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        int fromNode;
        Queue queue = Queue(100);
        queue.enqueue( Element(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]){
                        visited[toNode] = true;
                        queue.enqueue( Element(toNode));
                    }
                }
            }
        }
    }

    void Graph::readAndNumberWords(const std::string & filePath, int wordLength){


        std::ifstream file(filePath);
        if(!file.is_open()){
            std::cerr << "Error: Unable to open file" << std::endl;
        }
        std::string line;
        int wordCount = 0;
        index = 0;

        while (std::getline(file,line)){
            std::istringstream iss(line);
            std::string word;
            while (iss >> word){
                word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
                if(word.length() == static_cast<size_t>(wordLength)){
                    nums.push_back(index);
                    words.push_back(word);
                    std::cout <<nums[index] << " " << words[index] << " " << word << "\n";
                    wordCount++;
                    index++;
                }
            }
        }
        for(int i= 0; i<words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if(isOneLetterDifference(words[i],words[j])) {
                    std::cout << "Connection " << words[i] << " -> " << words[j] << "\n";
                    std:: cout << "Connection " << nums[i] << " -> " <<nums[j] << "\n";
                    addEdge(nums[i], nums[j]);
                    addEdge(nums[j],nums[i]);
                }
            }
        }
        file.close();
    }



    bool Graph::isOneLetterDifference(const std::string word1, const std::string word2) {
        bool x = false;
        int letterDiff = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i]!=word2[i]) {
                letterDiff++;
            }
        }
        if(letterDiff == 1){
            x = true;
        }
        return x;
    }
   void Graph::shortestPath(std::string startString, std::string endString) {
            int str;
            int dest;
            for(int i = 0; i<words.size(); i++){
                if(words[i]==startString){
                    str = nums[i];
                }
                if(words[i]==endString){
                    dest = nums[i];
                }
            }
        std::vector<bool> visitedPlace(vertexCount, false);
        std::vector<int> parentPlace(vertexCount, -1);
        Queue queue(vertexCount);

      visitedPlace[str] = true;
        queue.enqueue(Element(str));

        while (!queue.isEmpty()) {
            Element currentElement = queue.dequeue();
            int currentNode = currentElement.getData();

            if (currentNode == dest) {
                break;
            }

            for (int nextNode = 0; nextNode < vertexCount; nextNode++) {
                if (edges[currentNode][nextNode] > 0 && !visitedPlace[nextNode]) {
                    visitedPlace[nextNode] = true;
                    parentPlace[nextNode] = currentNode;
                    queue.enqueue(Element(nextNode));
                }
            }
        }

        if (parentPlace[dest] == -1) {
            std::cout << "No shortest path exists from " << str << " to " << dest << std::endl;
            return;
        }

        std::vector<int> shortestPath;
        for (int at = dest; at != -1; at = parentPlace[at]) {
            shortestPath.push_back(at);
        }
        reverse(shortestPath.begin(), shortestPath.end());

        std::cout << "Shortest from " << startString << " to " << endString << " is: ";
        for (size_t i = 0; i < shortestPath.size(); i++) {
            std::string word = words[shortestPath[i]];
            std::cout << word << (i < shortestPath.size() - 1 ? " -> " : "\n");
        }
    }


}
