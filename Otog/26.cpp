#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::vector<std::unordered_set<int>> freq(n);

    int u,v;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v;
        freq[u-1].emplace(v);
    }

    for (int i = 0 ; i < n ; i++) {
        std::cout << i+1 << ' ' << freq[i].size() << '\n';
    }
}