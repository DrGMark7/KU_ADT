#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// โครงสร้างของโหนดใน Huffman Tree
typedef struct HuffmanNode {
    char word[16]; // คำ
    int frequency; // ความถี่ของคำ
    struct HuffmanNode *left, *right; // ลูกซ้ายและลูกขวา
} HuffmanNode;

// โครงสร้างของ Min-Heap
typedef struct {
    HuffmanNode** nodes;  // เก็บโหนดของ Huffman Tree
    int size;             // ขนาดของ Heap
    int capacity;         // ความจุของ Heap
} MinHeap;

// สร้าง HuffmanNode ใหม่
HuffmanNode* createNode(const char* word, int frequency, HuffmanNode* left, HuffmanNode* right) {
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    strcpy(node->word, word);
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

// สร้าง MinHeap ใหม่
MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->nodes = (HuffmanNode**)malloc(capacity * sizeof(HuffmanNode*));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// สลับโหนดสองตำแหน่งใน heap
void swap(HuffmanNode** a, HuffmanNode** b) {
    HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// จัดเรียง heap ใหม่หลังจากดึงโหนดออก
void heapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->nodes[left]->frequency < heap->nodes[smallest]->frequency) {
        smallest = left;
    }

    if (right < heap->size && heap->nodes[right]->frequency < heap->nodes[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&heap->nodes[smallest], &heap->nodes[index]);
        heapify(heap, smallest);
    }
}

// แทรกโหนดเข้าใน heap
void insertHeap(MinHeap* heap, HuffmanNode* node) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        exit(EXIT_FAILURE);
    }

    heap->nodes[heap->size] = node;
    int i = heap->size;
    heap->size++;

    while (i != 0 && heap->nodes[(i - 1) / 2]->frequency > heap->nodes[i]->frequency) {
        swap(&heap->nodes[i], &heap->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// ดึงโหนดที่มีความถี่ต่ำสุดออกจาก heap
HuffmanNode* extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty!\n");
        exit(EXIT_FAILURE);
    }

    HuffmanNode* root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// สร้างต้นไม้ Huffman Tree
HuffmanNode* buildHuffmanTree(MinHeap* heap) {
    while (heap->size > 1) {
        HuffmanNode* left = extractMin(heap);
        HuffmanNode* right = extractMin(heap);
        int combinedFreq = left->frequency + right->frequency;
        HuffmanNode* newNode = createNode("", combinedFreq, left, right);
        insertHeap(heap, newNode);
    }
    return extractMin(heap);  // รากของ Huffman Tree
}

// สร้าง Huffman codes โดยใช้ DFS
void generateHuffmanCodes(HuffmanNode* root, char* code, int depth) {
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        printf("%s: %s\n", root->word, code);
        return;
    }

    if (root->left) {
        code[depth] = '0';
        generateHuffmanCodes(root->left, code, depth + 1);
    }

    if (root->right) {
        code[depth] = '1';
        generateHuffmanCodes(root->right, code, depth + 1);
    }
}

// ฟังก์ชันหลัก
int main() {
    int n;
    scanf("%d", &n);
    MinHeap* heap = createHeap(n);

    // อ่านคำและความถี่ แล้วใส่เข้าใน heap
    for (int i = 0; i < n; i++) {
        char word[16];
        int frequency;
        scanf("%s %d", word, &frequency);
        HuffmanNode* node = createNode(word, frequency, NULL, NULL);
        insertHeap(heap, node);
    }

    // สร้างต้นไม้ Huffman Tree
    HuffmanNode* root = buildHuffmanTree(heap);

    // สร้างและแสดง Huffman codes
    char code[100];
    generateHuffmanCodes(root, code, 0);

    return 0;
}
