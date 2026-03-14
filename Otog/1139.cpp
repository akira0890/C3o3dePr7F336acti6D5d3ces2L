#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define LLMin -1e17

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,t; std::cin >> n;
    std::vector<long long> v(n+1,0);

    int nk = std::sqrt(2*n)+5;

    for (int i = 1 ; i <= n ; i++) std::cin >> t , v[i] = v[i-1] + (long long)t;

    std::vector<std::vector<long long>> dp(n+1 , std::vector<long long>(nk+1, LLMin));
    dp[1][1] = 0;

    std::vector<long long> dp_prev(n + 1, LLMin);
    std::vector<long long> dp_curr(n + 1, LLMin);

    dp_prev[1] = 0;
    long long max_ans = 0;

    for (int k = 1; k < nk; k++) {
        fill(dp_curr.begin(), dp_curr.end(), LLMin);

        for (int i = 1; i <= n; i++) {
            if (k > 1) {
                int prev_i = i - (k - 1);
                if (prev_i >= 1 && dp_prev[prev_i] > LLMin) {
                    long long score_between = v[i - 1] - v[prev_i];
                    dp_curr[i] = std::max(dp_curr[i], dp_prev[prev_i] + score_between);
                }
            } else if (k == 1 && i == 1) {
                dp_curr[1] = 0;
            }

            if (i > 1 && dp_curr[i - 1] > LLMin) {
                dp_curr[i] = std::max(dp_curr[i], dp_curr[i - 1]);
            }

            // --- เช็กกรณี "ถึงเส้นชัย" หรือ "โดดเลยเส้นชัย" ---
            if (dp_curr[i] > LLMin) {
                if (i == n) {
                    max_ans = std::max(max_ans, dp_curr[i]);
                }
                // ถ้าโดดครั้งถัดไป (ระยะ k) แล้วจะเลยเส้นชัย
                int next_target = i + k;
                if (next_target > n) {
                    long long score_to_end = v[n] - v[i];
                    max_ans = std::max(max_ans, dp_curr[i] + score_to_end);
                }
            }
        }
        // สลับแถวเพื่อคำนวณ k ถัดไป
        dp_prev = dp_curr;
    }

    std::cout << max_ans;

}