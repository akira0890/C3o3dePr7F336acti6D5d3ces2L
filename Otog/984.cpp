#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Node {
    int dest , weight;

    Node (int _dest , int _weight) :
        dest(_dest) , weight(_weight) {}

    bool operator>(const Node& other) const {
        return weight > other.weight;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    int n , p , power;
public:
    Graph(int n, int p , int power) : n(n) , p(p) , power(power) {
        g.resize(n);
    }

    void addNode(int u , int v , int weight) {
        g[u].emplace_back(v , weight);
        // g[v].emplace_back(u , weight);
    }

    std::vector<int> dijkstra(int source) {
        std::vector<int> dist(n , INT_MAX);
        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;

        pq.emplace(source , 0);
        dist[source] = 0;

        while (!pq.empty()) {
            auto [s , distance] = pq.top();
            pq.pop();

            if (dist[s] < distance) continue;

            for (auto const& dest : g[s]) {
                if (distance + dest.weight <= power) {
                    int currdist = (dest.dest == p ? 0 : distance + dest.weight);
                    if (dist[dest.dest] > currdist) {
                        dist[dest.dest] = currdist;
                        pq.emplace(dest.dest , currdist);
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,q,power,p,start;
    std::cin >> n >> m >> q >> power >> p >> start;

    Graph graph(n+1 , p , power);

    int u , v , w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        graph.addNode(u,v,w);
    }

    std::vector<int> distance = graph.dijkstra(start);

    int target;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> target;

        int ans = distance[target];
        if (ans > power || ans == INT_MAX) std::cout << "-1\n";
        else std::cout << power - ans << '\n';
    }
}