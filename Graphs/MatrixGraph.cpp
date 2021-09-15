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

#include "MatrixGraph.h"

struct MatrixGraph::AdjacencyMatrix {
private:
    int* matrix;

    struct AdjacencyMatrixIndex {
        int row;
        int column;
    };

public:
    int size;

    AdjacencyMatrix (int _v) {
        matrix = new int[_v*_v];
        size = _v;

        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                setField({x,y}, 0);
            }
        }
    }

    void setField(AdjacencyMatrixIndex _i, int _weight) {
        matrix[size*_i.row + _i.column] = _weight;
    }

    int getField(AdjacencyMatrixIndex _i){
        return matrix[size*_i.row + _i.column];
    }

    /* Doesnt work :(
    int &operator[] (const AdjacencyMatrixIndex& i) {
      return matrix[size*i.row + i.column];
    }
    */
};

MatrixGraph::MatrixGraph(int _v) {
    matrix = new AdjacencyMatrix(_v);
}

MatrixGraph::~MatrixGraph() {
    delete [] matrix;
}

bool MatrixGraph::empty() {
    for (int x = 0; x < matrix->size; ++x) {
        for (int y = 0; y < matrix->size; ++y) {
            if (matrix->getField({x,y}) != 0) {
                return false;
            }
        }
    }
    return true;
}

void MatrixGraph::addEdge(int _src, int _dest, int _weight, bool _directed){
    matrix->setField({_src, _dest}, _weight);

    if (!_directed) {
        matrix->setField({_dest, _src}, _weight);
    }
}

void MatrixGraph::print(){
    for (int x = 0; x < matrix->size; x++) {
        for (int y = 0; y < matrix->size; y++) {
            std::cout << "(" << matrix->getField({x, y}) << ")";
        }
        std::cout << std::endl;
    }
}

bool MatrixGraph::depthFirstSearch(int _start){
    bool* visited = new bool[matrix->size];
    depthFirstSearch(_start, visited);
    std::cout << std::endl;

    //check if strongly connected
    for (int i = 0; i < matrix->size; ++i) {
        if (!visited[i]) {
            delete [] visited;
            return false;
        }
    }

    delete [] visited;
    return true;
}

void MatrixGraph::depthFirstSearch(int _v, bool* _visited){
    std::cout << _v;

    _visited[_v] = true;
    for (int i = 0; i < matrix->size; i++) {
        if (matrix->getField({_v, i}) >= 1 && !_visited[i]) {
            std::cout << "->";
            depthFirstSearch(i, _visited);
        }
    }
}

bool MatrixGraph::breadthFirstSearch(int _start){
    bool* visited = new bool[matrix->size];
    breadthFirstSearch(_start, visited);
    std::cout << std::endl;

    //check of strongly connected
    for (int i = 0; i < matrix->size; ++i) {
        if (!visited[i]) {
            delete [] visited;
            return false;
        }
    }

    delete [] visited;
    return true;
}

void MatrixGraph::breadthFirstSearch(int _v, bool* _visited){
    std::queue<int> queue;
    queue.push(_v);

    _visited[_v] = true;
    while (!queue.empty()) {
        int vis = queue.front();
        queue.pop();

        std::cout << vis << "->";

        for (int i = 0; i < matrix->size; ++i) {
            if (matrix->getField({vis, i}) >= 1 && !_visited[i]) {
                queue.push(i);
                _visited[i] = true;
            }
        }
    }
}

bool MatrixGraph::isCyclic(int _v, bool _visited[], bool _onceVisited[]){
    if(_visited[_v] == false) {
         _visited[_v] = true;
         _onceVisited[_v] = true;

        for (int i = 0; i < matrix->size; i++) {
            /* if field is set and either
             * 1. visted as well as isCyclic OR
             * 2. if already was visited once before
             * then graph is cyclic
             */
            if(matrix->getField({_v, i}) >= 1 && ((!_visited[i] && isCyclic(i, _visited, _onceVisited)) || (_onceVisited[i]))){
                 return true;
            }
        }
     }
     _onceVisited[_v] = false;
     return false;
}

//A DFS with a diffrent scope
bool MatrixGraph::isCyclic() {
    bool* visited = new bool[matrix->size];
    bool* onceVisited = new bool[matrix->size];

    for(int i = 0; i < matrix->size; i++) {
        visited[i] = false;
        onceVisited[i] = false;
    }

    for(int i = 0; i < matrix->size; i++){
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

void MatrixGraph::dijkstra(int _start) {
    int dist[matrix->size];
    bool visted[matrix->size];

    for (int i = 0; i < matrix->size; i++){
        dist[i] = INT_MAX, visted[i] = false;
    }

    dist[_start] = 0;
    for (int i = 0; i < matrix->size - 1; i++) {
        int m = minDistance(dist, visted);
        visted[m] = true;

        for (int v = 0; v < matrix->size; v++){
            if (!visted[v] && matrix->getField({m, v}) && dist[m] != INT_MAX
                    && dist[m] + matrix->getField({m, v}) < dist[v]){
                dist[v] = dist[m] + matrix->getField({m, v});
            }
        }
    }
    printDijkstraSolution(dist);
}


int MatrixGraph::minDistance(int _dist[], bool _visited[]) {
    int min = INT_MAX, minIndex = 0;

    for (int v = 0; v < matrix->size; v++){
        if (_visited[v] == false && _dist[v] <= min){
            min = _dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void MatrixGraph::printDijkstraSolution(int _dist[]) {
    std::cout <<"Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < matrix->size; i++){
        std::cout << i << " \t\t"<<_dist[i]<< std::endl;
    }
}

void MatrixGraph::topologicalSort(){
    std::stack<int> stack;
    bool* visited = new bool[matrix->size];

    for (int i = 0; i < matrix->size; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < matrix->size; ++i) {
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
/* Doesn't  quite works yet. Theres an bug I haven't yet sorted out
 * Other implementation in ListGraph works and is nearly the same
 */
void MatrixGraph::topologicalSort(int _v, bool _visited[], std::stack<int>& _stack){
    _visited[_v] = true;

    for (int i = 0; i < matrix->size; i++) {
        if (matrix->getField({_v, i}) >= 1 && !_visited[i]) {
            topologicalSort(i, _visited, _stack);
        }
    }
    _stack.push(_v);
}
