#include <stdio.h>
#include <stdlib.h>

int weighing_count = 0;

int weigh(const double weights[], const int g1[], int len1, const int g2[], int len2) {
    weighing_count++;
    double w1 = 0.0, w2 = 0.0;

    for (int i = 0; i < len1; i++) w1 += weights[g1[i]];
    for (int i = 0; i < len2; i++) w2 += weights[g2[i]];

    if (w1 < w2) return -1;
    if (w1 > w2) return 1;
    return 0;
}

int find_known_defective(const double weights[], const int indices[], int n) {
    if (n == 1) {
        return indices[0];
    }

    int k = n / 2;

    int result = weigh(weights, indices, k, indices + k, k);

    if (result == -1) {
        return find_known_defective(weights, indices, k);
    } else if (result == 1) {
        return find_known_defective(weights, indices + k, k);
    } else {
        return indices[2 * k];
    }
}

int find_defective_coin(const double weights[], int n) {
    weighing_count = 0;

    if (n <= 1) {
        return -1; 
    }

    int *indices = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    int k = n / 2;

    int result = weigh(weights, indices, k, indices + k, k);
    int defective_idx = -1;

    if (result == -1) {
        defective_idx = find_known_defective(weights, indices, k);
    } else if (result == 1) {
    
        defective_idx = find_known_defective(weights, indices + k, k);
    } else {
        if (n % 2 == 1) {
            int rem_idx[1] = { 2 * k };
            int ref_idx[1] = { 0 };

            int rem_result = weigh(weights, rem_idx, 1, ref_idx, 1);
            if (rem_result == -1) {
                defective_idx = 2 * k; 
            } else {
                defective_idx = -1;   
            }
        } else {
            defective_idx = -1; 
        }
    }

    free(indices);
    return defective_idx;
}

int main() {
    int n = 10;
    double standard_weight = 10.0;
    double weights[10];

    printf("====================================================\n");
    printf("        DEFECTIVE COIN DETECTION ALGORITHM          \n");
    printf("====================================================\n");

    for (int i = 0; i < n; i++) weights[i] = standard_weight;
    int result1 = find_defective_coin(weights, n);
    printf("Test 1 (All Perfect Coins):\n");
    printf("  Result: %s\n", (result1 == -1) ? "No defective coin found" : "Defective coin found");
    printf("  Total Scale Weighings: %d\n\n", weighing_count);

    for (int i = 0; i < n; i++) weights[i] = standard_weight;
    weights[4] = 9.2; 
    int result2 = find_defective_coin(weights, n);
    printf("Test 2 (Coin 4 is lighter):\n");
    printf("  Result: Defective coin found at Index %d\n", result2);
    printf("  Total Scale Weighings: %d\n", weighing_count);
    printf("====================================================\n");

    return 0;
}