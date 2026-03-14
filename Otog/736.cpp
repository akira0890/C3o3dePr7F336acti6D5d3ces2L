#include <iostream>
#include <stack>

int p[4] = {0,4,8,16};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s; std::cin >> s;

    std::stack<int> value , operation;

    for (int i = 0 ; i < s.size() ; i++) {
        if (isupper(s[i])) {
            value.emplace(20);
        } else if (isdigit(s[i])) {
            int curr = s[i] - '0';
            while (!operation.empty() && value.size() >= 2 && operation.top() >= curr) {
                int b = value.top(); value.pop();
                int a = value.top(); value.pop();
                int price = (b+a) + ((b+a) * p[operation.top()] / 100);
                value.emplace(price);
                operation.pop();
            }
            operation.emplace(curr);
        } else {
            if (s[i] == '[') operation.emplace(0);
            else {
                while (!operation.empty() && value.size() >= 2 && operation.top() != 0) {
                    int b = value.top(); value.pop();
                    int a = value.top(); value.pop();
                    int price = (b+a) + ((b+a) * p[operation.top()] / 100);
                    value.emplace(price);
                    operation.pop();
                }
                operation.pop();
            }
        }
    }

    while (!operation.empty() && value.size() >= 2) {
        int b = value.top(); value.pop();
        int a = value.top(); value.pop();
        int price = (b+a) + ((b+a) * p[operation.top()] / 100);
        value.emplace(price);
        operation.pop();
    }

    std::cout << value.top();
}