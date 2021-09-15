#ifndef GRAPH_H
#define GRAPH_H
class Graph {
public:
    virtual bool empty() = 0;
    virtual void addEdge(int _src, int _dest, int _weight, bool _directed = true) = 0;
    virtual void print() = 0;

    virtual bool depthFirstSearch(int _start) = 0;
    virtual bool breadthFirstSearch(int _start) = 0;

    virtual bool isCyclic() = 0;
    virtual void dijkstra(int _start) = 0;
    virtual void topologicalSort() = 0;
};

#endif // GRAPH_H
