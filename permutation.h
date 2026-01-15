// Permutation Class

#ifndef PERMUTATION_H
#define PERMUTATION_H

using namespace std;

class Permutation {
private:
    int allPermutations[120][4];
    int count;
    void swap(int& a, int& b);
    void generateHelper(int arr[], int start, int end);

public:
    Permutation();
    void generate(int arr[], int size);
    void getPermutation(int index, int output[4]) const;
    int getCount() const;
};

#endif
