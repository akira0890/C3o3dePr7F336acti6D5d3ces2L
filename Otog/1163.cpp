#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

const long long INF = 1e15;
const int MAXS = 2e4+5;

long long wi[505] , vi[505];
long long prefixW[505] , prefixV[505];
long long dp[505][MAXS];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    long long a,b;
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> wi[i] >> vi[i];
        prefixW[i] = prefixW[i-1] + wi[i];
        prefixV[i] = prefixV[i-1] + vi[i];
        // dp[i+1][wi[i]] = std::min(dp[i+1][wi[i]] , vi[i]);
    }

    for (int j = 1 ; j < MAXS ; j++) dp[n+1][j] = INF;
    dp[n+1][0] = 0;

    for (int i = n ; i >= 1 ; i--) {
        for (int w = 0 ; w < MAXS ; w++) {
            dp[i][w] = dp[i+1][w];

            int prev = std::max(0LL , w - wi[i]);
            if (dp[i+1][prev] != INF) {
                dp[i][w] = std::min(dp[i][w] , vi[i] + dp[i+1][prev]);
            }
        }
    }

    int q,x,w; std::cin >> q;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> x >> w;
        
        long long wantW = prefixW[x];
        long long wantV = prefixV[x];

        long long remain = std::max(0LL,w - wantW);
        if (remain >= MAXS) std::cout << "-1\n";
        else {
            if (dp[x+1][remain] >= INF) std::cout << "-1\n";
            else std::cout << wantV + dp[x+1][remain] << '\n';
        }
    }
}