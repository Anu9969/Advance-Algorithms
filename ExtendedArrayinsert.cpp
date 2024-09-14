#include <iostream>
using namespace std;

class ExtendedArray {
public:
    ExtendedArray() : n(0), capacity(1), A(NULL) {}

    int size() const {
        return n;
    }

    bool isEmpty() const {
        return n == 0;
    }

    int check(int i) const {
        if (i < 0 || i >= n) {
            cout << "Index out of bounds" << endl;
            return -1; // Return an error value
        }
        return A[i];
    }

    void insert(int i, int key) {
        if (i < 0 || i > n) {
            cout << "Index out of bounds" << endl;
            return;
        }
        
        if (n == capacity) {
            reserve(2 * capacity);
        }

        for (int j = n - 1; j >= i; j--) {
            A[j + 1] = A[j];
        }
        A[i] = key;
        n++;
    }

    void reserve(int newCapacity) {
        if (newCapacity <= capacity)
         return; // No need to resize if new capacity is not larger

        int* B = new int[newCapacity];
        for (int i = 0; i < n; i++) {
            B[i] = A[i];
        }
        delete[] A;

        A = B;
        capacity = newCapacity;
    }

private:
    int n;
    int capacity;
    int* A;
};

int main() {
    ExtendedArray arr;
    arr.insert(0, 10);
    arr.insert(1, 20);
    cout << "Array size: " << arr.size() << endl;
    cout << "Element at index 0: " << arr.check(0) << endl;
    cout << "Element at index 1: " << arr.check(1) << endl;
    return 0;
}
