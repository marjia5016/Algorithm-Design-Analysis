
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 60;

class FloydWarshall {
private:
    int V;
    vector<vector<long long>> dist;

public:
    FloydWarshall(int n) {
        V = n;

        dist.assign(V, vector<long long>(V, INF));

        for (int i = 0; i < V; i++)
            dist[i][i] = 0;
    }

    void addEdge(int u, int v, int w) {
        dist[u][v] = min(dist[u][v], (long long)w);
        dist[v][u] = min(dist[v][u], (long long)w);
    }

    void findShortestPaths() {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {

                    if (dist[i][k] != INF &&
                        dist[k][j] != INF) {

                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );
                    }
                }
            }
        }

        cout << "Floyd Warshall Matrix:\n";

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    FloydWarshall f(5);

    f.addEdge(0, 1, 2);
    f.addEdge(0, 2, 4);
    f.addEdge(1, 2, 1);
    f.addEdge(1, 3, 7);
    f.addEdge(2, 4, 3);
    f.addEdge(3, 4, 2);

    f.findShortestPaths();

    return 0;
}
