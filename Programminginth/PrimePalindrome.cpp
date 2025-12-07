#include <iostream>

const int MAXN = 1'500'000;
bool isprime[MAXN + 1];

inline bool npalindrome(int n) {
    int m = 0,temp = n;
    while (n!=0) {
        m = m*10 + (n % 10);
        n /= 10;
    }
    return temp != m;
}

int main() {
    for (bool &x : isprime) x = true;
    for (int i = 2 ; i*i <= MAXN ; i++) {
        if (isprime[i]) {
            for (int j = i * i ; j <= MAXN ; j+=i) isprime[j] = false;
        }
    }

    int n;
    std::cin >> n;

    while (!isprime[n] || npalindrome(n)) n++;
    std::cout << n;
    return 0;
}