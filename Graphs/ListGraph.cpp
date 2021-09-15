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

#include "ListGraph.h"

struct ListGraph::AdjacencyList {
    struct Vertex {
        Vertex (int _dest, int _weight) {
            dest = _dest;
            weight = _weight;
        }

        int dest;
        int weight;
        Vertex* next;
    };

    Vertex *head;
};

ListGraph::ListGraph (int _v) {
    size = _v;
    lists = new AdjacencyList[_v];

    for (int i = 0; i < _v; ++i) {
        lists[i].head = nullptr;
    }
}

ListGraph::~ListGraph(){
    for (int i = 0; i < size; ++i) {
        AdjacencyList::Vertex* vertex = lists[i].head;
        while (vertex != nullptr) {
            AdjacencyList::Vertex* toDelete = vertex;
            vertex = vertex->next;
            delete toDelete;
        }
    }
    delete [] lists;
}

bool ListGraph::empty(){
    return (lists[0].head == nullptr);
}

void ListGraph::addEdge(int _src, int _dest, int _weight, bool _directed){
    AdjacencyList::Vertex* vertex = new AdjacencyList::Vertex(_dest, _weight);
    vertex->next = lists[_src].head;
    lists[_src].head = vertex;

    if (!_directed) {
        AdjacencyList::Vertex* otherVertex = new AdjacencyList::Vertex(_src, _weight);
        otherVertex->next=lists[_dest].head;
        lists[_dest].head = otherVertex;
    }
}

void ListGraph::print(){
    for (int i = 0; i < size; ++i) {
        std::cout << "Adjacency list of vertex (" << i << ") head" << std::endl;

        AdjacencyList::Vertex* vertex = lists[i].head;
        while (vertex != nullptr) {
            std::cout << "->(" << vertex->dest << ")";
            vertex = vertex->next;
        }
        std::cout << std::endl;
    }
}

bool ListGraph::depthFirstSearch(int _start){
    bool* visited = new bool[size];
    depthFirstSearch(_start, visited);
    std::cout << std::endl;

    //check of strongly connected
    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            delete [] visited;
            return false;
        }
    }
    delete [] visited;
    return true;
}

void ListGraph::depthFirstSearch(int _v, bool* _visited){
    _visited[_v] = true;
    std::cout << _v;

    AdjacencyList::Vertex* vertex = lists[_v].head;
    while (vertex != nullptr) {
        int dest = vertex->dest;

        if (!_visited[dest]) {
            std::cout << "->";
            depthFirstSearch(dest, _visited);
        }
        vertex = vertex->next;
    }
}

bool ListGraph::breadthFirstSearch(int _start){
    bool* visited = new bool[size];
    breadthFirstSearch(_start, visited);
    std::cout << std::endl;

    //check of strongly connected
    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            delete [] visited;
            return false;
        }
    }
    delete [] visited;
    return true;
}

void ListGraph::breadthFirstSearch(int _v, bool* _visited){
    std::queue<int>* queue = new std::queue<int>();

    _visited[_v] = true;
    queue->push(_v);

    while (!queue->empty()) {
        int current = queue->front();
        queue->pop();
        std::cout << current << "->";

        AdjacencyList::Vertex* vertex = lists[current].head;
        while (vertex != nullptr) {
            int dest = vertex->dest;

            if (!_visited[dest]) {
                _visited[dest] = true;
                queue->push(dest);
            }
            vertex = vertex->next;
        }
    }
}

bool ListGraph::isCyclic() {
    bool* visited = new bool[size];
    bool* onceVisited = new bool[size];

    for(int i = 0; i < size; i++) {
        visited[i] = false;
        onceVisited[i] = false;
    }

    for(int i = 0; i < size; i++){
        if (isCyclic(i, visited, onceVisited)){
            delete [] visited;
            delete [] onceVisited;
            return true;
        }
    }

    delete [] visited;
    delete [] onceVisited;
    return false;
}

//A DFS with a diffrent scope
bool ListGraph::isCyclic(int _v, bool _visited[], bool _onceVisited[]){
    if(_visited[_v] == false) {
         _visited[_v] = true;
         _onceVisited[_v] = true;

         AdjacencyList::Vertex* vertex = lists[_v].head;
         while (vertex != nullptr) {
             int dest = vertex->dest;

             if( (!_visited[dest] && isCyclic(dest, _visited, _onceVisited)) || (_onceVisited[dest])){
                 return true;
             }
             vertex = vertex->next;
         }
     }
     _onceVisited[_v] = false;
     return false;
}

//Optimized code based on Karthikeya Boyini
void ListGraph::dijkstra(int _start){
    int dist[size];
    std::list<int> q;

    for (int i = 0; i < size; i++) {
        dist[i] = INT_MAX;
        q.push_back(i);
    }

    dist[_start] = 0;

    while (!q.empty()) {
        auto i = std::min_element(q.begin(), q.end());
        int u = *i;
        q.remove(u);

        AdjacencyList::Vertex* vertex = lists[u].head;
        while (vertex != nullptr) {
            if(dist[u] + vertex->weight < dist[vertex->dest]) {
               dist[vertex->dest] = (dist[u]+(vertex->weight));
            }
            vertex = vertex->next;
        }
    }
    printDijkstraSolution(dist);
}

void ListGraph::printDijkstraSolution(int _dist[]) {
    std::cout <<"Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << i << " \t\t"<<_dist[i]<< std::endl;
    }
}

void ListGraph::topologicalSort(){
    std::stack<int> stack;
    bool* visited = new bool[size];

    for (int i = 0; i < size; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            topologicalSort(i, visited, stack);
        }
    }
    delete [] visited;

    while (!stack.empty()) {
        std::cout << stack.top() << "->";
        stack.pop();
    }
    std::cout << std::endl;
}

//Another DFS with yet again a diffrent scope
void ListGraph::topologicalSort(int _v, bool _visited[], std::stack<int>& _stack){
    _visited[_v] = true;

    AdjacencyList::Vertex* vertex = lists[_v].head;
    while (vertex != nullptr) {
        int dest = vertex->dest;

        if (!_visited[dest]) {
            topologicalSort(dest, _visited, _stack);
        }
        vertex = vertex->next;
    }
    _stack.push(_v);
}
