#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s; std::cin >> s;
    int ans = 1 , mul = 1;

    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == 'i') mul++;
        else if (s[i] == ')') ans *= mul , mul = 1;
    }
    ans *= mul;

    std::cout << ans;
}