#include <iostream>
#include <vector>

long long sum[100005];
long long gcdSum[100005];

inline int gcd(int a , int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n >> q;
    std::vector<long long> v(n+1);

    for (int i = 1 ; i <= n ; i++) {
        std::cin >> v[i];
    }

    for (int i = 1 ; i <= n ; i++) {
        if (n % i == 0) {
            gcdSum[i] = 0;
            for (int j = i ; j <= n ; j += i) {
                gcdSum[i] += v[j];
            }
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        sum[i] = gcdSum[gcd(i,n)]*(long long)i;
    }

    int target;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> target;
        long long ans = -1;
        int idx = 1;
        for (int j = 1 ; j <= target ; j++) {
            if (sum[j] >= ans) {
                ans = sum[j];
                idx = j;
            }
        }
        std::cout << idx << ' ' << ans << '\n';
    }
}