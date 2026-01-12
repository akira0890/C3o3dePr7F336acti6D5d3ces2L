/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    - - - - -
  - - -
- - -
            - -
              - - --
                - -- -- -- -- -- --
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/

/*
Method 2 a little faster 100ms and less memory

Solution:
first store information in start, end, index format call require and sort it
use min heap to track lowest end time
for each require check until min heap is empty or start is <= min heap
check is current min heap size is lower than k if yes mark it as Y else mark it as N
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct require {
    int s, f, ind;
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    int n,k,m,start,end;
    std::cin >> n >> k >> m;

    std::vector<require> Require(n);
    std::vector<char> mark(n);

    for (int i = 0 ; i < n ; i++) {
        std::cin >> start >> end;
        Require[i] = {start, end, i};
    }

    std::sort(Require.begin(), Require.end(), [](const require& A, const require& B){
        return A.s < B.s;
    });

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (require &req : Require) {
        while (!pq.empty() && pq.top() < req.s) {
            pq.pop();
        }

        if (pq.size() < k) {
            pq.emplace(req.f);
            mark[req.ind] = 'Y';
        } else {
            mark[req.ind] = 'N';
        }
    }

    for (int i = 0 ; i < m ; i++) {
        std::cin >> start;
        std::cout << mark[start-1] << ' ';
    }
}

/*
Method 1 Slow than method 2.

Solution:
Using sweep line algorithm keep input information (position, start or end(1,-1), index) and sort that by if position is equal then let end1 be first and end-1 last and sort by position
for each that information and check if end is 1 then check if current signal is lower than maximum signal then mark it as can be use signal and increase current signal else mark sa can't use signal
else if that signal is used remove that signal 
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
//     int n,k,m,start,end;
//     std::cin >> n >> k >> m;

//     int curr = 0;
//     std::vector<std::pair<std::pair<int,int>, int>> info(n*2);
//     std::vector<bool> canuse(n);

//     for (int i = 0 ; i < n ; i++) {
//         std::cin >> start >> end;
//         info[i*2] = {{start,1},i};
//         info[i*2+1] = {{end,-1},i};
//     }

//     std::sort(info.begin(), info.end(), [](const std::pair<std::pair<int,int>, int>& A, const std::pair<std::pair<int,int>, int>& B){
//         if (A.first.first == B.first.first) return A.first.second > B.first.second;
//         return A.first.first < B.first.first;
//     });

//     for (auto [in, i] : info) {
//         auto [t , inc] = in;
//         if (inc == 1) {
//             if (curr < k) {
//                 canuse[i] = true;
//                 curr++;
//             } else {
//                 canuse[i] = false;
//             }
//         } else if (canuse[i]) curr--;
//     }

//     for (int i = 0 ; i < m ; i++) {
//         std::cin >> start;
//         std::cout << (canuse[start-1]?'Y':'N') << ' ';
//     }
// }