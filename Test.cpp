/*Adi Megidi
314956608
adimillersoso@gmail.com
*/

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test operator+ && +=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    CHECK(Algorithms::isConnected(g1) == true);
    CHECK(Algorithms::shortestPath(g1, 0, 2) == "0->1->2");
    CHECK(Algorithms::isContainsCycle(g1) == "0");
    CHECK(Algorithms::negativeCycle(g1) == 0);
    CHECK(Algorithms::isBipartite(g1) == "The graph is bipartite: A={0,2}, B={1}");

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    ariel::Graph result;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    result.loadGraph(expectedGraph);
    CHECK(g3 == result); 
    g1 += g2;
    CHECK (g1 == result); //test operator +=
    CHECK(Algorithms::isConnected(g3) == true);
    CHECK(Algorithms::shortestPath(g3, 0, 2) == "0->2");
    CHECK(Algorithms::isContainsCycle(g3) == "The cycle is: 0->1->2->0");
    CHECK(Algorithms::negativeCycle(g3) == 0);
    CHECK(Algorithms::isBipartite(g3) == "0");

}
TEST_CASE ("Test +()unary")
{
    ariel::Graph g1,g2,g3;
    g1.loadGraph({
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}});
    g2.loadGraph({
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}});
    g3.loadGraph({
        {1, 1, 2},
        {3, 4, 5},
        {6, 7, 8}});
    g1.operator+();
    CHECK (g1 == g2);
    g2.operator+();
    CHECK (g2 != g3);
}

TEST_CASE("Test operator- && -=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g2 - g1;
    ariel::Graph result;
    vector<vector<int>> expectedGraph = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 0}};
    result.loadGraph(expectedGraph);
    CHECK(g3 == result); 
    g2 -= g1;
    CHECK (g2 == result); //test operator -=
}

TEST_CASE ("Test -()unary")
{
    ariel::Graph g1,g2,g3;
    g1.loadGraph({
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}});
    g2.loadGraph({
        {0, -1, -2},
        {-3, -4, -5},
        {-6, -7, -8}});
    g3.loadGraph({
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}});
    g1.operator-();
    CHECK (g1 == g2);
    g2.operator-();
    CHECK (g2 == g3);
}

TEST_CASE("Test operator* & *=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph multi = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 2},
        {0, 2, 0}};
    ariel::Graph g4;
    g4.loadGraph(expectedGraph);
    CHECK (multi == g4);
    g1.operator*=(6);
    vector<vector<int>> graph2 = {
        {0, 6, 0},
        {6, 0, 6},
        {0, 6, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph2);
    CHECK (g1 == g5); 
}

TEST_CASE ("Test operator ++ & --")
{
    ariel::Graph g1,g2,g3;
    g1.loadGraph({
        {0, 1, 0},
        {3, 2, 5},
        {0, 0, 8}});
    g2.loadGraph({
        {0, 2, 0},
        {4, 3, 6},
        {0, 0, 9}});
    g3.loadGraph({
        {0, 1, 0},
        {3, 2, 5},
        {0, 0, 8}});
    g1.operator++();
    CHECK (g1 == g2);
    g2.operator--();
    CHECK (g2 == g3);
}

TEST_CASE ("Test operator /=")
{
    ariel::Graph g1,g2;
    g1.loadGraph({
        {4, 2, 0},
        {1, 2, 8},
        {0, 0, 6}});
    g2.loadGraph({
        {2, 1, 0},
        {0, 1, 4},
        {0, 0, 3}});
    g1.operator/=(2);
    CHECK (g1 == g2);
}

TEST_CASE ("get number egdes")
{
    ariel::Graph g1;
    g1.loadGraph({
    {0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0}});
    int edges = ariel::Graph::getNumEdge(g1); 
    CHECK (edges == 10);
    ariel::Graph g2,g3;
    g2.loadGraph({
        {4, 2, 0},
        {1, 2, 8},
        {0, 0, 6}});
    g3.loadGraph({
        {2, 1, 0},
        {0, 1, 4},
        {1, 0, 3}});
    CHECK(ariel::Graph::getNumEdge(g2)==ariel::Graph::getNumEdge(g3));
}

TEST_CASE ("equal size graph")
{
    ariel::Graph g1,g2,g3;
    vector<vector<int>> graph1 = {
    {0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0}}; 
    vector<vector<int>> graph2 = {
        {4, 2, 0},
        {1, 2, 8},
        {0, 0, 6}};
    vector<vector<int>> graph3 = {
        {2, 1, 0},
        {0, 1, 4},
        {1, 0, 3}};
    CHECK(ariel::Graph::equalSize(graph1,graph2) == false);
    CHECK(ariel::Graph::equalSize(graph2,graph3) == true);
}

TEST_CASE ("Test operator <")
{
    ariel::Graph g1,g2,g3,g4,g5;
    g1.loadGraph({
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}});
    g2.loadGraph({
        {0, 2, 0},
        {1, 2, 0},
        {0, 0, 6}});
    g3.loadGraph({
        {2, 1, 0, 0},
        {0, 1, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}});
    g4.loadGraph({
        {0, 5},
        {0, 0}});
    g5.loadGraph({
        {0, 0, 5},
        {1, 0, 0},
        {3, 1, 0}});
    CHECK(g1.operator<(g2));
    CHECK(g2.operator<(g3));
    CHECK(g4.operator<(g5));
}

TEST_CASE ("Test operator >")
{
    ariel::Graph g1,g2,g3,g4,g5;
    g1.loadGraph({
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}});
    g2.loadGraph({
        {0, 2, 0},
        {1, 2, 0},
        {0, 0, 6}});
    g3.loadGraph({
        {2, 1, 0, 0},
        {0, 1, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}});
    g4.loadGraph({
        {0, 5},
        {0, 0}});
    g5.loadGraph({
        {0, 0, 5},
        {1, 0, 0},
        {3, 1, 0}});
    CHECK(g2.operator>(g1));
    CHECK(g3.operator>(g2));
    CHECK(g5.operator>(g4));
}

TEST_CASE ("Test operator == && !=")
{
    ariel::Graph g1,g2,g3;
    g1.loadGraph({
        {0, 2, 0},
        {1, 2, 0},
        {0, 0, 6}});
    g2.loadGraph({
        {0, 2, 0},
        {1, 2, 0},
        {0, 0, 6}});
    g3.loadGraph({
        {1, 2, 3},
        {1, 2, 0},
        {0, 5, 6}});
    CHECK(g1.operator==(g2));
    CHECK(g2.operator!=(g3));
}

TEST_CASE ("Test operator <=")
{
    ariel::Graph g1,g2,g3;
    g1.loadGraph({
        {0, 2, 0},
        {1, 2, 0},
        {0, 0, 6}});
    g2.loadGraph({
        {0, 2, 0},
        {1, 2, 0},
        {0, 0, 6}});
    g3.loadGraph({
        {2, 1, 0, 0},
        {0, 1, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}});
    CHECK(g1.operator<=(g2));
    CHECK(g2.operator<=(g3));
}

TEST_CASE ("Test operator >=")
{
    ariel::Graph g1,g2,g3;
    g1.loadGraph({
        {0, 2, 0},
        {1, 2, 0},
        {0, 0, 6}});
    g2.loadGraph({
        {0, 2, 0},
        {1, 2, 0},
        {0, 0, 6}});
    g3.loadGraph({
        {2, 1, 0, 0},
        {0, 1, 4, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}});
    CHECK(g2.operator>=(g1));
    CHECK(g3.operator>=(g2));
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}