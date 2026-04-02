#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    for (int i = n+1 ; i <= 9999 ; i++) {
        int freq[10] = {0,0,0,0,0,0,0,0,0,0};
        int m = i;
        while (m) {
            freq[m%10]++;
            m /= 10;
        }

        int maxs = 0;
        for (int i = 0 ; i < 10 ; i++) {
            maxs = std::max(maxs , freq[i]);
        }
        if (maxs == 1) {
            std::cout << i; break;
        }
    }
}