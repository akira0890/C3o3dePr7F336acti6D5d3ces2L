#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> v(n) , prefix(n,0) , suffix(n,0);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];
}


/*

*/