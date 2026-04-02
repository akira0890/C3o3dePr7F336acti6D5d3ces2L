#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::vector<int> tail;
    tail.emplace_back(v[0]);
    for (int i = 1 ; i < n ; i++) {
        if (v[i] >= tail.back()) {
            tail.emplace_back(v[i]);
        } else {
            auto it = std::lower_bound(tail.begin() , tail.end() , v[i]);
            *it = v[i];
        }
    }

    std::cout << n - tail.size() << '\n';
}