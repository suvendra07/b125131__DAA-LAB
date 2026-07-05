#include <stdio.h>

void print_growth_order() {
    printf("1. log_2(n)\n");
    printf("2. 12*sqrt(n)\n");
    printf("3. 50*n^0.5\n");
    printf("4. n^0.51\n");
    printf("5. 2^32*n\n");
    printf("6. n*log_2(n)\n");
    printf("7. n^2 - 324\n");
    printf("8. 100*n^2 + 6n\n");
    printf("9. 2*n^3\n");
    printf("10. n^log_2(n)\n");
    printf("11. 3^n\n");
}

int main() {
    print_growth_order();
    return 0;
}
