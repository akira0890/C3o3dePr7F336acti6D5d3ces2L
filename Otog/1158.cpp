#include <iostream>

long long findMissing(int N) {
    long long sum = query(0,N-1);
    long long realSum = (N)*(N-1) / 2;
    return realSum - sum;
}