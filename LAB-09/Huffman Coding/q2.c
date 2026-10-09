#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct {
    char ch;
    int len;
    unsigned int code;
} CanonicalCode;

Node* create_node(char ch, int freq, Node* l, Node* r) {
    Node* n = malloc(sizeof(Node));
    n->ch = ch; n->freq = freq; n->left = l; n->right = r;
    return n;
}

void swap(Node** a, Node** b) { Node* t = *a; *a = *b; *b = t; }

void min_heapify(Node** heap, int size, int i) {
    int smallest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < size && heap[l]->freq < heap[smallest]->freq) smallest = l;
    if (r < size && heap[r]->freq < heap[smallest]->freq) smallest = r;
    if (smallest != i) { swap(&heap[i], &heap[smallest]); min_heapify(heap, size, smallest); }
}

void get_lengths(Node* root, int depth, CanonicalCode* codes, int* count) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[*count].ch = root->ch;
        codes[*count].len = depth;
        (*count)++;
        return;
    }
    get_lengths(root->left, depth + 1, codes, count);
    get_lengths(root->right, depth + 1, codes, count);
}

int cmp_canon(const void* a, const void* b) {
    CanonicalCode* c1 = (CanonicalCode*)a;
    CanonicalCode* c2 = (CanonicalCode*)b;
    if (c1->len != c2->len) return c1->len - c2->len;
    return c1->ch - c2->ch;
}

void print_binary(unsigned int val, int len) {
    for (int i = len - 1; i >= 0; i--) printf("%d", (val >> i) & 1);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Node** heap = malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        char ch; int freq;
        scanf(" %c %d", &ch, &freq);
        heap[i] = create_node(ch, freq, NULL, NULL);
    }
    for (int i = (n - 2) / 2; i >= 0; i--) min_heapify(heap, n, i);
    int size = n;
    while (size > 1) {
        Node* l = heap[0]; heap[0] = heap[--size]; min_heapify(heap, size, 0);
        Node* r = heap[0];
        Node* parent = create_node('\0', l->freq + r->freq, l, r);
        heap[0] = parent; min_heapify(heap, size, 0);
    }
    CanonicalCode* codes = malloc(n * sizeof(CanonicalCode));
    int count = 0;
    get_lengths(heap[0], 0, codes, &count);
    qsort(codes, n, sizeof(CanonicalCode), cmp_canon);
    unsigned int cur_code = 0;
    int cur_len = codes[0].len;
    for (int i = 0; i < n; i++) {
        if (codes[i].len > cur_len) {
            cur_code <<= (codes[i].len - cur_len);
            cur_len = codes[i].len;
        }
        codes[i].code = cur_code++;
        printf("Symbol: %c | Length: %d | Code: ", codes[i].ch, codes[i].len);
        print_binary(codes[i].code, codes[i].len);
        printf("\n");
    }
    free(heap); 
    free(codes);
    return 0;
}