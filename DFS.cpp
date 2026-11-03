
#include <iostream>
#include <vector>
using namespace std;

class DFS {
private:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;

    void dfsVisit(int u) {
        visited[u] = true;

        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfsVisit(v);
            }
        }
    }

public:
    DFS(int n) {
        V = n;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void traversal(int start) {
        visited.assign(V, false);

        cout << "DFS Traversal: ";

        dfsVisit(start);

        cout << endl;
    }
};

int main() {
    DFS dfs(5);

    dfs.addEdge(0, 1);
    dfs.addEdge(0, 2);
    dfs.addEdge(1, 3);
    dfs.addEdge(2, 4);

    dfs.traversal(0);

    return 0;
}
