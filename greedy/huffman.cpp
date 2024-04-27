#include <iostream>
#include <cstring> // for memset

#define MAX_TREE_HT 100

struct MinHeapNode {
    char item; // One of the input characters
    unsigned freq; // Frequency of the character
    MinHeapNode *left, *right; // Left and right child of this node
};

struct MinHeap {
    unsigned size; // Current size of min heap
    unsigned capacity; // Capacity of min heap
    MinHeapNode **array; // Attay of minheap node pointers
};

// A utility function to create a new min heap node
MinHeapNode* newNode(char item, unsigned freq) {
    MinHeapNode* temp = new MinHeapNode();
    temp->left = temp->right = nullptr;
    temp->item = item;
    temp->freq = freq;
    return temp;
}

// A utility function to create a min heap of given capacity
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = new MinHeap();
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = new MinHeapNode*[capacity];
    return minHeap;
}

// A utility function to swap two min heap nodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// The standard minHeapify function
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// A utility function to check if size of heap is 1 or not
bool isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// The standard insert function for a min heap
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    int i = minHeap->size++;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// A utility function to build min heap
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// A function to print an array of size n
void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i];
    std::cout << "\n";
}

// Utility function to check if this node is leaf
bool isLeaf(MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// The main function that builds Huffman tree
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;

    // Step 1: Create a min heap of capacity equal to size.  Initially, there are modes equal to size.
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minHeap)) {
        // Step 2: Extract the two minimum freq items from min heap
        left = minHeap->array[0];
        minHeap->array[0] = minHeap->array[minHeap->size - 1];
        --minHeap->size;
        minHeapify(minHeap, 0);

        right = minHeap->array[0];
        minHeap->array[0] = minHeap->array[minHeap->size - 1];
        --minHeap->size;
        minHeapify(minHeap, 0);

        // Step 4: Create a new internal node with frequency equal to the sum of the two nodes frequencies.
        // Make the two extracted node as left and right children of this new node. Add this node to the min heap
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    // Step 5: The remaining node is the root node and the tree is complete.
    return minHeap->array[0];
}

// Prints huffman codes from the root of Huffman Tree. It uses arr[] to store codes
void printCodes(MinHeapNode* root, int arr[], int top) {
    // Assign 0 to left edge and recur
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // Assign 1 to right edge and recur
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node, then it contains one of the input characters, print the character and its code from arr[]
    if (isLeaf(root)) {
        std::cout << root->item << ": ";
        printArr(arr, top);
    }
}

// The main function that builds a Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size) {
    // Construct Huffman Tree
    MinHeapNode* root = buildHuffmanTree(data, freq, size);

    // Print Huffman codes using the Huffman tree built above
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
