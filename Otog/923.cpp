#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <unordered_map>

#define pii std::pair<int,int>

class Graph {
    int size;
    std::vector<std::vector<int>> g;
    std::string c;
public:
    Graph(int n , std::string C) : size(n) {
        g.resize(n);
        c = C;
    }

    void addNode(int u , int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<int> dijkstra(int source) {
        std::vector<int> distance(size , INT_MAX);
        std::priority_queue<pii , std::vector<pii> , std::greater<pii>> pq;
        pq.emplace(std::make_pair(0 , source));
        distance[source] = 0;

        while (!pq.empty()) {
            auto [dis , u] = pq.top();
            pq.pop();

            if (dis > distance[u]) continue;

            for (int v : g[u]) {
                if (distance[v] > 1 + distance[u]) {
                    pq.emplace(std::make_pair(distance[u]+1 , v));
                    distance[v] = distance[u]+1;
                }
            }
        }

        return distance;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,l , u , v;
    std::string s, target;
    std::cin >> n >> m >> l >> s;

    Graph g(n , s);
    std::unordered_map<char , std::priority_queue<int , std::vector<int> , std::greater<int>>> unmap;

    for (int i = 0 ; i < m ; i++) std::cin >> u >> v , g.addNode(u-1,v-1);

    std::vector<int> distance = g.dijkstra(0);
    for (int i = 0 ; i < n ; i++) {
        distance[i] *= 2;

        unmap[s[i]].emplace(distance[i]);
    }

    long long sum = 0;
    std::cin >> target;
    for (char c : target) {
        if (unmap[c].empty()) {
            std::cout << -1;
            return 0;
        }
        sum += unmap[c].top();
        unmap[c].pop();
    }

    std::cout << sum;

}