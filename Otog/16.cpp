#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int start = 0 , end = 0;
    int maxStart = -1, maxEnd = -1;
    int sum = 0;
    int maxsum = -10000000;
    for (int i = 0 ; i < n ; i++) {
        if (sum + v[i] < v[i]) {
            sum = v[i];
            start = i;
        } else {
            sum += v[i];
        }

        if (maxsum < sum) {
            maxStart = start;
            maxEnd   = i;
            maxsum = sum;
        }
    }

    if (maxsum <= 0) std::cout << "Empty sequence";
    else {
        for (int i = maxStart ; i <= maxEnd ; i++) std::cout << v[i] << ' '; std::cout << '\n';
        std::cout << maxsum; 
    }
}