/* Change "int* matrix" to "bool* matrix and remove
 * "MatrixGraph::AdjacencyMatrix::weight" and "int _weight" from
 * "addEdge()" (and probably some other places) and set values to
 * "true". Some algorithm will needed to be adjusted to.
 * Alternatively, set fields just to 0 or 1
 *
 * Adjust the addEdge() function to make graph undirected. Remove
 * bool from parameters and the if-statement and make it fill in
 * always in both direction
 */

/* Inspired and with help from:
 * Prof. Dr. Peter Altenbernd
 * StackOverflow
 * GeeksforGeeks
 */

#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Graph.h"

class MatrixGraph : Graph {
    struct AdjacencyMatrix;
    AdjacencyMatrix* matrix;

    void depthFirstSearch(int _v, bool* _visited);
    void breadthFirstSearch(int _v, bool* _visited);

    int minDistance(int _dist[], bool _visited[]);
    void printDijkstraSolution(int _dist[]);

    bool isCyclic(int _v, bool _visited[], bool _onceVisited[]);
    void topologicalSort(int _v, bool _visited[], std::stack<int>& _stack);

public:
    MatrixGraph(int _v);
    ~MatrixGraph();

    bool empty();
    void addEdge(int _src, int _dest, int _weight, bool _directed = true);
    void print();

    bool depthFirstSearch(int _start);
    bool breadthFirstSearch(int _start);

    bool isCyclic();
    void dijkstra(int _start);
    void topologicalSort();
};

#endif // MATRIXGRAPH_H
