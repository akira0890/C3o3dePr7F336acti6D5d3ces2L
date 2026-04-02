#include <iostream>

const long long mod = 1e9 + 7;

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n;
    long long oper,a,b,currA = 1,currB = 0;
    char c;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> c >> oper;
        if (c == '+') {
            a = 1;
            b = oper;
        } else {
            a = oper;
            b = 0;
        }
        currA = (currA * a) % mod;
        currB = ((a * currB) % mod + b) % mod;
    }

    std::cin >> q;
    long long x;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> x;
        std::cout << ((currA * x) % mod + currB) % mod << '\n';
    }
}