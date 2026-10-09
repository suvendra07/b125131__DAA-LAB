#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

void max_heapify(CharFreq *heap, int size, int i) {
    int max_idx = i, l = 2*i + 1, r = 2*i + 2;
    if (l < size && heap[l].freq > heap[max_idx].freq) max_idx = l;
    if (r < size && heap[r].freq > heap[max_idx].freq) max_idx = r;
    if (max_idx != i) {
        CharFreq t = heap[i]; heap[i] = heap[max_idx]; heap[max_idx] = t;
        max_heapify(heap, size, max_idx);
    }
}

CharFreq pop_max(CharFreq *heap, int *size) {
    CharFreq top = heap[0];
    heap[0] = heap[--(*size)];
    max_heapify(heap, *size, 0);
    return top;
}

void push_max(CharFreq *heap, int *size, CharFreq val) {
    heap[(*size)++] = val;
    int i = *size - 1;
    while (i > 0 && heap[(i - 1) / 2].freq < heap[i].freq) {
        CharFreq t = heap[(i - 1) / 2]; heap[(i - 1) / 2] = heap[i]; heap[i] = t;
        i = (i - 1) / 2;
    }
}

int main() {
    char str[100005];
    int K;
    if (scanf("%s %d", str, &K) != 2) return 0;
    int len = strlen(str);
    if (K <= 1) { printf("Reorganized String: %s\n", str); return 0; }
    
    int freq[256] = {0};
    for (int i = 0; i < len; i++) freq[(unsigned char)str[i]]++;
    
    CharFreq heap[256];
    int heap_size = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            heap[heap_size].ch = (char)i;
            heap[heap_size].freq = freq[i];
            heap_size++;
        }
    }
    for (int i = (heap_size - 2) / 2; i >= 0; i--) max_heapify(heap, heap_size, i);
    
    char *res = malloc((len + 1) * sizeof(char));
    CharFreq *queue = malloc(K * sizeof(CharFreq));
    int q_head = 0, q_tail = 0, q_cnt = 0;
    
    int idx = 0;
    while (heap_size > 0) {
        CharFreq cur = pop_max(heap, &heap_size);
        res[idx++] = cur.ch;
        cur.freq--;
        
        if (q_cnt == K - 1) {
            CharFreq ready = queue[q_head];
            q_head = (q_head + 1) % K;
            q_cnt--;
            if (ready.freq > 0) push_max(heap, &heap_size, ready);
        }
        queue[q_tail] = cur;
        q_tail = (q_tail + 1) % K;
        q_cnt++;
    }
    res[idx] = '\0';
    if (idx == len) printf("Reorganized String: %s\n", res);
    else printf("Empty String (Impossible)\n");
    
    free(res); 
    free(queue);
    return 0;
}