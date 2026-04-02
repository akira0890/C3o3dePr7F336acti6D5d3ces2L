#include <iostream>


unsigned long long dp[100000];

unsigned long long fibo(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;

    if (dp[n] != 0) return dp[n];

    return dp[n] = fibo(n-1) + fibo(n-2);
}

int main() {
    int n; std::cin >> n;

    std::cout << fibo(n);

    // dp[1] = 1;
    // dp[2] = 1;

    // for (int i = 2 ; i <= n ; i++) {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }

    // std::cout << dp[n];
}