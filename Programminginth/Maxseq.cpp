/*
This problem is to find maximum subsequence with print that subsequence but if maximum subsequence is <= 0 then print Empty sequence

to solve this problem i use kadane's algorithm to find the answer but keep the index of the start of the sequence and end of the sequence
*/

#include <iostream>
#include <algorithm>
#include <climits>

int main() {
    int n,m, maxseq = INT_MIN, newsum = 0,start = 0, end = 0, maxstart, maxend;
    std::cin >> n;

    int val[n];
    for (int i = 0 ; i < n ; i++) {
        std::cin >> val[i];

        newsum = newsum + val[i];
        if (newsum < val[i]) {
            newsum = val[i];
            start = i;
            end = i;
        } else {
            end++;
        }

        if (newsum > maxseq) {
            maxseq = newsum;
            maxstart = start;
            maxend = end;
        }
    }
    if (maxseq <= 0) std::cout << "Empty sequence";
    else {
        for (int i = maxstart ; i <= maxend ; i++) std::cout << val[i] << ' ';
    
        std::cout << '\n' << maxseq;
    }
}