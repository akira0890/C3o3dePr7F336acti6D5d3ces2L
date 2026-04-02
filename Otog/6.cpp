#include <iostream>
#include <string>

void sins(std::string &s , int n) {
    s += "sin(1";
    for (int i = 2 ; i <= n ;i++) {
        if (i%2 == 0) s+= '-';
        else s+='+';
        s+="sin(" + std::to_string(i);
    }
    s += std::string(n , ')');
}

std::string Sn(int n) {
    std::string ans = std::string(n-1 , '(');
    for (int i = 1 ; i < n ; i++) {
        sins(ans , i);
        ans += "+" + std::to_string(n-i+1) + ')';
    }
    sins(ans , n);
    ans += "+1";
    return ans;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::cout << Sn(n);
}