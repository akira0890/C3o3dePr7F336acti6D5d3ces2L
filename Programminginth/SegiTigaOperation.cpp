#include <iostream>
#pragma GCC optimize("O3,unroll-loops,inline,fast-math")

int oper[3][3] = {
    {2,1,0},
    {2,1,1},
    {1,2,1}
};

unsigned char dp[255][255];
unsigned char pre[8][8];

void init_precompute() {
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            unsigned char res = 0;
            for (int a = 0 ; a < 3 ; a++) {
                if (i & (1 << a)) {
                    for (int b = 0 ; b < 3 ; b++) {
                        if (j & (1 << b)) {
                            res |= (1 << oper[a][b]);
                        }
                    }
                }
            }
            pre[i][j] = res;
        }
    }
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    init_precompute();

    for (int q = 0 ; q < 20 ; q++) {
        int length;
        std::string s;
        std::cin >> length >> s;

        for (int i = 0 ; i < length ; i++) {
            for (int j = 0 ; j < length ; j++) dp[i][j] = 0;
            dp[i][i] = (1 << (s[i] - '0')); // len1
        }

        for (int len = 2 ; len <= length ; len++) {
            for (int i = 0 ; i <= length - len ; i++) {
                int j = i + len - 1;
                for (int k = i ; k < j ; k++) {
                    dp[i][j] |= pre[dp[i][k]][dp[k+1][j]];

                    if (dp[i][j] == 7) break;
                }
            }
        }

        std::cout << (dp[0][length-1] & 1 ? "yes\n" : "no\n");
    }
}