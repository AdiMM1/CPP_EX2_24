/*Adi Megidi
314956608
adimillersoso@gmail.com
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;
namespace ariel{

    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;


    public:

    //construcor
    Graph();

    const vector <vector<int>>& getadjMatrix() const;
    void loadGraph (const vector<vector<int>>&matrix);
    void printGraph() const;
    bool isDirected (const Graph& g);
    static int getNumEdge (const Graph& g);
    static bool equalSize(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2); 
    bool contain(const Graph& g1, const Graph& g2);
    bool equalEdges(const Graph& g1, const Graph& g2);
    Graph operator+(const Graph& g2);
    void operator+=(const Graph& g2); 
    void operator+(); 
    Graph operator- (const Graph& g2);
    void operator-=(const Graph& g2); 
    void operator-(); 
    bool operator< (const Graph& g2); 
    bool operator> (const Graph& g2);
    bool operator== (const Graph& g2); 
    bool operator<= (const Graph& g2);
    bool operator>= (const Graph& g2);
    bool operator!= (const Graph& g2);
    void operator++ ();
    void operator-- ();
    Graph operator*(const Graph& g2);
    void operator*=(int scalar); 
    void operator/= (int scalar); 
    friend ostream& operator<<(ostream& os,const Graph& g);





   };
};
#endif