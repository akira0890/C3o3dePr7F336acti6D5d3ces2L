#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k; std::cin >> n >> k;
    std::unordered_set<int> sorted;

    std::vector<int> v(n+2,0);
    for (int i = 1 ; i <= n ; i++) std::cin >> v[i];

    for (int i = 1 ; i <= n ; i++) {
        if (v[i] > v[i-1] && v[i] > v[i+1]) { 
            sorted.emplace(v[i]);
        }
    }

    std::vector<int> sorts;
    for (int x : sorted) sorts.emplace_back(x);
    std::sort(sorts.begin() , sorts.end());

    if (sorts.size() < k) {
        if (sorts.size() == 0) std::cout << "-1";
        else {
            for (int i = 0 ; i < sorts.size() ; i++) {
                std::cout << sorts[i] << '\n';
            }
        }
    } else {
        int count = 0;
        for (int i = sorts.size()-1 ; i >= 0 && count < k ; i-- , count++) {
            std::cout << sorts[i] << '\n';
        }
    }

    return 0;
}