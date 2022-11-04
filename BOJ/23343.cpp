#include <bits/stdc++.h>

using namespace std;

char a[10];
char b[10];

bool is_number(const char *s) {
    for (int i = 0; s[i]; i++) {
        if (!('0' <= s[i] && s[i] <= '9')) return false;
    }
    return true;
}

int main() {
    scanf("%s %s", a, b);

    if (!is_number(a) || !is_number(b)) {
        printf("NaN\n");
        return 0;
    }

    int A = atoi(a);
    int B = atoi(b);

    printf("%d\n", A - B);

    return 0;
}