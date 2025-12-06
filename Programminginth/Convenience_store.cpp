#include <iostream>

const int mod = 1e6+7;
int dp[500];

int main() {
    int n,m;
    int cost[500];
    std::cin >> n >> m;

    for (int i = 0 ; i < n ; i++) std::cin >> cost[i];

    dp[0] = 1;

    for (int i = 0 ; i < n ; i++) {
        for (int j = m ; j >= cost[i] ; j--) {
            dp[j] += dp[j - cost[i]];
            dp[j] %= mod;
        }
    }

    std::cout << cost[m];
}