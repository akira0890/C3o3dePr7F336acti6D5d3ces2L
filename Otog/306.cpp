#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<int> v(n) , dp(n,0);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    dp[0] = v[0];
    if (n > 1) dp[1] = v[1];

    for (int i = 2 ; i < n ; i++) {
        dp[i] = dp[i-1];
        for (int j = 0 ; j < i-1 ; j++) {
            dp[i] = std::max(dp[i] , dp[j] + v[i]);
        }
    }

    std::cout << dp[n-1];

}