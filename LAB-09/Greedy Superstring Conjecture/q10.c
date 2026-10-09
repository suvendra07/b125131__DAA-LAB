#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute_overlap(const char *s1, const char *s2, int *overlap_len) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int max_ov = 0;
    for (int k = 1; k <= len1 && k <= len2; k++) {
        if (strncmp(s1 + len1 - k, s2, k) == 0) max_ov = k;
    }
    *overlap_len = max_ov;
    return max_ov;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    char **str = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        str[i] = malloc(1024 * sizeof(char));
        scanf("%s", str[i]);
    }
    int len = n;
    while (len > 1) {
        int max_ov = -1, best_i = -1, best_j = -1;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (i == j) continue;
                int ov;
                compute_overlap(str[i], str[j], &ov);
                if (ov > max_ov) {
                    max_ov = ov; best_i = i; best_j = j;
                }
            }
        }
        int l1 = strlen(str[best_i]), l2 = strlen(str[best_j]);
        char *merged = malloc(l1 + l2 - max_ov + 1);
        strcpy(merged, str[best_i]);
        strcat(merged, str[best_j] + max_ov);
        free(str[best_i]); free(str[best_j]);
        str[best_i] = merged;
        str[best_j] = str[len - 1];
        len--;
    }
    printf("Greedy Superstring: %s\n", str[0]);
    free(str[0]);
    free(str);
    return 0;
}