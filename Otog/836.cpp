#include <iostream>

const long long mod = 1e9+7;

inline long long powers(long long base , long long exp) {
    long long res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

inline long long modInverse(long long n) {
    return powers(n , mod-2);
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int q;
    std::cin >> q;
    for (int i = 0 ; i < q ; i++) {
        long long x; std::cin >> x;
        x %= mod;
        long long x2 = (x*x) % mod;
        long long x3 = (x2*x)%mod;

        long long f = (x3 - (6*x2)%mod - 6) % mod;
        long long g = (x2 - (3*x) %mod + 2) % mod;
        if (g == 0) std::cout << "NO\n";
        else {
            long long res = (f * modInverse(g)) % mod;
            std::cout << res << '\n';
        }
    }
}