
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> matrix;

public:
    Graph(int n) {
        V = n;
        adj.resize(V);
        matrix.assign(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);

        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void displayList() {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < V; i++) {
            cout << i << ": ";

            for (int v : adj[i])
                cout << v << " ";

            cout << endl;
        }
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << matrix[i][j] << " ";

            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.displayList();
    g.displayMatrix();

    return 0;
}
