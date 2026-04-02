#include <iostream>
#include <algorithm>
#include <vector>

#define pis std::pair<double , std::string>

struct Compare {
    bool operator()(const pis& a , const pis& b) {
        return a.first < b.first;
    }
};

struct Compare2 {
    bool operator()(const double& value , const pis& a) {
        return value < a.first;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n;

    std::vector<pis> v(n);

    double l,r;
    std::string s;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> l >> r >> s;
        v[i] = {r,s};
    }

    std::sort(v.begin() , v.end() , Compare());

    std::cin >> m;
    double target;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> target;
        auto it = std::upper_bound(v.begin() , v.end() , target , Compare2());

        std::cout << it->second << '\n';
    }
}