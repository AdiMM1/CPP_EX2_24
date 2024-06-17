/*Adi Megidi
314956608
adimillersoso@gmail.com
*/

#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <limits>
#include <vector>
#include <stack>

using namespace std;

namespace ariel{

vector<vector<int>> Algorithms::adjMatrix;
vector <int> Algorithms::dist;

void Algorithms::BFS (const Graph& graph, size_t scr, vector <bool>& visited){  
    adjMatrix = graph.getadjMatrix();
    visited = vector<bool>(adjMatrix.size(), 0);
    queue <size_t> queue;
    visited [scr] = true;
    queue.push (scr);
    while (!queue.empty()){
        size_t current = queue.front();
        queue.pop();
        for (size_t i=0; i<adjMatrix.size(); i++){
            if (adjMatrix[(current)][i] >= 1 && !visited[i]){
                queue.push(i);
                visited[i] = true;
            }
        }
    } 
}

bool Algorithms::isConnected (const Graph& graph){
    adjMatrix = graph.getadjMatrix();
    size_t size = adjMatrix.size();
    vector<bool> visited (size, false);
    Algorithms::BFS (graph,0,visited);
    for(size_t i=0; i<size; i++){
        if (!visited[i]){
             return false;
        }
    }
    return true;
}

bool Algorithms::bellmanFord (const Graph& graph, size_t source){
    adjMatrix = graph.getadjMatrix();
    size_t size = adjMatrix.size();
    dist = vector<int>(size, numeric_limits<int>::max());
    dist [source] = 0;
    for (size_t i=0; i<size-1; i++){
        for (size_t u=0; u<size; u++){
            for (size_t v=0; v<size; v++){
                if (adjMatrix[u][v] != 0 && dist[u] != numeric_limits<int>::max() && dist[u] + adjMatrix[u][v] < dist[v]){
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }
    }
    for (size_t i=0; i<size; i++){
        for (size_t j=0; j<size; j++){
            if (adjMatrix[i][j] != 0 && dist[i] != numeric_limits<int>::max() && dist[i] + adjMatrix[i][j] < dist[j]){
                return true;
            }
        }
    }
    return false;
}

string Algorithms::shortestPath(const Graph& graph, size_t start, size_t end){
    adjMatrix = graph.getadjMatrix();
    if (Algorithms::bellmanFord(graph, start)){
        return "This graph contains negative-cycle";
    }
    if (dist[end] == numeric_limits<int>::max()){
        return "-1";
    }
    string path = to_string(end);
    while (end != start){
        for (size_t i=0; i<adjMatrix.size(); i++){
            if (adjMatrix[i][end] != 0 && dist [end] == dist[i] + adjMatrix[i][end]){
                path = to_string(i)+  "->" + path;
                end = i;
                break;
            }
        }
    }
    return path;
    }

    bool Algorithms::negativeCycle(const Graph& graph){
        vector <int> dist;
        return bellmanFord (graph, 0);
    }

bool Algorithms::DFS (const Graph& graph, size_t node, vector<bool>&visited, vector<size_t>&parent, string& cycle){
    adjMatrix = graph.getadjMatrix();
    visited[node]=true;
    for (size_t i=0; i<adjMatrix.size(); i++){
        if (adjMatrix[node][i]){
            if (visited[i]){
                if (i != parent[node]){
                    size_t cur=node;
                    cycle=to_string(i);
                    while (cur!=i){
                        cycle=to_string(cur)+"->"+cycle;
                        cur=parent[cur];
                    }
                    cycle=to_string(i)+"->"+cycle;
                    return true;
                }
            }
            else {
                parent[i]=node;
                if(DFS(graph,i,visited,parent,cycle)){
                    return true;
                }
            }
        }
    }    
    return false;
}

string Algorithms::isContainsCycle (const Graph& graph){
    adjMatrix = graph.getadjMatrix();
    vector<bool>visited(adjMatrix.size(), false);
    vector<size_t>parent(adjMatrix.size(),numeric_limits<size_t>::max());
    string cycle;
    for (size_t i=0; i<adjMatrix.size(); i++){
        if (!visited[i]&&DFS(graph, i, visited, parent, cycle)){
            return "The cycle is: " + cycle;
        }
    }    
    return "0";
}

bool Algorithms::find_Bipartite (const Graph& graph, vector <bool>& visited, vector <int>& color, size_t node, size_t col){
    adjMatrix = graph.getadjMatrix();
    visited[node]=true;
    color[node]=col;
    for(size_t i=0; i<adjMatrix.size(); i++){
        if (adjMatrix[node][i] && !visited[i]){
            if (!find_Bipartite(graph, visited, color, i, 1-col)){
                return false;
            }
        }
        else if(adjMatrix[node][i] && color[i] == color[node]){
            return false;
        }
    }
    return true;
} 

string Algorithms::isBipartite(const Graph& graph){
    adjMatrix = graph.getadjMatrix();
    size_t size = adjMatrix.size();
    vector<bool>visited (size, false);
    vector<int>color(size, -1);
    vector<vector<int>>bipartition(2);
    for (size_t i = 0; i < size; i++) {
        if (!visited[i]) {
            if (!find_Bipartite(graph, visited, color, i, 0)) {
                return "0";
            }
        }
    }
    string result = "The graph is bipartite: A={";
        for (size_t i=0; i<color.size(); i++){
            if (color[i]==0){
                result = result + to_string(i) + ",";
            }
        }
        result.pop_back();
        result = result + "}, B={";
        for (size_t i=0; i<color.size(); i++){
            if (color[i]==1){
                result = result + to_string(i) + ",";
            }
        }
        result.pop_back();
        result = result + "}";
        return result;
    }
}        

    



















