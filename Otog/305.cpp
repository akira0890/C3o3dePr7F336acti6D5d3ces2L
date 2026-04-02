#include <iostream>

std::string a,b;
int dp[505][505];
int recursive(int u , int v) {
    if (u < 0 || v < 0) return 0;

    if (dp[u][v]) return dp[u][v];

    int res;
    if (a[u] == b[v]) res = 1 + recursive(u-1 , v-1);
    else res = std::max(recursive(u,v-1) , recursive(u-1,v));

    return dp[u][v] = res;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    dp[0][0] = 0;
    std::cin >> a >> b;
    std::cout << recursive(a.length() , b.length()) - 1;
}