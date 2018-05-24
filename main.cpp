#include "Vector.hpp"

int main() {
    MyVector<int> vector;

    for (int i = 0; i < 10000; ++i) {
        vector.push_back(i);
    }

    assert(vector.size() == 10000);

    vector.delete_element(5);
    assert(vector.size() == 9999);

    assert(vector[4] == 4);
    assert(vector[5] == 6);

    vector.insert_element(5, 5);

    for (int i = 0; i < 10000; ++i) {
        assert(vector.get_at(i) == vector[i]);
    }

    return 0;
}