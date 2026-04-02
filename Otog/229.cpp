#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::string s;
    s += std::string(n , '(');
    s += std::string(n , ')');

    std::vector<std::string> ans;
    ans.emplace_back(s);

    int count = 0;
    for (int len = 1 ; len < n-1 ; len++) {
        
        for (int i = n+1 ; i > 0 ; i--) {

        }
    }
}


/*
000111
001011
010011
001101
010101

0011
0101
(())
()()
*/