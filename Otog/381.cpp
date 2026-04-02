#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

#define pll std::pair<int , int>

struct Node {
    int dest;
    int w;

    Node(int Dest , int W) : dest(Dest) , w(W) {}

    bool operator>(const Node& other) const {
        return w > other.w;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    int vertex;
public:
    Graph(int n) {
        g.resize(n);
        vertex = n;
    }

    void addNode(int u , int v , int w) {
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    int dijkstra(int source , int target) {
        // std::vector<pll> dist(vertex , {0,0});
        std::vector<int> maximum(vertex , 0);
        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
        pq.emplace(source , INT_MAX);

        while (!pq.empty()) {
            auto [curr , distance] = pq.top();
            pq.pop();

            if (distance < maximum[curr]) continue;

            for (auto [dest , w] : g[curr]) {
                int maxs = std::min(w , distance);
                if (maximum[dest] < maxs) {
                    maximum[dest] = maxs;
                    pq.emplace(dest , maxs);
                }
            }
        }

        return maximum[target];
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    Graph g(n+1);

    int u,v;
    int w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    int start,end,people;
    std::cin >> start >> end >> people;

    double value = g.dijkstra(start , end);
    value--;
    std::cout << std::ceil((double)people / value);
}