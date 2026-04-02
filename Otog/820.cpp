#include <iostream>
#include <vector>

const int mod = 1'000'003;
const int offset = 900;

int q1[1805][1805] , q2[1805][1805];
int v[1805][1805];
int fac[1205][605];

void prepare() {
    fac[0][0] = 1;
    for (int i = 1 ; i <= 1200 ; i++) {
        fac[i][0] = 1;
        for (int j = 1 ; j <= std::min(i,600) ; j++) {
            fac[i][j] = (fac[i-1][j-1] + fac[i-1][j]) % mod;
        }
    }
}

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    prepare();

    int r,c,K; std::cin >> r >> c >> K;
    char ch;
    for (int i = 901 ; i <= r+900 ; i++) {
        for (int j = 901 ; j <= c+900 ; j++) {
            std::cin >> ch;
            if (ch == '#') v[i][j] = 1;
        }
    }

    for (int i = 1 ; i <= 1800 ; i++) {
        for (int j = 1 ; j <= 1800 ; j++) {
            q1[i][j] = v[i][j] + q1[i-1][j-1];
        }
    }

    for (int i = 1802 ; i >= 1 ; i--) {
        for (int j = 1 ; j <= 1802 ; j++) {
            q2[i][j] = v[i][j] + q2[i+1][j-1];
        }
    }

    int sum = 0;
    for (int i = 901 ; i <= r+900 ; i++) {
        for (int j = 901 ; j <= c+900 ; j++) {
            for (int k = 1 ; k <= r + c ; k++) {
                int count = 0;
                count += q2[i+1][j+k-1] - q2[i+k][j];
                count += q2[i-k+1][j-1] - q2[i][j-k];
                count += q1[i][j+k] - q1[i-k-1][j-1];
                count += q1[i+k][j] - q1[i-1][j-k-1];
                
                if (count >= K) sum = (sum + (fac[count][K])) % mod;
            }
        }
    }

    std::cout << sum;
}