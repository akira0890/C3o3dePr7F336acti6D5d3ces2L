#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    unsigned long long sum = 0;
    std::vector<unsigned long long> v;
    while (std::cin >> sum) {
        v.emplace_back(sum);
    }

    if (v.empty()) {
        std::cout << 0;
        return 0;
    }

    int cnt = 0 , curr = v.size()-1;
    while (curr >= 0) {
        cnt++;
        curr -= v[curr];
    }

    std::cout << cnt;
}