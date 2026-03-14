#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , dis , ansi = INT_MAX; std::cin >> n;
    char s , d , ansc;

    std::vector<std::vector<std::pair<int,int>>> g(70);

    for (int i = 0 ; i < n ; i++) {
        std::cin >> s >> d >> dis;
        g[s - 'A'].emplace_back(std::make_pair(d-'A' , dis));
        g[d - 'A'].emplace_back(std::make_pair(s-'A' , dis));
    }

    std::vector<int> distance(70,INT_MAX);
    std::priority_queue<std::pair<int,int> , std::vector<std::pair<int,int>> , std::greater<std::pair<int,int>>> pq;
    pq.emplace(0,'Z'-'A');
    distance['Z'-'A'] = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        auto [d,u] = top;

        if (d > distance[u]) continue;

        for (auto [dest , dist] : g[u]) {
            if (distance[u] + dist < distance[dest]) {
                distance[dest] = distance[u] + dist;
                pq.emplace(distance[dest], dest);
            }
        }
    }

    for (int i = 0 ; i < 25 ; i++) {
        if (distance[i] < ansi) {
            ansi = distance[i];
            ansc = i + 'A';
        }
    }

    std::cout << ansc << ' ' << ansi;
}