#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int x , y , z; std::cin >> x >> y >> z;

    std::vector<long long> v(x+2,0);
    std::vector<std::pair<int,int>> cord(y+1);

    int a,b;
    for (int i = 1 ; i <= y ; i++) {
        std::cin >> cord[i].first >> cord[i].second;
    }

    for (int i = 0 ; i < z ; i++) {
        std::cin >> a;
        v[cord[a].first] += 1;
        v[cord[a].second+1] -= 1;
    }

    std::cout << v[1] << '\n';
    for (int i = 2 ; i <= x ; i++) {
        v[i] += v[i-1];
        if (v[i] >= 0) std::cout << v[i] << '\n';
        else std::cout << 0 << '\n';
    }
}