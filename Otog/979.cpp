#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Node {
    int a , b , c;
};

int main () {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k; std::cin >> n >> k;
    std::vector<Node> v(n);

    for (int i = 0 ; i < n ; i++) {
        std::cin >> v[i].a >> v[i].b >> v[i].c;
    }

    double ans = 0 , l = 0 , r = 1;

    for (int iter = 0 ; iter < 100 ; iter++) {
        double mid = l + (r - l) / 2.0;
        double sum = 0;
        for (int i = 0 ; i < n ; i++) {
            sum += mid * v[i].a + std::pow(mid , v[i].b) + std::pow(mid , v[i].c);
        }

        if (sum >= k) {
            if ((double)((int)(sum*100))/100 == k) {
                std::cout << std::round(mid*10000)/100.0;
                return 0;
            }
            r = mid;
        } else {
            l = mid;
        }
    }

    // std::cout << std::fixed << std::setprecision(2) << l*100;
    // std::cout << l*100;

}