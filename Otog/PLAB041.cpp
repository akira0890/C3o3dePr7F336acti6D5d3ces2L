#include <iostream>
#include <vector>
#include <climits>
#include <queue>

struct Node {
    int dest , weight;

    Node(int Dest , int Weight) : dest(Dest) , weight(Weight) {}

    bool operator>(const Node & other) const {
        return weight > other.weight;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    int N;
public:
    Graph(int n) {
        g.resize(n);
        N = n;
    }

    void addNode(int u , int v , int w) {
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    int dijkstra(int source , int target) {
        std::vector<int> distance(N,INT_MAX);
        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
        distance[source] = 0;
        pq.emplace(source,0);

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            if (distance[curr.dest] < curr.weight) continue;

            for (auto [dest , w] : g[curr.dest]) {
                if (distance[dest] > distance[curr.dest] + w) {
                    distance[dest] = distance[curr.dest] + w;
                    pq.emplace(dest , distance[dest]);
                }
            }
        }

        return distance[target];
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,start ,end; std::cin >> n >> m >> start >> end;

    Graph g(n);

    int u,v,w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    int res = g.dijkstra(start , end);
    std::cout << res << '\n' << res*20;
}