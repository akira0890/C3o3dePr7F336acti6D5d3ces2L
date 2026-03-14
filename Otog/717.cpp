#include <iostream>
#include <vector>

inline int gcd(int n,int m) {
    while (m) {
        int remain = n%m;
        n = m;
        m = remain;
    }
    return n;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int q,n; std::cin >> q;

    while (q--) {
        std::cin >> n;

        int result = 1;
        std::vector<int> ans = {1};
        for (int i = 2 ; i < n ; i++) {
            if (gcd(n , i) == 1) result++ , ans.emplace_back(i);
        }

        std::cout << result << '\n';
        for (int i : ans) std::cout << i << ' ';
        std::cout << '\n';
    }
}