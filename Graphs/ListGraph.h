/* Remove "ListGraph::AdjacencyList::weight" and "int _weight"
 * from "addEdge()" (and probably some other places) to convert
 * to unweighted graph. Alternatively, set fields just to 0 or 1.
 *
 * Adjust the addEdge() function to make graph undirected. Remove
 * bool from parameters and the if-statement and make it fill in
 * always in both direction
 */

/* Inspired and with help from:
 * Prof. Dr. Peter Altenbernd
 * GeeksforGeeks
 * Karthikeya Boyini
 * programiz.com
 */

#ifndef LISTGRAPH_H
#define LISTGRAPH_H
#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include "Graph.h"

class ListGraph : Graph {
    int size;

    struct AdjacencyList;
    AdjacencyList* lists;

    void depthFirstSearch(int _v, bool* _visited);
    void breadthFirstSearch(int _v, bool* _visited);

    bool isCyclic(int _v, bool _visited[], bool _stack[]);
    void printDijkstraSolution(int _dist[]);
    void topologicalSort(int _v, bool _visited[], std::stack<int>& _stack);

public:
    ListGraph (int _v);
    ~ListGraph();

    bool empty();
    void addEdge(int _src, int _dest, int _weight, bool _directed = true);
    void print();

    bool depthFirstSearch(int _start);
    bool breadthFirstSearch(int _start);

    bool isCyclic();
    void dijkstra(int _start);
    void topologicalSort();
};

#endif // LISTGRAPH_H
