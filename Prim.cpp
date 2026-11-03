
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const long long INF = 1LL << 60;

class Prim {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Prim(int n) {
        V = n;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void findMST() {
        vector<bool> visited(V, false);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, 0});

        long long total = 0;
        int count = 0;

        while (!pq.empty()) {
            int w = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            total += w;
            count++;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!visited[v]) {
                    pq.push({weight, v});
                }
            }
        }

        if (count != V)
            cout << "MST does not exist\n";
        else
            cout << "Prim MST Weight: " << total << endl;
    }
};

int main() {
    Prim p(5);

    p.addEdge(0, 1, 2);
    p.addEdge(0, 2, 4);
    p.addEdge(1, 2, 1);
    p.addEdge(1, 3, 7);
    p.addEdge(2, 4, 3);
    p.addEdge(3, 4, 2);

    p.findMST();

    return 0;
}
