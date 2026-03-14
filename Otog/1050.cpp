#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Node {
    int dest;
    long long weight;

    Node (int _dest , long long _weight) :
        dest(_dest) , weight(_weight) {}

    bool operator>(const Node& other) const {
        return weight > other.weight;
    }
};

struct Edge {
    int u , v;
    long long weight;

    Edge(int _u , int _v , long long _weight) :
        u(_u) , v(_v) , weight(_weight) {}
};

class Graph {
    int n;
    std::vector<std::vector<Node>> g;
public:
    Graph(int N) {
        n = N;
        g.resize(N);
    }

    void addNode(int u , int v , long long weight) {
        g[u].emplace_back(v , weight);
        g[v].emplace_back(u , weight);
    }

    std::vector<long long> dijkstra(int source) {
        std::vector<long long> dist(n , LLONG_MAX);

        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
        dist[source] = 0;
        pq.emplace(source , 0);

        while (!pq.empty()) {
            auto [curr , cDist] = pq.top();
            pq.pop();

            if (dist[curr] < cDist) continue;
            
            for (Node dest : g[curr]) {
                if (dist[dest.dest] > dist[curr] + dest.weight) {
                    dist[dest.dest] = dist[curr] + dest.weight;
                    pq.emplace(dest.dest , dist[dest.dest]);
                }
            }
        }

        return dist;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int Nvertex , Nedge , Q , start , end;
    std::cin >> Nvertex >> Nedge >> Q >> start >> end;

    Graph graph(Nvertex);

    std::vector<Edge> edge;
    edge.reserve(Nedge);

    int u , v;
    long long weight;

    for (int i = 0 ; i < Nedge ; i++) {
        std::cin >> u >> v >> weight;
        graph.addNode(u , v , weight);
        edge.emplace_back(u,v,weight);
    }

    std::vector<long long> DistfromA = graph.dijkstra(start);
    std::vector<long long> DistfromB = graph.dijkstra(end);

    int iedge;

    for (int i = 0 ; i < Q ; i++) {
        std::cin >> iedge;
        u = edge[iedge].u;
        v = edge[iedge].v;
        long long w = edge[iedge].weight;

        long long ans1 = DistfromA[u] + DistfromB[v] + w;
        long long ans2 = DistfromA[v] + DistfromB[u] + w;

        std::cout << std::min(ans1 , ans2) << '\n';
    }
}