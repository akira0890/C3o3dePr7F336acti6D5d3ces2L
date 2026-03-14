#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::string s, ori;
    
    std::cin >> s;
    ori = s;

    std::string temp;
    for (int i = 1 ; i <= n ; i++) {
        temp.push_back(s[n-1]);
        s.pop_back();
        temp += s;
        if (temp == ori) {
            std::cout << i;
            break;
        }
        s = temp;
        temp = "";
    }
}