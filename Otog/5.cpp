#include <iostream>

int main() {
    int leftsum = 0,rightsum = 0,i=1,n,m=0;
    std::cin >> n;
    leftsum = n;

    int templeftsum;
    while (leftsum > rightsum) {
        i=1;
        rightsum = 0;
        templeftsum = 0;
        m = 0;
        while (leftsum!=0) {
            if (leftsum%3==1) {
                rightsum += i;
                m++;
            } else if (leftsum%3==2) {
                templeftsum += i;
            }
            leftsum/=3;
            i*=3;
        }

        if (rightsum > n) {
            int temp = rightsum - n;
            while (temp != 0) {
                if (temp%3==1) m++;
                temp/=3;
            }
        }
        leftsum = templeftsum + n;
    }

    std::cout << m << ' ' << rightsum;

    return 0;
}