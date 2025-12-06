#include <iostream>
#include <algorithm>
// #include <cmath>
// #include <iomanip>

// int main() {
//     int n,m;
//     std::scanf("%d",&n);

//     while (n--) {
//         std::scanf("%d", &m);
//         std::printf("%.0Lf\n", powl(2,m));
//     }
// }

// std::string mul2(std::string& num) {
//     std::string ans;
//     ans.reserve(num.size() + 1);

//     int remain = 0;
//     for (int i = num.length()-1 ; i >= 0 ; i--) {
//         int val = (num[i]-'0') * 2 + remain;
//         remain = val / 10;
//         ans.push_back((val%10)+'0');
//     }

//     if (remain != 0) ans.push_back((remain+'0'));

//     std::reverse(ans.begin() , ans.end());

//     return ans;
// }

// int main() {
//     int n,m;
//     std::cin >> n;

//     std::string ans[215];
//     ans[0] = "1";

//     std::string num = "1";
//     for (int i = 1 ; i <= 214 ; i++) {
//         num = mul2(num);
//         ans[i] = num;
//     }

//     for (int i = 0 ; i < n ; i++) {
//         std::cin >> m;
//         std::cout << ans[m] << '\n';
//     }
// }

std::string mul2(const std::string& num) {
    std::string ans;
    ans.reserve(num.size() + 1);

    int carry = 0;
    for (int i = num.size() - 1; i >= 0; --i) {
        int val = (num[i] - '0') * 2 + carry;
        carry = val / 10;
        ans.push_back(char('0' + (val % 10)));
    }

    if (carry) ans.push_back(char('0' + carry));
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int Q;
    std::cin >> Q;

    static std::string ans[216];
    ans[0] = "1";

    for (int i = 1; i <= 215; ++i)
        ans[i] = mul2(ans[i - 1]);

    while (Q--) {
        int n;
        std::cin >> n;
        std::cout << ans[n] << '\n';
    }
}