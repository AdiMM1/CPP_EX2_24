/*Adi Megidi
314956608
adimillersoso@gmail.com
*/

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include "Graph.hpp"

using namespace std;
namespace ariel{
    class Algorithms {

    static vector<vector<int>> adjMatrix;
    static vector<int> dist;

    public:
    static bool isConnected(const Graph& graph);
    
    static std::string shortestPath(const Graph& graph, size_t start, size_t end);
    
    static bool DFS (const Graph& graph, size_t node, vector<bool>&visited, vector<size_t>&parent, string& cycle); 
    
    static std::string isContainsCycle (const Graph& graph);
    
    static bool find_Bipartite (const Graph& graph, vector <bool>& visited, vector <int>& color, size_t node, size_t col);
    
    static std::string isBipartite(const Graph& graph);
    
    static bool negativeCycle(const Graph& graph);
    
    static void BFS (const Graph& graph, size_t s, vector <bool>& visited);
    
    static bool bellmanFord (const Graph& graph, size_t source);
    };
};
    

#endif