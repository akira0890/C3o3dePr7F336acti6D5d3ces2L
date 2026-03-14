#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int weigth, dest;

    Node(int w, int d) : weigth(w) , dest(d) {}

    bool operator<(const Node& other) const {
        return weigth < other.weigth;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,s,d,w; std::cin >> n >> m;

    std::vector<std::vector<Node>> g(n+1);

    for (int i = 0 ; i < m ; i++) {
        std::cin >> s >> d >> w;
        g[s].emplace_back(w,d);
        g[d].emplace_back(w,s);
    }

    std::priority_queue<Node> pq;
    std::vector<bool> visited(n+1,false);
    pq.emplace(1,1);

    unsigned long long res = 0;

    while (!pq.empty()) {
        auto [weigth , dest] = pq.top();
        pq.pop();

        if (visited[dest]) continue;

        res += weigth-1;
        visited[dest] = true;

        for (auto [we , de] : g[dest]) {
            if (!visited[de]) {
                pq.emplace(we , de);
            }
        }
    }

    std::cout << res;
}