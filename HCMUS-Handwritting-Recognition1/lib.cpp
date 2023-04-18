#include "lib.hpp"
#include <algorithm>
#include <stdio.h>

const int N = (int) 6e4, sz = 28 * 28;
node sx[N];
int cnt[10];

// int guess(void * xav, void * yav, void * testav) {
//     const int K = 1000;
//     unsigned long long * x = (unsigned long long *) xav;
//     unsigned long long * y = (unsigned long long *) yav;
//     unsigned long long * test = (unsigned long long *) testav;

//     for (int i = 0; i < N; i++) {
//         unsigned long long sum = 0;
//         for (int j = 0; j < sz; j++) {
//             unsigned long long a = x[i * sz + j], b = test[j];
//             unsigned long long v = (a > b) ? a - b : b - a;
//             unsigned long long u = (a-b)*(a-b);
//             sum = sum + (u);
//         }
//         sx[i].val = sum;
//         sx[i].num = y[i];
//     }

//     std::sort(sx, sx + N);

//     int cnt[10];
//     for (int i = 0; i < 10; ++i) cnt[i] = 0;
//     for (int i = 0; i < K; ++i) cnt[sx[i].num]++;
    
//     int maxi = 0;
//     for (int i = 0; i < 10; ++i) {
//         if (cnt[i] > maxi) maxi = cnt[i];
//     }
//     for (int i = 0; i < 10; ++i) 
//         if (cnt[i] == maxi) return i;
//     return -1;
// }

// fraction Proper(void * xav, void * yav, int len, void * ansav, void * alltestav) {
//     unsigned long long * ans = (unsigned long long *) ansav;
//     unsigned long long * alltest = (unsigned long long *) alltestav;

//     int cnt = 0;
//     for (int i = 0; i < len; ++i) {
//         cnt += (ans[i] != guess(xav, yav, ))
//     }
// }

void supervjp(void * xav, void * yav, int len, void * ansav, void * testav) {
    unsigned long long * ans = (unsigned long long *) ansav;
    unsigned long long * test = (unsigned long long *) testav;

    const int K = 10;
    unsigned long long * x = (unsigned long long *) xav;
    unsigned long long * y = (unsigned long long *) yav;

    printf("start!!!\n");

    int correct = 0;
    for (int i_test = 0; i_test < len; ++i_test) {
        for (int i = 0; i < N; i++) {
            unsigned long long sum = 0;
            for (int j = 0; j < sz; j++) {
                unsigned long long a = x[i * sz + j], b = test[i_test * sz + j];
                unsigned long long v = (a > b) ? a - b : b - a;
                unsigned long long u = (a-b)*(a-b);
                sum = sum + (u);
            }
            sx[i].val = sum;
            sx[i].num = y[i];
        }

        std::sort(sx, sx + N);

        for (int i = 0; i < 10; ++i) cnt[i] = 0;
        for (int i = 0; i < K; ++i) cnt[sx[i].num]++;
        
        int maxi = 0, number = -1;
        for (int i = 0; i < 10; ++i) {
            if (cnt[i] > maxi) {
                maxi = cnt[i];
                number = i;
            }
        }
        correct += (number == ans[i_test]);
        printf("%d --- %d\n", i_test + 1, correct);
    }
    printf("%d / %d", correct, len);
    return;
}