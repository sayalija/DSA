#include "testUtils.h"
#include "bSort.h"
#include <string.h>
#include <memory.h>

int compareInts(void* a, void* b){
        return *(int*)a - *(int*)b;
};
int compareFloats(void* a, void* b){
        return *(float*)a - *(float*)b;
};
int compareDoubles(void* a, void* b){
        return *(double*)a - *(double*)b;
};
int areEqual(void* element1, void* element2,size_t size){
        return 0 == memcmp(element1,element2,sizeof(element1)*size);
};

void test_1_for_sorting_sorted_integer_values() {
        int elements[5] = {1,2,3,4,5};
        int expected[5] = {1,2,3,4,5};
        bSort(elements, 5, sizeof(int), compareInts);
        ASSERT(areEqual(&elements,&expected,5));
};

void test_2_for_sorting_unsorted_integer_values() {
        int elements[5] = {3,5,2,4,1};
        int expected[5] = {1,2,3,4,5};
        bSort(elements, 5, sizeof(int), compareInts);
        ASSERT(areEqual(&elements,&expected,5));
};

void test_3_for_sorting_unsorted_float_values() {
        float elements[5] = {4.0f,2.0f,1.0f,3.0f,5.0f};
        float expected[5] = {1.0f,2.0f,3.0f,4.0f,5.0f};
        bSort(elements, 5, sizeof(float), compareFloats);
        ASSERT(areEqual(&elements,&expected,5));
};

void test_4_for_sorting_sorted_float_values() {
        double elements[5] = {1.0f,2.0f,3.0f,4.0f,5.0f};
        double expected[5] = {1.0f,2.0f,3.0f,4.0f,5.0f};
        bSort(elements, 5, sizeof(double), compareFloats);
        ASSERT(areEqual(&elements,&elements,5));
};

void test_5_for_sorting_unsorted_double_values() {
        double elements[5] = {4.0,2.0,1.0,3.0,5.0};
        double expected[5] = {1.0,2.0,3.0,4.0,5.0};
        bSort(elements, 5, sizeof(double), compareDoubles);
        ASSERT(areEqual(&elements,&expected,5));
};

void test_6_for_sorting_sorted_double_values() {
        double elements[5] = {1.0,2.0,3.0,4.0,5.0};
        double expected[5] = {1.0,2.0,3.0,4.0,5.0};
        bSort(elements, 5, sizeof(double), compareDoubles);
        ASSERT(areEqual(&elements,&expected,5));
};