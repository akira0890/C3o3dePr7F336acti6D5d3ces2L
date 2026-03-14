#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);

    std::string s; std::cin >> s;

    int start = 0 , curr = 0, len = s.length();
    if (s[0] == '-') start = 1;

    for (int i = start ; i < (len + start)/2 ; i++) {
        std::swap(s[i], s[len - curr - 1]);
        curr++;
    }

    std::cout << s;
}