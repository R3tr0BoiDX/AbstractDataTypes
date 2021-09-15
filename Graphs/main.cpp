#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"

using namespace std;

int main() {

    cout << "Bitte Anzahl der Knoten eingeben: ";
    int i;
    cin >> i;
    MatrixGraph graph(i); //Change typ of graph here (either ListGraph or MatrixGraph)

    bool loop = true;
    while (loop) {
        cout << "0. exit" << endl;
        cout << "1. Fill with test data" << endl;
        cout << "2. empty()" << endl;
        cout << "3. addEdge(src, dest)" << endl;
        cout << "4. print()" << endl;
        cout << "5. depthFirstSearch(start)" << endl;
        cout << "6. breadthFirstSearch(start)" << endl;
        cout << "7. isCyclic()" << endl;
        cout << "8. dijkstra(start)" << endl;
        cout << "9. topologicalSort()" << endl;
        cout << "Please choose: ";

        int s;
        cin >> s;

        switch (s) {
            case 0:
                loop = false;
                break;

            case 1:
                graph.addEdge(0, 1, 3);
                graph.addEdge(0, 2, 6);
                graph.addEdge(1, 0, 3);
                graph.addEdge(1, 2, 2);
                graph.addEdge(1, 3, 1);
                graph.addEdge(2, 1, 6);
                graph.addEdge(2, 1, 2);
                graph.addEdge(2, 3, 1);
                graph.addEdge(2, 4, 4);
                graph.addEdge(2, 5, 2);
                graph.addEdge(3, 1, 1);
                graph.addEdge(3, 2, 1);
                graph.addEdge(3, 4, 2);
                graph.addEdge(3, 6, 4);
                graph.addEdge(4, 2, 4);
                graph.addEdge(4, 3, 2);
                graph.addEdge(4, 5, 2);
                graph.addEdge(4, 6, 1);
                graph.addEdge(5, 2, 2);
                graph.addEdge(5, 4, 2);
                graph.addEdge(5, 6, 1);
                graph.addEdge(6, 3, 4);
                graph.addEdge(6, 4, 1);
                graph.addEdge(6, 5, 1);
                break;

            case 2:
                cout << "Graph is empty: " << graph.empty() << endl;
                break;

            case 3:{
                int src, dest, weight;

                cout << "Please enter source: ";
                cin >> src;

                cout << "Please enter destination: ";
                cin >> dest;

                cout << "Please enter weight: ";
                cin >> weight;

                graph.addEdge(src, dest, weight);
                break;
            }

            case 4:
                graph.print();
                break;

            case 5:{
                int start;
                cout << "Please enter start vertex: ";
                cin >> start;

                bool result = graph.depthFirstSearch(start);
                cout << "Graph is strongly connected: " << result << endl;
                break;
            }

            case 6:{
                int start;
                cout << "Please enter start vertex: ";
                cin >> start;

                bool result = graph.breadthFirstSearch(start);
                cout << "Graph is strongly connected: " << result << endl;
                break;
            }

            case 7:{
                cout << "Graph has cycles: " << graph.isCyclic() << endl;
                break;
            }

            case 8:{
                int start;
                cout << "Please enter start vertex: ";
                cin >> start;

                graph.dijkstra(start);
                break;
            }

            case 9:
                graph.topologicalSort();
                break;

            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }
        cout << "========================" << endl;
    }
    return 0;
}
