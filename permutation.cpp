// Permutation Class

#include "permutation.h"

Permutation::Permutation() {
    count = 0;
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 4; j++) {
            allPermutations[i][j] = -1;
        }
    }
}

void Permutation::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Permutation::generateHelper(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            allPermutations[count][i] = arr[i];
        }
        count++;
    } else {
        for (int i = start; i <= end; i++) {
            swap(arr[start], arr[i]);
            generateHelper(arr, start + 1, end);
            swap(arr[start], arr[i]);
        }
    }
}

void Permutation::generate(int arr[], int size) {
    count = 0;
    generateHelper(arr, 0, size - 1);
}

void Permutation::getPermutation(int index, int output[4]) const {
    if (index < 0 || index >= count) return;
    for (int i = 0; i < 4; ++i) {
        output[i] = allPermutations[index][i];
    }
}

int Permutation::getCount() const {
    return count;
}
