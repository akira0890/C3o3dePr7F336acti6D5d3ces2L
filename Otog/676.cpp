#include <iostream>
#include <vector>
#include <algorithm>

int move[3][2] = {{-1,-1} , {-1,0} , {-1,1}};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<long long> v(3) , curr(3,0) , prev(3,0);

    for (int i = 0 ; i < 3 ; i++) std::cin >> prev[i];

    for (int i = 0 ; i < n-1 ; i++) {
        for (int j = 0 ; j < 3 ; j++) std::cin >> v[j];

        curr[0] = v[0] + std::max({prev[0] , prev[1]});
        curr[1] = v[1] + std::max({prev[0] , prev[1] , prev[2]});
        curr[2] = v[2] + std::max({prev[1] , prev[2]});

        std::swap(prev , curr);
    }

    std::cout << std::max({prev[0] , prev[1] , prev[2]});
}