
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> sz;

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

    void unite(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);

        if (u == v)
            return;

        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }

    bool sameSet(int u, int v) {
        return findRoot(u) == findRoot(v);
    }
};

int main() {
    DSU d(5);

    d.unite(0, 1);
    d.unite(1, 2);

    if (d.sameSet(0, 2))
        cout << "Same Set\n";
    else
        cout << "Different Set\n";

    if (d.sameSet(0, 3))
        cout << "Same Set\n";
    else
        cout << "Different Set\n";

    return 0;
}
