#ifndef CPP_ARRAY_TESTS_H
#define CPP_ARRAY_TESTS_H

#include <iostream>
#include <cassert>
#include "Vector.hpp"


void fill_10000(MyVector<int>& v) {
    for (int i = 0; i < 10000; ++i) {
        int value = i;
        v.push_back(value);
    }
}

void test_push_back() {
    printf("Testing push back\n");
    MyVector<int> array;


    int i;
    for (i = 0; i < 10; ++i) {
        int x = i*2;
        array.push_back(x);

        assert(array.size() == i+1);
    }

    for (i = 0; i < 10; ++i) {
        assert(array[i] == i*2);
    }
}

void test_delete() {
    std::cout << "testing delete" << std::endl;
    MyVector<int> array;

    fill_10000(array);
    assert(array.size() == 10000);

    int initial_size = array.size();
    int deleted_count = 0;

    for (int i = 9999; i >= 0; i -= 2) {
        array.delete_element(i);
        deleted_count++;

        assert(array.size() == initial_size - deleted_count);

    }

    assert(array.size() == initial_size - deleted_count);

    for (int i = 0; i < array.size(); ++i) {
        assert(array[i] == i * 2);
    }

}

void test_find() {
    std::cout << "testing find" << std::endl;

    MyVector<int> array;

    fill_10000(array);

    // поиск существующих элементов
    for (int el = 0; el < 10000; ++el) {

        int found = array.find_element(el);

        int elementRealIndex = el;
        assert(found == elementRealIndex);

    }

    // поиск несуществующего элемента
    int item = -5;
    int found = array.find_element(item);
    assert(found == -1);

}

void run_all_tests() {
    test_push_back();
    test_delete();
    test_find();
    std::cout << "all tests passed" << std::endl;
}

#endif //CPP_ARRAY_TESTS_H
