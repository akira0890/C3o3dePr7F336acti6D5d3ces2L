// #include <iostream>
// #include <vector>

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

//     int n,m; std::cin >> n >> m;

//     std::vector<std::vector<int>> v(n+1 , std::vector<int>(n+1));
//     std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(n+1,-1));

//     for (int i = 1 ; i <= n ; i++) {
//         for (int j = i ; j <= n ; j++) {
//             std::cin >> v[i][j];
//         }
//     }

//     for (int i = 0 ; i <= n ; i++) dp[0][i] = 0;

//     for (int k = 1 ; k <= m ; k++) {
//         for (int i = 1 ; i <= n ; i++) {
//             dp[k][i] = dp[k][i-1];
//             for (int j = 1 ; j <= i ; j++) {
//                 int prevJ = j-2;
//                 if (prevJ < 0) {
//                     if (k == 1) dp[k][i] = std::max(dp[k][i] , (long long)(v[j][i]));
//                 } else {
//                     if (dp[k-1][prevJ] != -1) {
//                         dp[k][i] = std::max(dp[k-1][prevJ] + (long long)v[j][i] , dp[k][i]);
//                     }
//                 }
//             }
//         }
//     }
                                           
//     long long res = -1;
//     for (int i = 1 ; i <= n ; i++) {
//         res = std::max(res , dp[m][i]);
//     }
//     std::cout << res;
// }


// #include <iostream>
// #include <vector>

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

//     int n,m; std::cin >> n >> m;

//     std::vector<std::vector<long long>> v(n+1 , std::vector<long long>(n+1));
//     for (int i = 1 ; i <= n ; i++) {
//         for (int j = i ; j <= n ; j++) {
//             std::cin >> v[i][j];
//         }
//     }

//     std::vector<std::vector<long long>> dp(m+1 , std::vector<long long>(n+1 , -1));

//     for (int i = 0 ; i <= n ; i++) dp[0][i] = 0;

//     for (int k = 1 ; k <= m ; k++) {
//         for (int i = 1 ; i <= n ; i++) {
//             dp[k][i] = dp[k][i-1];
//             for (int j = 1 ; j <= i ; j++) {
//                 int prev = j-2;
//                 if (prev < 0) {
//                     if (k == 1) dp[k][i] = std::max(dp[k][i] , v[j][i]);
//                 } else {
//                     if (dp[k-1][prev] != -1) {
//                         dp[k][i] = std::max(dp[k][i] , dp[k-1][prev] + v[j][i]);
//                     }
//                 }
//             }
//         }
//     }

//     long long res = -1;
//     for (int i = 1 ; i <= n ; i++) res = std::max(res , dp[m][i]);
//     std::cout << res;
// }

#include <iostream>
#include <vector>

int n,m;
long long dp[30][500];

std::vector<std::vector<long long>> v;

long long recursive(int k ,int i) {
    if (k == 0) return 0;
    if (i > n)  return -1e15;

    if (dp[k][i]) return dp[k][i];

    long long res;
    res = recursive(k , i+1);

    for (int j = i ; j <= n ; j++) {
        long long nextP = j + 2;

        res = std::max(res , v[i][j] + recursive(k-1 , nextP));
        // long long nextSum = recursive(k-1 , nextP);

        // if (nextSum > -1e14) {
        //     res = std::max(res , v[i][j] + nextSum);
        // }
    }

    return dp[k][i] = res;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;
    v.assign(n+1 , std::vector<long long>(n+1,0));

    for (int i = 1 ; i <= n ; i++) {
        for (int j = i ; j <= n ; j++) {
            std::cin >> v[i][j];
        }
    }

    std::cout << recursive(m , 1);

}