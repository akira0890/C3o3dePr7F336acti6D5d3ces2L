#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<int> v(n) , dp(n+1,INT_MAX);
    dp[1] = 0;

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    for (int i = 1 ; i <= n ; i++) {
        if (i+1 <= n) dp[i+1] = std::min(dp[i+1] , dp[i]+1);
        if (i + v[i-1] <= n) dp[i+v[i-1]] = std::min(dp[i+v[i-1]] , dp[i]+1);
    }
    std::cout << dp[n];
}