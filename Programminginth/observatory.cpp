#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k,t,ans = INT_MIN;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> prefix(n+2, std::vector<int>(m+2,0));

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            std::cin >> t;
            prefix[i][j] = prefix[i-1][j-1]+t;
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            std::cout << prefix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    // for (int i = 0 ; i < n-k ; i++) {
    //     for (int j = 1 ; j <= m-k ; j++) {
    //         int sum1 = 0, sum2;
    //         for (int l = 0 ; l < k ; l++) sum1 += prefix[i+l][j+l] - prefix[i+l][j-1];
    //         for (int l = 0 ; l < k ; l++) sum2 += prefix[i+l][j+k] - prefix[i+l][j+k-l-1];
    //         ans = std::max({ans,sum1,sum2});
    //     }
    // }
    // std::cout << ans;
}