#include <iostream>
#include <set>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k,t , ans = 0; std::cin >> n >> k;
    std::set<int> ischeck;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> t;
        int mod = t % k;
        if (ischeck.find(mod) == ischeck.end()) {
            ans++;
            ischeck.emplace(mod);
        }
    }

    std::cout << ans << '\n';
    for (auto it = ischeck.begin() ; it != ischeck.end() ; it++) {
        std::cout << *it << '\n';
    }
}