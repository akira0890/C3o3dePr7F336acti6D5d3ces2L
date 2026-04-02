#include <iostream>
#include <vector>

std::vector<long long> sizes;

void recursive(const std::vector<std::vector<int>> &v , std::vector<bool> &visited , int curr ) {
    int s = 0;
    for (int i = 0 ; i < v[curr].size() ; i++) {
        if (visited[v[curr][i]]) s++;
    }
    if (v[curr].size() == s) {
        sizes[curr] = 1;
        return;
    }

    for (int i = 0 ; i < v[curr].size() ; i++) {
        if (!visited[v[curr][i]]) {
            visited[v[curr][i]] = true;
            recursive(v , visited , v[curr][i]);
            sizes[curr] += sizes[v[curr][i]];
        }
    }
    sizes[curr] += 1;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    
    int n; std::cin >> n;
    sizes.resize(n,0);
    std::vector<std::vector<int>> g(n);
    std::vector<bool> visited(n , false);

    int u,v;
    for (int i = 0 ; i < n-1 ; i++) {
        std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    visited[0] = true;
    recursive(g , visited , 0);

    for (int i = 0 ; i < n ; i++) std::cout << sizes[i] << ' ';
}