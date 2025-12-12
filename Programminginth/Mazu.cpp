#include <iostream>
#include <stack>

/*
The problem is to pop all current adjacent character and print in reverse.
from the problem pop last element of array if it the same character and print in reverse. This is stack.
So to solve this i loop n time and check if stack is empty and on top of stack is the same character of current character input. if it is then pop the top element of the stack
if isn't then push that character into the stack. after process all the element, print the stack information.
*/

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    std::stack<char> st;
    int n;
    std::cin >> n;

    char c;
    while (n--) {
        std::cin >> c;
        if (!st.empty() && st.top() == c) st.pop();
        else st.emplace(c);
    }

    std::cout << st.size() << '\n';
    if (st.empty()) std::cout << "empty";
    else while (!st.empty()) std::cout << st.top(), st.pop();
}