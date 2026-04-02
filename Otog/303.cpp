#include <iostream>

long long dp[105][105];

long long recursive(int n , int k) {
    if (n == 0) return 1;
    if (k == 0) return 0;

    if (dp[n][k]) return dp[n][k];

    long long res;
    res = recursive(n , k-1);
    if (n-k >= 0) res += recursive(n-k,k);

    return dp[n][k] = res;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int target; std::cin >> target;
    
    std::cout << recursive(target , target);
}