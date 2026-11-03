
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class DSU {
private:
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        iota(parent.begin(), parent.end(), 0);
    }

    int findRoot(int u) {
        if (parent[u] == u)
            return u;

        return parent[u] = findRoot(parent[u]);
    }

    bool unite(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);

        if (u == v)
            return false;

        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];

        return true;
    }
};

class Kruskal {
private:
    int V;

    struct Edge {
        int u, v, w;
    };

    vector<Edge> edges;

public:
    Kruskal(int n) {
        V = n;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void findMST() {
        sort(edges.begin(), edges.end(),
             [](Edge a, Edge b) {
                 return a.w < b.w;
             });

        DSU dsu(V);

        long long total = 0;
        int count = 0;

        for (auto e : edges) {
            if (dsu.unite(e.u, e.v)) {
                total += e.w;
                count++;

                if (count == V - 1)
                    break;
            }
        }

        if (count != V - 1)
            cout << "MST does not exist\n";
        else
            cout << "Kruskal MST Weight: "
                 << total << endl;
    }
};

int main() {
    Kruskal k(5);

    k.addEdge(0, 1, 2);
    k.addEdge(0, 2, 4);
    k.addEdge(1, 2, 1);
    k.addEdge(1, 3, 7);
    k.addEdge(2, 4, 3);
    k.addEdge(3, 4, 2);

    k.findMST();

    return 0;
}
