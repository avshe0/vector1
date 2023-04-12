#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    assert(isEmpty(&v));

    pushBack(&v, 5);
    assert(v.data[0] == 5 && v.capacity == 1 && v.size == 1);

    reserve(&v, 0);
    pushBack(&v, 15);
    assert(v.data[0] == 15 && v.capacity == 1 && v.size == 1);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(0);
    assert(isFull(&v));

    pushBack(&v, 5);
    assert(v.data[0] == 5 && v.capacity == 1 && v.size == 1);

    pushBack(&v, 6);
    assert(v.data[1] == 6 && v.capacity == 2 && v.size == 2);

    pushBack(&v, 2);
    pushBack(&v, 1);
    pushBack(&v, 10);
    assert(v.data[4] == 10 && v.capacity == 8 && v.size == 5);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0 && v.capacity == 1);

    pushBack(&v, 12);
    pushBack(&v, 29);

    assert(v.size == 2);
    popBack(&v);
    assert(v.size == 1 && v.capacity == 2);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    vector v = createVector(SIZE_MAX);

    test();

    return 0;
}
