#include <iostream>
#include <algorithm>

int v[100];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int m,o,t, ans , sum = 0 , l=0,r;
    float avg;
    std::cin >> m >> o;

    std::cin >> v[0];
    for (int i = 1 ; i < o ; i++) {
        std::cin >> t;
        v[i] = t;
        sum += t;
        l = std::max(t,l);
    }

    r = sum;
    while (l <= r) {
        int mid = (l+r)/2;

        int n = 0 , sum = 0;
        for (int i = 0 ; i < o ; i++) {
            if (sum + v[i] > mid) {
                n++;
                sum = 0;
            }
            sum += v[i];
        }
        
        if (sum > 0) {
            n++;
        }

        if (n <= m) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << ans;
}