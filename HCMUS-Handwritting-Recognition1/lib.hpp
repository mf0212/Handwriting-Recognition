#ifndef LIB1_H_INCLUDED
#define LIB1_H_INCLUDED

#ifdef __cplusplus
   extern "C" {
#endif

struct node {
    int val, num;

    bool operator < (const node& other) {
        return this->val < other.val;
    }
};

struct fraction {
    int num, den;

    fraction(int NUM = 1, int DEN = 1) {
        num = NUM;
        den = DEN;
    }
};

int guess(void * xav, void * yav, void * testav);
void supervjp(void * xav, void * yav, int len, void * ansav, void * testav);

#ifdef __cplusplus
   }
#endif

#endif /* LIB1_H_INCLUDED */