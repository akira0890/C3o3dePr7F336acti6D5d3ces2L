#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define pii std::pair<long long , int>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    char start , end;
    int m;
    std::cin >> start >> end >> m;

    std::vector<std::vector<long long>> g(26 , std::vector<long long>(26,1000005));
    std::priority_queue<pii , std::vector<pii> , std::greater<pii>> pq;

    char u,v;
    int w,o;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> w >> v >> o;
        if (o == 0) g[u-'A'][v-'A'] = w;
        if (o == 0) g[v-'A'][u-'A'] = w;
    }

    std::vector<long long> distance(26,LLONG_MAX);
    pq.emplace(0,start-'A');
    distance[start-'A'] = 0;

    while (!pq.empty()) {
        auto [dist , curr] = pq.top();
        pq.pop();

        if (distance[curr] < dist) continue;

        for (int i = 0 ; i < 26 ; i++) {
            if (g[curr][i] != 1000005) {
                if (distance[i] > distance[curr] + g[curr][i]) {
                    distance[i] = distance[curr] + g[curr][i];
                    pq.emplace(distance[i] , i);
                }
            }
        }
    }

    std::cout << distance[end - 'A'];
}