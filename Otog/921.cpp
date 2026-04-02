#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Node {
    int dest;
    long long weight;

    Node(int Dest , long long Weight) :
        dest(Dest) , weight(Weight) {}

    bool operator>(const Node& other) const {
        return weight > other.weight;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    int n;
public:
    Graph(int N) {
        n = N;
        g.resize(N);
    }

    void addNode(int u , int v , long long w) {
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    long long dijkstra(int source , int target) {
        std::vector<long long> distance(n , LLONG_MAX);
        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;

        pq.emplace(source,0);
        distance[source] = 0;

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            if (distance[curr.dest] < curr.weight) continue;

            for (Node dest : g[curr.dest]) {
                if (distance[curr.dest] + dest.weight < distance[dest.dest]) {
                    distance[dest.dest] = distance[curr.dest] + dest.weight;
                    pq.emplace(dest.dest , distance[dest.dest]);
                }
            }
        }

        return distance[target];
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,u,v;
    long long w;
    std::cin >> n >> m;

    Graph g(n+1);
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    long long sum = 0;
    for (int i = 1 ; i < n ; i++) {
        sum += g.dijkstra(i,i+1);
    }

    std::cout << sum;
}