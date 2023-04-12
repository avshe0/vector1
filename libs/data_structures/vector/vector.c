#include "vector.h"

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "Wrong value: capacity");
        exit(1);
    }

    return (vector) {
            data,
            0,
            n
    };
}

// изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    }

    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "Wrong value: newCapacity");
        exit(1);
    }

    v->capacity = newCapacity;
    if (newCapacity < v->size) {
        v->size = newCapacity;
    }
}

// удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v) {
    v->size = 0;
}

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

// освобождает память, выделенную вектору
void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

// проверка, является ли вектор пустым
bool isEmpty(vector *v) {
    return v->size == 0;
}

// проверка, является ли вектор полным
bool isFull(vector *v) {
    return v->size == v->capacity;
}

// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i) {
    return *(v->data + i);
}

// добавляет элемент x в конец вектора v
void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        v->capacity++;
    } else if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }

    v->data[v->size++] = x;
}

// удаляет последний элемент из вектора
void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }

    v->size--;
}