#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void f(bool *a) {
    *a = true;
    printf("fuck!");
}
int main() {
    bool ok = false;
    f(&ok);

    printf("%s", (ok?"yes":"no"));
    return 0;
}