#include <iostream>

#define ull unsigned long long

const int MOD = 1e9+7;
const int MAX = 1e6+5;

ull fact[1'000'005] , invfact[1'000'005];

ull power(ull base , ull exp) {
    ull res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1 ; i < MAX ; i++) fact[i] = (fact[i-1] * i) % MOD;

    invfact[MAX-1] = power(fact[MAX-1] , MOD - 2);

    for (int i = MAX - 2 ; i >= 0 ; i--) {
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
    }
}

ull nCr(int n, int k) {
    return (((fact[n] * invfact[k]) % MOD) * invfact[n-k]) % MOD;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k,q; std::cin >> q;

    precompute();

    while (q--) {
        std::cin >> n >> k;
        std::cout << nCr(n,k) << '\n';
    }
}