#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k; std::cin >> n >> m >> k;

    std::vector<std::string> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::string s;
    std::cin >> s;

    int y = 0 , x = 0;
    for (int i = 0 ; i < s.length() ; i++) {
        switch (s[i]) {
        case 'D':
            y++;
            break;
        case 'R':
            x++;
            break;
        case 'U':
            y--;
            break;
        case 'L':
            x--;
            break;
        default:
            break;
        }
    }

    std::cout << v[y][x];
}