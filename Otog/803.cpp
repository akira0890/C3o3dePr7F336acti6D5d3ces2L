#include <iostream>
#include <vector>

#define MOD 10'000'009

int dp[201][201][1501];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k; std::cin >> n >> m >> k;
    int mx[2] = {0,1} , my[2] = {1,0};

    std::vector<std::string> grid(n);
    for (int i = 0 ; i < n ; i++) std::cin >> grid[i];

    if (grid[0][0] == '#') {
        std::cout << '0';
        return 0;
    }

    if (grid[0][0] == 'X') {
        if (1 <= k) dp[0][0][1] = 1;
        else { std::cout << 0; return 0; }
    } else {
        dp[0][0][0] = 1;
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            for (int p = 0 ; p <= k ; p++) {
                if (dp[i][j][p] != 0) {
                    for (int l = 0 ; l < 2 ; l++) {
                        int ny = i + my[l];
                        int nx = j + mx[l];

                        if (ny < n && nx < m) {
                            if (grid[ny][nx] == '.') {
                                dp[ny][nx][p] = (dp[ny][nx][p] + dp[i][j][p]) % MOD;
                            } else if (grid[ny][nx] == 'X' && p+1 <= k) {
                                dp[ny][nx][p+1] = (dp[ny][nx][p+1] + dp[i][j][p]) % MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0 ; i <= k ; i++) {
        sum = (sum + dp[n-1][m-1][i]) % MOD;
    }
    std::cout << sum;
}

/*
.X.
..X
#..

100
11-1
111

111
120
000
*/