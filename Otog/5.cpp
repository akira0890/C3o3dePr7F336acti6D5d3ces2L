#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long n , count = 0 , use = 0; std::cin >> n;
    long long i = 1;

    while (n > 0) {
        int remainder = n % 3;

        if (remainder == 1 || remainder == 2) count++;

        if (remainder == 1) {
            use += i;
            n /= 3;
        } else if (remainder == 2) {
            n = (n/3)+1;
        } else {
            n /= 3;
        }
        i*=3;
    }

    std::cout << count << ' ' << use;

    return 0;
}