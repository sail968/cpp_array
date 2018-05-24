#include <cassert>
#include <iostream>

template <typename T>
class MyVector {
public:
    MyVector();
    ~MyVector();
    void push_back(T item);
    int get_at(int position);
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


template <typename Type>
MyVector<Type>::MyVector() : capacity(2), head(0), tail(0) {
    array = new Type[capacity];
}

template <typename Type>
MyVector<Type>::~MyVector() {
    delete[] array;
}

template <typename Type>
void MyVector<Type>::extend_array() {
    int i = 0;
    Type *temp_array = new Type[capacity * 2];

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

template <typename Type>
void MyVector<Type>::push_back(Type item) {
    if (tail - head == capacity) {
        extend_array();
    }
    array[tail % capacity] = item;
    tail++;
}

template <typename Type>
Type MyVector<Type>::get_at(int position) {
    assert(position > tail);
    return array[position];
}

template<typename Type>
int MyVector<Type>::find_element(Type item) {
    for (int i = head; i < tail; i++) {
        if (array[i] == item) {
            return i;
        }
    }
    return -1;
}

template<typename Type>
void MyVector<Type>::delete_element(Type item) {
    int delete_position = find_element(item);
    for (int i = delete_position; i < tail; i++) {
        array[i] = array[i + 1];
    }
    tail--;
}

template<typename Type>
void MyVector<Type>::insert_element(Type item, int position) {
    if (tail - head == capacity) {
        extend_array();
    }
    for (int i = position; i < tail; i++) {
        array[i + 1] = array[i];
    }
    array[position % capacity] = item;
    tail++;
}

template<typename T>
T &MyVector<T>::operator[](int position) {
    return array[position];
}
