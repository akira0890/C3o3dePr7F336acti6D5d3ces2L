#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::vector<int> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::string Eat; std::cin >> Eat;

    int l = 0 , r = n-1;
    int ans = 0;
    for (int i = 0 ; i < Eat.length() ; i++) {
        if (Eat[i] == 'L') ans += v[l] , l++;
        else ans += v[r] , r--;
    }

    std::cout << ans;
}