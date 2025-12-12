#include <iostream>
#include <queue>
#include <functional>

/*
The Problem is to get highest value at the currect time when cmd is 'Q' so i use data structure like priority queue to store the highest value at that current time
when cmd is 'P' : get the value and then push it in the priority queue
when cmd is 'Q' : if there is no value in the priority queue print -1 but if priority queue isn't empty print the highest value at that current time and pop it from the priority queue
*/

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    int n,temp;
    std::cin >> n;

    char cmd;
    while (n--) {
        std::cin >> cmd;
        if (cmd == 'P') {
            std::cin >> temp;
            pq.emplace(temp);
        } else {
            if (pq.empty()) std::cout << "-1\n";
            else std::cout << pq.top() << '\n', pq.pop();
        }
    }
}