/*Adi Megidi
314956608
adimillersoso@gmail.com
*/

#include <iostream>
using namespace std;
#include "Graph.hpp"

namespace ariel {
    

    Graph::Graph(){} 

    const std::vector <vector<int>>& Graph::getadjMatrix() const{
        return this-> adjMatrix;
    }

    //load graph
    void ariel::Graph::loadGraph (const std::vector<std::vector<int>>&matrix){
        size_t numRows = matrix.size();
        size_t numCols = matrix[0].size();
        adjMatrix = matrix;
    }

    void ariel::Graph::printGraph() const {
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix[i].size(); j++){
                cout << adjMatrix [i][j] << " "; 
            }
            cout << endl;
        }
    }

    int Graph::getNumEdge (const Graph& g){
        int edges=0;
        for (size_t i=0; i<g.adjMatrix.size(); i++){
            for (size_t j=0; j<g.adjMatrix[i].size(); j++){
                if (g.adjMatrix[i][j]!= 0)
                    edges++;
            }
        }
        return edges;
    }

    bool Graph::equalSize(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2){
        return (mat1.size() == mat2.size());
    }    

    bool Graph::equalEdges(const Graph& g1, const Graph& g2){
        if (!equalSize(g1.adjMatrix, g2.adjMatrix)){
            throw std::invalid_argument("The size of matrixs not equal");
        }
        for (size_t i=0; i<g1.adjMatrix.size(); i++){
            for (size_t j=0; j<g1.adjMatrix.size(); j++){
                if (g1.adjMatrix[i][j] != g2.adjMatrix[i][j])
                    return false;
            }
        }
        return true;
    }

    bool Graph::contain(const Graph& g1, const Graph& g2){ //check if g1 contain in g2
        if (g1.adjMatrix.size() >= g2.adjMatrix.size()){
            return false;
        }
        for (size_t i=0; i<g1.adjMatrix.size(); i++){
            for (size_t j=0; j<g1.adjMatrix.size(); j++){
                if (g1.adjMatrix[i][j] != 0 && (i >= g2.adjMatrix.size() || j >= g2.adjMatrix.size() || g2.adjMatrix[i][j] == 0)){
                    return false;
                }
            }
        }
        return true;
    }
 
    Graph Graph::operator+(const Graph& g2){
        if (!equalSize(adjMatrix, g2.adjMatrix)){
            throw std::invalid_argument("The size of matrixs not equal");
        }
        Graph g3;
        g3.adjMatrix = adjMatrix;
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix.size(); j++){
                g3.adjMatrix[i][j] = adjMatrix[i][j] + g2.adjMatrix[i][j];
            }
        }
        return g3;
    }

    void Graph::operator+=(const Graph& g2){
        if (!equalSize(adjMatrix, g2.adjMatrix)){
            throw std::invalid_argument("The size of matrixs not equal");
        }
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix.size(); j++){
                adjMatrix[i][j] = adjMatrix[i][j] + g2.adjMatrix[i][j];   
            }
        }
    }

    void Graph::operator+(){
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix.size(); j++){
                adjMatrix[i][j]=adjMatrix[i][j]*1;
            }
        }
    }

    Graph Graph::operator- (const Graph& g2){
        if (!equalSize(adjMatrix, g2.getadjMatrix())){
            throw std::invalid_argument("The size of matrixs not equal");
        }
        Graph g3;
        g3.adjMatrix = adjMatrix;
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix.size(); j++){
                g3.adjMatrix[i][j] = adjMatrix[i][j] - g2.adjMatrix[i][j];
            }
        }
        return g3;
    }

    void Graph::operator-=(const Graph& g2){
        if (!equalSize(adjMatrix, g2.adjMatrix)){
            throw std::invalid_argument("The size of matrixs not equal");
        }
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix.size(); j++){
                adjMatrix[i][j] = adjMatrix[i][j] - g2.adjMatrix[i][j];   
            }
        }
    }

    void Graph::operator-(){
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix.size(); j++){
                adjMatrix[i][j]=-adjMatrix[i][j]; 
            }
        }
    }
        
    void Graph::operator*=(int scalar){
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix.size(); j++){
                adjMatrix[i][j]=adjMatrix[i][j]*scalar;
            }
        }
    }

    void Graph::operator/= (int scalar){
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix.size(); j++){
                adjMatrix[i][j]=adjMatrix[i][j]/scalar;
            }
        }
    }

    Graph Graph::operator* (const Graph& g2){
        if (!equalSize(adjMatrix, g2.adjMatrix)){
            throw std::invalid_argument("The size of matrixs not equal");
        }
        if (adjMatrix[0].size() != g2.adjMatrix[0].size()){
            throw std::invalid_argument("The size of the columns of the matrix is ​​not equal");
        }
        Graph g3;
        g3.adjMatrix = adjMatrix;
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix.size(); j++){
                g3.adjMatrix[i][j] = adjMatrix[i][j] * g2.adjMatrix[i][j];
            }
        }
        return g3;    
    }

    bool Graph::operator< (const Graph& g2){
        if (contain (g2,*this))
            return false;
        if (getNumEdge(*this) > getNumEdge(g2))
            return false;
        if (getNumEdge(*this) == getNumEdge(g2))
            if (adjMatrix.size() > g2.adjMatrix.size())
                return false;
        return true;
    }

    bool Graph::operator> (const Graph& g2){
        if (!operator< (g2))
            return true;
        return false;
    }    

    bool Graph::operator== (const Graph& g2){
        if (equalSize(adjMatrix,g2.adjMatrix) && equalEdges(*this,g2) || !operator<(g2) && !operator<(*this))
            return true;
        return false;
    }

    bool Graph::operator<= (const Graph& g2){
        if (operator<(g2) || operator==(g2))
            return true;
        return false;
    }

    bool Graph::operator>= (const Graph& g2){
        if (operator>(g2) || operator==(g2))
            return true;
        return false;
    }

    bool Graph::operator!= (const Graph& g2){
        if (!operator==(g2))
            return true;
        return false;
    }

    void Graph::operator++ (){
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix[i].size(); j++){
                if (adjMatrix[i][j] != 0)
                    adjMatrix[i][j] = adjMatrix[i][j]+1;
            }
        }
    }

    void Graph::operator-- (){
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix[i].size(); j++){
                if (adjMatrix[i][j] != 0)
                    adjMatrix[i][j] = adjMatrix[i][j]-1;
            }
        }
    }

    ostream& operator<<(ostream& os,const Graph& g){
        for (size_t i=0; i<g.adjMatrix.size(); i++){
            os << "[";
            for (size_t j=0; j<g.adjMatrix[0].size(); j++){
                os << g.adjMatrix[i][j];
                if (j != g.adjMatrix[0].size()-1){
                    os << ", ";
                }
            }
            os << "]";
            if (i != g.adjMatrix.size()-1){
                os << ", ";
            }
            os << endl;
        }
        os << endl;
        return os;
    }

};