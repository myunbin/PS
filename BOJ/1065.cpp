#include <bits/stdc++.h>
// #include <vector>
// #include <algorithm>
// #include <iostream>
using namespace std;

bool ok(int x) {
    int pos = 0;
    while (x) {
        a[pos++]=x%10;
        x/=10;
    }

    if (pos==1) return 1;

    int d=a[1]-a[0];
    for (int i=0; i<pos-1; i++) {
        if (d!=a[i+1]-a[i]) {
            return 0;
        }
    }
    for (int i=0; i<pos; i++) a[i]=0;

    return 1;
}

int main() {

    return 0;
}