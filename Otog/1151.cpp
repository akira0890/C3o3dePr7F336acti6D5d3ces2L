#include <iostream>
#include <vector>
#include <queue>
#include <climits>

const long long INF = LLONG_MAX;

struct Node {
    int dest;
    long long w;

    Node(int Dest , long long W) : dest(Dest) , w(W) {}

    bool operator>(const Node & other) const {
        return w > other.w;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    int vertex;
public:
    Graph(int N) {
        vertex = N;
        g.resize(N);
    }

    void addNode(int u , int v , long long w) {
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    std::vector<long long> dijkstra(int source) {
        std::vector<long long> dist(vertex , INF);
        std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
        pq.emplace(source , 0);
        dist[source] = 0;

        while (!pq.empty()) {
            auto [curr , d] = pq.top();
            pq.pop();

            if (dist[curr] < d) continue;

            for (auto [dest , w] : g[curr]) {
                if (dist[dest] > dist[curr] + w) {
                    dist[dest] = dist[curr] + w;
                    pq.emplace(dest , dist[dest]);
                }
            }
        }

        return dist;
    }
};

int k;
long long minDist = INF;
std::vector<int> target;

void dfs(const std::vector<std::vector<long long>> &distance , int source , long long Cost , std::vector<bool> &visited , int n) {
    if (n == visited.size()) {
        minDist = std::min(minDist , Cost + distance[source][0]);
        return;
    }

    for (int i = 0 ; i < k ; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(distance , i , Cost + distance[source][i] , visited , n+1);
            visited[i] = false;
        }
    }
}

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m >> k;
    k++;
    target.resize(k);
    target[0] = 0;
    for (int i = 1 ; i < k ; i++) std::cin >> target[i];

    int u , v;
    long long w;
    Graph g(n);
    // std::cout << "work\n";

    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    // std::cout << "work\n";

    std::vector<std::vector<long long>> distance(k , std::vector<long long>(k));
    for (int i = 0 ; i < k ; i++) {
        std::vector<long long> d = g.dijkstra(target[i]);
        for (int j = 0 ; j < k ; j++) {
            distance[i][j] = d[target[j]];
        }
    }

    std::vector<bool> visited(k,false);
    visited[0] = true;
    dfs(distance , 0 , 0 , visited , 1);

    // std::cout << "work\n";

    std::cout << minDist;
}