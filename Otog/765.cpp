#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;
    std::vector<int> row(n) , col(m);

    long long ans = 0;
    for (int i = 0 ; i < n ; i++) std::cin >> row[i] , ans += row[i];
    for (int i = 0 ; i < m ; i++) std::cin >> col[i] , ans += col[i];

    ans -= col[0];

    for (int i = 0 ; i < n-1 ; i++) {
        for (int j = 1 ; j < m ; j++) {
            ans += std::min(row[i] , col[j]);
        }
    }

    std::cout << ans;
}

/*
02222
13323
24423
  423
  012
 */