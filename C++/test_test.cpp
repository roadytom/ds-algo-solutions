#include <cstdio>
int main() {
    printf("__cplusplus = %ld\n", (long)__cplusplus);
#ifdef LOCAL
    puts("LOCAL: yes");
#else
    puts("LOCAL: no");
#endif
}