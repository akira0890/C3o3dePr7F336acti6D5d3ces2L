#include <iostream>
#include <vector>

int dp[105][105];
int v[105];

int recursive(int l , int r , int i) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    if (i % 2 == 1) {
        return dp[l][r] = std::max(v[l] + recursive(l+1 , r , i+1) , v[r] + recursive(l , r-1 , i+1));
    } else {
        return dp[l][r] = std::max(recursive(l+1 , r , i+1) , recursive(l , r-1 , i+1));
    }
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for (int i = 0 ; i < n*2 ; i++) std::cin >> v[i];

    for (int i = 0 ; i < n*2 ; i++) {
        for (int j = 0 ; j < n*2 ; j++) {
            dp[i][j] = -1;
        }
    }

    int l = 0 , r = n*2-1;
    std::cout << recursive(l , r, 1);
}