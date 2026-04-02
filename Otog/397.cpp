#include <iostream>
#include <unordered_map>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k,t , ans = 0; std::cin >> n >> k;
    std::unordered_map<int , bool> ischeck;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> t;
        int mod = t % k;
        if (ischeck.find(mod) == ischeck.end()) ans++;
        ischeck[mod] = true;
    }

    std::cout << ans;
}