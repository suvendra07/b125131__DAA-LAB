#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double v, w, l;
} Item;

int cmp(const void *a, const void *b) {
    Item *i1 = (Item *)a;
    Item *i2 = (Item *)b;
    double r1 = (i1->v / i1->w) - i1->l;
    double r2 = (i2->v / i2->w) - i2->l;
    return (r2 > r1) - (r2 < r1);
}

int main() {
    int n;
    double W;
    if (scanf("%d %lf", &n, &W) != 2) return 0;
    Item *arr = malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        arr[i].id = i + 1;
        scanf("%lf %lf %lf", &arr[i].v, &arr[i].w, &arr[i].l);
    }
    qsort(arr, n, sizeof(Item), cmp);
    double cur_t = 0, tot_val = 0, rem_W = W;
    for (int i = 0; i < n && rem_W > 0; i++) {
        double take_w = (arr[i].w < rem_W) ? arr[i].w : rem_W;
        double frac = take_w / arr[i].w;
        double eff_dens = (arr[i].v / arr[i].w) - arr[i].l * cur_t;
        if (eff_dens < 0) eff_dens = 0;
        tot_val += eff_dens * take_w;
        rem_W -= take_w;
        cur_t += frac;
        printf("Item %d: Fraction = %.2f\n", arr[i].id, frac);
    }
    printf("Max Total Value: %.2f\n", tot_val);
    free(arr);
    return 0;
}