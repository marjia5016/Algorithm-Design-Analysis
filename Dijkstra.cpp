
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const long long INF = 1LL << 60;

class Dijkstra {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Dijkstra(int n) {
        V = n;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void shortestPath(int source) {
        vector<long long> dist(V, INF);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            long long d = pq.top().first;

            pq.pop();

            if (d != dist[u])
                continue;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest Distances:\n";

        for (int i = 0; i < V; i++) {
            cout << source << " -> " << i << ": ";

            if (dist[i] == INF)
                cout << "Unreachable";
            else
                cout << dist[i];

            cout << endl;
        }
    }
};

int main() {
    Dijkstra d(5);

    d.addEdge(0, 1, 2);
    d.addEdge(0, 2, 4);
    d.addEdge(1, 2, 1);
    d.addEdge(1, 3, 7);
    d.addEdge(2, 4, 3);
    d.addEdge(3, 4, 2);

    d.shortestPath(0);

    return 0;
}
