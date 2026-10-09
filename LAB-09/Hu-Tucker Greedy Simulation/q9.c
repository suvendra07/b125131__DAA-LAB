#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long long weight;
    int is_original;
    struct Node *left, *right;
} Node;

Node* create_node(long long w, int orig, Node *l, Node *r) {
    Node *n = malloc(sizeof(Node));
    n->weight = w; n->is_original = orig; n->left = l; n->right = r;
    return n;
}

void get_depths(Node *root, int depth, int *depths, int *idx) {
    if (!root) return;
    if (root->is_original) {
        depths[(*idx)++] = depth;
        return;
    }
    get_depths(root->left, depth + 1, depths, idx);
    get_depths(root->right, depth + 1, depths, idx);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    long long *orig_w = malloc(n * sizeof(long long));
    Node **nodes = malloc(n * sizeof(Node*));
    int size = n;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &orig_w[i]);
        nodes[i] = create_node(orig_w[i], 1, NULL, NULL);
    }
    
    while (size > 1) {
        long long min_sum = -1;
        int min_i = -1, min_j = -1;
        for (int i = 0; i < size - 1; i++) {
            long long sum = nodes[i]->weight + nodes[i+1]->weight;
            if (min_sum == -1 || sum < min_sum) {
                min_sum = sum;
                min_i = i;
                min_j = i + 1;
            }
        }
        Node *merged = create_node(min_sum, 0, nodes[min_i], nodes[min_j]);
        nodes[min_i] = merged;
        for (int k = min_j; k < size - 1; k++) nodes[k] = nodes[k + 1];
        size--;
    }
    
    int *depths = malloc(n * sizeof(int));
    int idx = 0;
    get_depths(nodes[0], 0, depths, &idx);
    
    long long total_cost = 0;
    for (int i = 0; i < n; i++) total_cost += orig_w[i] * depths[i];
    printf("Optimal Cost: %lld\n", total_cost);
    
    free(orig_w);
    free(nodes);
    free(depths);
    return 0;
}