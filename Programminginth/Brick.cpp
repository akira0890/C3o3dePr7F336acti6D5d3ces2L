#include <iostream>
#include <vector>

/*
at every input col keep highest position that can place '#'
then loop through brick number in each row and place '#' in that position , update highest position to that position - 1 repeat this process until brick number become 0
*/

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    int n,m,brick;
    std::cin >> n >> m;
    
    std::vector<int> top(m, n-1);
    std::vector<std::string> grid(n);

    for (int i = 0 ; i < n ; i++) {
        std::cin >> grid[i];
        const std::string &s = grid[i];

        for (int j = 0 ; j < m ; j++) {
            if (s[j] == 'O' && top[j] == n-1) {
                top[j] = i-1;
            }
        }
    }

    for (int i = 0 ; i < m ; i++) {
        std::cin >> brick;
        while (brick-- && top[i] >= 0) {
            grid[top[i]][i] = '#';
            top[i]--;
        }
    }

    for (std::string &s : grid) std::cout << s << '\n';
}