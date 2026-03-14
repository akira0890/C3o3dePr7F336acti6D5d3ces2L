#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Node {
    int dist , s;

    Node(int Dist, int S) : s(S) , dist(Dist) {}

    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

class graph{
    int n;
    std::vector<std::vector<int>> g;
public:
    graph(int N) {
        n = N;
        g.resize(N);
    }

    void addNode(int u, int v) {
        g[u].emplace_back(v);
    }

    std::vector<int> dijkstra(int source , const std::vector<int>& energy) {
        std::vector<int> dist(n , INT_MAX);
        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
        pq.emplace(Node(energy[source],source));
        dist[source] = energy[source];

        while (!pq.empty())
        {
            auto [w , s] = pq.top();
            pq.pop();

            if (w > dist[s]) continue;

            for (int i = 0 ; i < g[s].size() ; i++) {
                if (dist[g[s][i]] > dist[s] + energy[g[s][i]]) {
                    dist[g[s][i]] = dist[s] + energy[g[s][i]];
                    pq.emplace(dist[g[s][i]] , g[s][i]);
                }
            }
        }
        return dist;
        
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k,q,source , x , y ; std::cin >> n >> k >> q >> source;

    std::vector<int> energy(n);
    for (int i = 0 ; i < n ; i++) std::cin >> energy[i];

    graph g(n);
    for (int i = 0 ; i < k ; i++) {
        std::cin >> x >> y;
        g.addNode(x-1,y-1);
    }

    std::vector<int> dist = g.dijkstra(source-1 , energy);

    while (q--) {
        std::cin >> x;
        std::cout << dist[x-1] << '\n';
    }
}