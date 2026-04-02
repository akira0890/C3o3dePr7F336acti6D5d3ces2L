#include <iostream>
#include <unordered_map>
#include <algorithm>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::unordered_map<std::pair<std::string , int> , int , pair_hash> v;
    std::string s;
    long long value;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> s >> value;
        v[{s , value}] = i;
    }

    int m , found = 0 , even = 0;
    std::cin >> m;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> s >> value;
        if (v.find({s , value}) != v.end()) {
            found++;
            if (value % 2 == 0) even++;
        }

    }

    std::cout << found << ' ' << even;
}