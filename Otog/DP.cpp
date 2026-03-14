#include <iostream>
#include <vector>

#define MAX 10000

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string a,b; std::cin >> a >> b;

    std::vector<std::vector<int>> dp(a.length()+1 , std::vector<int>(b.length()+1,0));

    for (int i = 1 ; i <= a.length() ; i++) {
        for (int j = 1 ; j <= b.length() ; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = std::max(dp[i][j-1] , dp[i-1][j]);
        }
    }

    std::cout << dp[a.length()][b.length()];

}