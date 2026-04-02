#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

struct Node {
    int v;
    long long w;

    Node(int v , long long w) : v(v) , w(w) {}

    bool operator<(const Node & other) const {
        return w < other.w;
    }

    bool operator>(const Node & other) const {
        return w > other.w;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    int n;
public:
    Graph(int N) {
        n = N+1;
        g.resize(N+1);
    }

    void addNode(int u , int v , long long w) {
        g[u].emplace_back(v , w);
        g[v].emplace_back(u , w);
    }

    long long dijkstra(int source) {
        std::vector<long long> distance(n , LLONG_MAX);
        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;

        distance[source] = 0;
        pq.emplace(source , 0);

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            if (distance[curr.v] < curr.w) continue;

            for (auto [dest , w] : g[curr.v]) {
                if (distance[dest] > distance[curr.v] + w) {
                    distance[dest] = distance[curr.v] + w;
                    pq.emplace(dest , distance[dest]);
                }
            }
        }

        return distance[n-1];
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;
    int u,v;
    long long w;

    Graph g(n);

    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    std::cin >> m;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> v >> w;
        g.addNode(n,v,w);
    }

    std::cout << g.dijkstra(0);
}