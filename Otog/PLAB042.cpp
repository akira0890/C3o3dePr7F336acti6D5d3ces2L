#include <iostream>
#include <vector>
#include <climits>

class Graph {
    std::vector<std::vector<long long>> dist;
    long long N;
public:
    Graph(long long n , const std::vector<std::vector<long long>> &v) {
        N = n;
        dist = v;
    }

    void addNode(long long u , long long v , long long w) {
        dist[u][v] = std::min(dist[u][v] , w);
        dist[v][u] = std::min(dist[v][u] , w);
    }

    void floyd() {
        for (long long k = 0 ; k < N ; k++) {
            for (long long i = 0 ; i < N ; i++) {
                if (dist[i][k] == LLONG_MAX) continue;
                for (long long j = 0 ; j < N ; j++) {
                    if (dist[k][j] == LLONG_MAX) continue;
                    dist[i][j] = std::min(dist[i][k] + dist[k][j] , dist[i][j]);
                    // if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    //     dist[i][j] = dist[i][k] + dist[k][j];
                    // }
                }
            }
        }
    }

    long long get(long long start , long long target) {
        return dist[start][target];
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long n,m,start , end; std::cin >> n >> m >> start >> end;
    std::vector<std::vector<long long>> g(n , std::vector<long long>(n,LLONG_MAX));
    for (long long i = 0 ; i < n ; i++) g[i][i] = 0;
    
    long long u,v,w;
    for (long long i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g[u][v] = std::min(g[u][v], w);
        g[v][u] = std::min(g[v][u], w);
    }
    Graph graph(n , g);
    graph.floyd();

    std::cout << graph.get(start,end) << '\n' << graph.get(start , end) * 20;
}