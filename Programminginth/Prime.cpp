#include <iostream>

#define size 10'000'000

bool nprime[size];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    nprime[0] = true;
    nprime[1] = true;

    if (n == 1) {
        std::cout << 2;
        return 0;
    }
    n--;

    for (int i = 2 ; i*i < size ; i++) {
        if (!nprime[i]) {
            for (int j = i*i ; j < size ; j += i) {
                nprime[j] = true;
            }
        }
    }

    int i;
    for (i = 3 ; n > 0 ; i+=2) {
        if (!nprime[i]) n--;
    }

    std::cout << i-2;
}