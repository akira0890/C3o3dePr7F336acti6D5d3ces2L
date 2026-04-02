#include <iostream>
#include <vector>

int dp[1005][1005];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string a,b; std::cin >> a >> b;

    for (int i = 1 ; i <= a.length() ; i++) {
        for (int j = 1 ; j <= b.length() ; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = std::max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    std::cout << dp[a.length()][b.length()] << ' ' << std::max(a.length() , b.length());
}