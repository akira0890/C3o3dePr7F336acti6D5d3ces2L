#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n+1);

    int u,v;
    for (int i = 0 ; i < n-1 ; i++) {
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<bool> visited(n+1,false);

    int curr = 1;
    visited[curr] = true;
    while (g[curr].size() == 2) {
        if (!visited[g[curr][0]]) {
            curr = g[curr][0];
            visited[curr] = true;
        } else {
            curr = g[curr][1];
            visited[curr] = true;
        }
    }

    for (int i = 0 ; i <= n ; i++) visited[i] = false;

    visited[curr] = true;
    curr = g[curr].front();

    int move = n/2;
    for (int i = 1 ; i < move ; i++) {
        if (!visited[g[curr][0]]) {
            visited[curr] = true;
            curr = g[curr][0];
        } else {
            visited[curr] = true;
            curr = g[curr][1];
        }
    }

    std::cout << curr;
}