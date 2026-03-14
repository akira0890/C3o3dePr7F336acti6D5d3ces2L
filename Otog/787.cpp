#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,q,t,len; std::cin >> n >> m >> q;
    std::string s;

    std::unordered_map<std::string , std::vector<int>> map;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> s >> len;
        map[s].resize(m,0);
        for (int j = 0 ; j < len ; j++) {
            std::cin >> t;
            map[s][t-1]++;
        }
    }

    for (int i = 0 ; i < q ; i++) {
        std::cin >> s;
        for (int x : map[s]) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
}