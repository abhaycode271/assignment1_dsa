class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 2) : size(0), capacity(initialCapacity) {
        arr = new int[capacity];
    }

    

    void insert(int index, int value) {
        if (index < 0 || index > size) return;
        if (size == capacity) resize(capacity * 2);
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) return;
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        if (size < capacity / 4) resize(capacity / 2);
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void rotate(int k) {
        k = k % size;
        if (k == 0) return;
        int* temp = new int[k];
        for (int i = 0; i < k; i++) {
            temp[i] = arr[size - k + i];
        }
        for (int i = size - 1; i >= k; i--) {
            arr[i] = arr[i - k];
        }
        for (int i = 0; i < k; i++) {
            arr[i] = temp[i];
        }
        delete[] temp;
    }

    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

    void append(int value) {
        if (size == capacity) resize(capacity * 2);
        arr[size++] = value;
    }

    void prepend(int value) {
        insert(0, value);
    }

    void merge(DynamicArray& other) {
        for (int i = 0; i < other.size; i++) {
            append(other.arr[i]);
        }
    }

    void interleave(DynamicArray& other) {
        int newSize = size + other.size;
        int* newArr = new int[newSize];
        int i = 0, j = 0, k = 0;
        while (i < size && j < other.size) {
            newArr[k++] = arr[i++];
            newArr[k++] = other.arr[j++];
        }
        while (i < size) {
            newArr[k++] = arr[i++];
        }
        while (j < other.size) {
            newArr[k++] = other.arr[j++];
        }
        delete[] arr;
        arr = newArr;
        size = newSize;
        capacity = newSize;
    }

    int getMiddle() {
        if (isEmpty()) return -1;
        return arr[size / 2];
    }

    int find(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) return i;
        }
        return -1;
    }

    void split(int index, DynamicArray& first, DynamicArray& second) {
        if (index < 0 || index > size) return;
        first = DynamicArray(index);
        second = DynamicArray(size - index);
        for (int i = 0; i < index; i++) {
            first.append(arr[i]);
        }
        for (int i = index; i < size; i++) {
            second.append(arr[i]);
        }
    }

    void resizeCustom(int factor) {
        if (factor <= 1) return;
        resize(size * factor);
    }
};
