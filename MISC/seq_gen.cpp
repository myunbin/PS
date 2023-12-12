#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // 2 <= N <= 5,000
    const int MAX = 5000;

    int LN = opt<int>("left_n");
    int RN = opt<int>("right_n");

    int N = rnd.next(LN,RN);
    printf("%d\n", N);

    return 0;
}
