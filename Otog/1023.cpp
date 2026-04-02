#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define ll long long
const long long INF = 1e15;

struct Node {
    int dest;
    long long weight;

    Node(int Dest , long long Weight) : dest(Dest) , weight(Weight) {}
};

struct State {
    int dest;
    long long dist , crystal;

    State(int Dest , long long Dist , long long Crystal) : dest(Dest) , dist(Dist) , crystal(Crystal) {}

    bool operator>(const State& other) const {
        if (dist != other.dist)return dist > other.dist;
        return crystal > other.crystal;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    std::vector<std::vector<ll>> dist;
    std::vector<long long> prefixMinimum;
    int vertex;
public:
    Graph(int n) {
        g.resize(n+1);
        prefixMinimum.resize(2001,INF);
        vertex = n;
        dist = std::vector<std::vector<ll>>(n+1 , std::vector<long long>(2001,INF));
    }

    void addNode(int u , int v , ll w) {
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    void dijkstra(int source , const std::vector<int> Crystal) {
        dist[source][0] = 0;

        std::priority_queue<State,std::vector<State>,std::greater<State>> pq;
        pq.emplace(source , 0 , 0);

        while (!pq.empty()) {
            auto [curr , d , cyl] = pq.top();
            pq.pop();

            if (dist[curr][cyl] < d) continue;

            for (auto [dest , weight] : g[curr]) {
                if (dist[dest][cyl] > dist[curr][cyl] + weight) {
                    dist[dest][cyl] = dist[curr][cyl] + weight;
                    pq.emplace(dest , dist[dest][cyl] , cyl);
                }
                if (cyl + Crystal[curr] <= 2000 && dist[dest][cyl+Crystal[curr]] > dist[curr][cyl]) {
                    dist[dest][cyl + Crystal[curr]] = dist[curr][cyl];
                    pq.emplace(dest , dist[dest][cyl+Crystal[curr]] , cyl + Crystal[curr]);
                }
            }
        }

        prefixMinimum[0] = dist[vertex][0];
        for (int i = 1 ; i <= 2000 ; i++) {
            prefixMinimum[i] = std::min(prefixMinimum[i-1] , dist[vertex][i]);
        }
    }

    long long GetDist(int dest , int cost) {
        return prefixMinimum[cost];
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,q; std::cin >> n >> m >> q;
    std::vector<int> cost(n+1);
    cost[0] = 0;
    for (int i = 1 ; i <= n ; i++) std::cin >> cost[i];

    int u,v;
    long long w;

    Graph g(n);
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    g.dijkstra(1,cost);

    long long target;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> target;
        std::cout << g.GetDist(n,target) << '\n';
    }
}