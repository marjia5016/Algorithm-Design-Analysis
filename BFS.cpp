#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFS {
private:
    int V;
    vector<vector<int>> adj;

public:
    BFS(int n) {
        V = n;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void traversal(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    BFS bfs(5);

    bfs.addEdge(0, 1);
    bfs.addEdge(0, 2);
    bfs.addEdge(1, 3);
    bfs.addEdge(2, 4);

    bfs.traversal(0);

    return 0;
}
