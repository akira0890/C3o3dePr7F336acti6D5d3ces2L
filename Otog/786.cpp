// #include <iostream>
// #include <cmath>

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

//     float n,m,t; std::cin >> n >> m;

//     float maxP = 0;
//     for (int i = 0 ; i < n ; i++) {
//         std::cin >> t;
//         maxP = std::max(maxP , t);
//     }

//     for (int i = 0 ; i < n ; i++) {
//         std::cin >> t;
//         std::cout << ceil(t/maxP) << '\n';
//     }
// }

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int max_a = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp > max_a) max_a = temp;
    }

    for (int i = 0; i < m; i++) {
        long long b;
        cin >> b;
        if (b == 0) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = (b + max_a - 1) / max_a;
        cout << ans << "\n";
    }

    return 0;
}