#include <iostream>
#include <vector>
#include <stack>
#include <queue>

const int size = 1e6+5;
long long maxDist[size];
int parent[size];
int parentWeight[size];

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<std::vector<std::pair<int,int>>> g(n+1);

    int u,v,w;
    for (int i = 0 ; i < n-1 ; i++) {
        std::cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    std::stack<int> s;
    std::vector<int> order;
    parent[1] = 0;
    int maxvalue = 0;
    s.emplace(1);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();
        order.emplace_back(curr);

        for (auto [dest , d] : g[curr]) {
            if (dest != parent[curr]) {
                parent[dest] = curr;
                s.emplace(dest);
                parentWeight[dest] = d;
            }
        }
    }

    long long res = 0;

    for (int i = order.size()-1 ; i >= 0 ; i--) {
        int u = order[i];

        long long currmax = 0;
        for (auto [dest , d] : g[u]) {
            if (dest != parent[u]) {
                currmax = std::max(currmax , maxDist[dest] + (long long)d);
            }
        }

        maxDist[u] = currmax;

        for (auto [dest , d] : g[u]) {
            if (dest != parent[u]) {
                long long childDist = maxDist[dest] + (long long)parentWeight[dest];
                if (childDist < currmax) {
                    res += currmax - childDist;
                }
            }
        }
    }

    std::cout << res;
}