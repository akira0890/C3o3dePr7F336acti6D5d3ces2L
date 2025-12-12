#include <iostream>
#include <algorithm>

std::pair<int,int> pairs[1'000'000];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    int n,maxy = 0, prex = 0, premaxy = 0;
    std::cin >> n;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> pairs[i].first >> pairs[i].second;
    }

    std::sort(pairs, pairs + n, [](auto &a, auto &b){
        if (a.first != b.first) return a.first > b.first;
        else return a.second > b.second;
    });

    for (int i = 0 ; i < n ; i++) {
        auto [x,y] = pairs[i];
        if (x != prex) {
            maxy = premaxy;
            prex = x;
        }
        if (y >= maxy) {
            std::cout << x << ' ' << y << '\n';
        }
        premaxy = std::max(premaxy, y);
    }
}

// need to add condition for max x and max y to make it work

// #include <iostream>

// int pairs[1'000'000][2];

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
//     int n,maxpaira = 0,maxpairb = 0;
//     std::cin >> n;

//     for (int i = 0 ; i < n ; i++) {
//         std::cin >> pairs[i][0] >> pairs[i][1];
//         if (pairs[i][0] >= maxpaira && pairs[i][1] >= maxpairb) {
//             maxpaira = pairs[i][0];
//             maxpairb = pairs[i][1];
//         }
//     }

//     for (int i = 0 ; i < n ; i++) {
//         if (!(pairs[i][0] < maxpaira && pairs[i][1] < maxpairb)) std::cout << pairs[i][0] << ' ' << pairs[i][1] << '\n';
//     }
// }