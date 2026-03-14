#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define pii std::pair<int,int>

struct Node {
    int dest , weigth;

    Node(int d , int w) : dest(d) , weigth(w) {}
};

class Graph {
    int n;
    std::vector<std::vector<Node>> g;
public:
    Graph(int n) : n(n) {
        g.resize(n+1);
    }

    void addNode(int u, int v , int w) {
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    int dijkstra(int source , int rest , int dest) {
        std::vector<int> distance(n , INT_MAX);
        std::priority_queue<pii , std::vector<pii> , std::greater<pii>> pq;
        distance[rest] = 0;
        pq.emplace(0,rest);

        while (!pq.empty()) {
            auto [dist , curr] = pq.top();
            pq.pop();

            for (Node dest : g[curr]) {
                if (distance[dest.dest] > distance[curr] + dest.weigth) {
                    distance[dest.dest] = distance[curr] + dest.weigth;
                    pq.emplace(distance[dest.dest] , dest.dest);
                }
            }
        }
        return distance[source] + distance[dest];
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k,q,u,v,w; std::cin >> n >> m >> k >> q;

    Graph graph(n);

    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        graph.addNode(u , v , w);
    }

    for (int i = 0 ; i < k ; i++) std::cin >> u;

    while (q--) {
        int s , x , t;
        std::cin >> s >> x >> t;

        std::cout << graph.dijkstra(s,x,t) << '\n';
    }
}