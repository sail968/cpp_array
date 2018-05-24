#include <cassert>
#include <iostream>

template <typename T>
class MyVector {
public:
    MyVector();
    ~MyVector();
    void push_back(T item);
    T& get_at(int position);
    int find_element(T item);
    void delete_element(T item);
    void insert_element(T item, int position);

    T& operator[](int position);

    int size() {
        return tail - head;
    }

private:
    int head;
    int tail;
    int capacity;
    T *array;

    void extend_array();
};


template <typename T>
MyVector<T>::MyVector() : capacity(4), head(0), tail(0) {
    array = new T[capacity];
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] array;
}

template <typename T>
void MyVector<T>::extend_array() {
    int i = 0;
    T *temp_array = new T[capacity * 2];

    for (int j = head; j < tail; j++) {
        temp_array[i] = array[j % capacity];
        i++;
    }

    head = 0;
    tail = capacity;
    capacity *= 2;
    delete[] array;
    array = temp_array;
}

template <typename T>
void MyVector<T>::push_back(T item) {
    if (tail - head == capacity) {
        extend_array();
    }

    array[tail] = item;
    tail++;
}

template <typename T>
T& MyVector<T>::get_at(int position) {
    assert(position > tail);
    return array[position];
}

template<typename T>
int MyVector<T>::find_element(T item) {
    for (int i = head; i < tail; i++) {
        if (array[i] == item) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void MyVector<T>::delete_element(T item) {
    int delete_position = find_element(item);
    for (int i = delete_position; i < tail; i++) {
        array[i] = array[i + 1];
    }
    tail--;
}

template<typename T>
void MyVector<T>::insert_element(T item, int position) {
    if (tail - head == capacity) {
        extend_array();
    }
    for (int i = tail; i > position; i--) {
        array[i] = array[i-1];
    }
    array[position % capacity] = item;
    tail++;
}

template<typename T>
T &MyVector<T>::operator[](int position) {
    return array[position];
}
