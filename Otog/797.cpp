#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s; std::cin >> s;
    std::string ans = "";

    int start = 0;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == ',') {
            ans += (char)(std::stoi(s.substr(start,i-start)));
            start = i+1;
        }
    }

    ans += (char)(std::stoi(s.substr(start , s.length()-start)));

    std::cout << ans;
}