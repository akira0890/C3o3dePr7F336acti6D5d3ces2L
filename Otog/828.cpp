#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    unsigned long long change = 0 , sum = v[0] + v[n-1];
    for (int i = 1 ; i < n-1 ; i++) {
        unsigned long long avg = (v[i-1] + v[i] + v[i+1])/3;
        if (avg > v[i]) change++ , sum += avg;
        else sum += v[i];
    }
    std::cout << change << ' ' << sum;
}