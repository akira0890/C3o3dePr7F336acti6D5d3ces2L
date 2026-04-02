#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<std::vector<int>> dp(n ,std::vector<int>(n,0));
    std::vector<char> c(n);

    for (int i = 0 ; i < n ; i++) std::cin >> c[i];

    for (int length = 2 ; length <= n ; length++) {
        for (int l = 0 ; l + length <= n ; l++) {
            int r = l + length - 1;
            dp[l][r] = dp[l+1][r-1] + (c[l] == c[r]);
            for (int k = l ; k < r ; k++) {
                dp[l][r] = std::max(dp[l][r] , dp[l][k] + dp[k+1][r]);
            }
        }
    }

    // for (int i = 0 ; i < n ; i++) {
    //     for (int j = 0 ; j < n ; j++) {
    //         std::cout << dp[i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }

    std::cout << dp[0][n-1];
}
