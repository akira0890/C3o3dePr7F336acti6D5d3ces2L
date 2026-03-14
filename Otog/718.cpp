#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,g,t; std::cin >> n >> g;

    std::vector<int> v(n+1);
    std::vector<std::vector<std::vector<int>>> dp(n+1 , std::vector<std::vector<int>>(g+1 , std::vector<int>(3,0)));

    for (int i = 1 ; i <= n ; i++) std::cin >> v[i];

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= g ; j++) {
            dp[i][j][0] = std::max({dp[i-1][j][0] , dp[i-1][j][1] , dp[i-1][j][2]});

            dp[i][j][1] = dp[i-1][j][0] + v[i];

            if (j > 0) {
                dp[i][j][2] = std::max({dp[i-1][j-1][0] , dp[i-1][j-1][1] , dp[i-1][j-1][2]}) + v[i];
            }
        }
    }

    int maxs = 0;
    for (int i = 0 ; i <= g ; i++) {
        maxs = std::max({maxs , dp[n][i][0] , dp[n][i][1] , dp[n][i][2]});
    }
    std::cout << maxs;
}