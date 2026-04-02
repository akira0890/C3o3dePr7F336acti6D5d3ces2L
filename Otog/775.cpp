#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define pii std::pair<long long , int>

class Graph {
    std::vector<std::vector<pii>> distance;
    int n;
public:
    Graph(int N) {
        n = N;
        distance.resize(n+1);
        for (int i = 0 ; i <= n ; i++) {
            distance[i].resize(n+1,{LLONG_MAX,0});
            distance[i][i] = {0,0};
        }
    }

    void addNode(int u , int v , long long w , int item = 2) {
        distance[u][v] = {std::min(w , distance[u][v].first), item};
        distance[v][u] = {std::min(w , distance[v][u].first), item};
    }

    void floyd() {
        for (int k = 0 ; k <= n ; k++) {
            for (int i = 0 ; i <= n ; i++) {
                if (distance[i][k].first == LLONG_MAX) continue;
                for (int j = 0 ; j <= n ; j++) {
                    if (distance[k][j].first == LLONG_MAX) continue;

                    long long newdist = distance[i][k].first + distance[k][j].first;
                    int       newedge = distance[i][k].second + distance[k][j].second;
                    if (distance[i][j].first > newdist) {
                        distance[i][j].first = newdist;
                        distance[i][j].second = newedge;
                    } else if (distance[i][j].first == newdist) {
                        distance[i][j].second = std::max(distance[i][j].second , newedge);
                    }
                }
            }
        }
    }

    pii distUV(int source , int target) {
        return distance[source][target];
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,q; std::cin >> n >> m >> q;
    std::vector<long long> price(n+1);
    
    Graph g(n);
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> price[i];
        g.addNode(i , 0 , price[i] , 1);
    }

    int u , v;
    long long w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    g.floyd();

    for (int i = 0 ; i < q ; i++) {
        std::cin >> u >> v;
        pii floyd  = g.distUV(u,v);

        std::cout << floyd.first << ' ' << floyd.second << '\n';
    }
}