#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int,int>
const int sizes = 61;

std::vector<std::vector<int>> g(sizes);

void addNode(int source , int dest) {
    g[source].emplace_back(dest);
    g[dest].emplace_back(source);
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int m,s,i,a,b; std::cin >> m >> s >> i;

    for (int i = 0 ; i < m ; i++) {
        std::cin >> a >> b;
        addNode(a,b);
    }

    std::priority_queue<pii , std::vector<pii> , std::greater<pii>> pq;
    std::vector<int> distance(sizes , 1e9);
    distance[s] = 0;
    pq.emplace(0,s);

    while (!pq.empty()) {
        auto [d , source] = pq.top();
        pq.pop();

        if (d > distance[source]) continue;

        for (int dest : g[source]) {
            if (distance[dest] > distance[source] + 1) {
                distance[dest] = distance[source] + 1;
                pq.emplace(distance[dest] , dest);
            }
        }
    }

    std::cout << distance[i];

}