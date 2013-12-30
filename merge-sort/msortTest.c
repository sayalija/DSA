#include "testUtils.h"
#include "msort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInteger(void *element1,void *element2){
        return *(int*)element1 - *(int*)element2;
}

int compareFloats(void *element1,void *element2){
        return *(float*)element1 - *(float*)element2;
}

int compareDouble(void *element1,void *element2){
        return *(double*)element1 - *(double*)element2;
}

void test_sorting_two_elements_with_merge_sort(){
    int a[] = {3,2},expected[] = {2,3};
    void *elements[] = {&a[0],&a[1]};
    msort(elements,2,compareInteger);
    ASSERT(expected[0] == *(int*)elements[0]);
    ASSERT(expected[1] == *(int*)elements[1]);
};

void test_sorting_four_elements_with_merge_sort(){
    int a[] = {1,2,3,4,5},expected[] = {1,2,3,4,5};
    void *elements[] = {&a[0],&a[1],&a[2],&a[3],&a[4]};
    msort(elements,5,compareInteger);
    ASSERT(expected[0] == *(int*)elements[0]);
    ASSERT(expected[1] == *(int*)elements[1]);
    ASSERT(expected[2] == *(int*)elements[2]);
    ASSERT(expected[3] == *(int*)elements[3]);
    ASSERT(expected[4] == *(int*)elements[4]);
};

void test_sorting_two_float_elements_with_merge_sort(){
    float a[] = {3.3f,2.2f},expected[] = {2.2f,3.3f};
    void *elements[] = {&a[0],&a[1]};
    msort(elements,2,compareFloats);
    ASSERT(expected[0] == *(float*)elements[0]);
    ASSERT(expected[1] == *(float*)elements[1]);
};

void test_sorting_three_float_elements_with_merge_sort(){
    float a[] = {3.3f,4.4f,1.1f},expected[] = {1.1f,3.3f,4.4f};
    void *elements[] = {&a[0],&a[1],&a[2]};
    msort(elements,3,compareFloats);
    ASSERT(expected[0] == *(float*)elements[0]);
    ASSERT(expected[1] == *(float*)elements[1]);
    ASSERT(expected[2] == *(float*)elements[2]);
};

void test_sorting_two_double_elements_with_merge_sort(){
    double a[] = {3.3,2.2},expected[] = {2.2,3.3};
    void *elements[] = {&a[0],&a[1]};
    msort(elements,2,compareDouble);
    ASSERT(expected[0] == *(double*)elements[0]);
    ASSERT(expected[1] == *(double*)elements[1]);
};

void test_sorting_three_double_elements_with_merge_sort(){
    double a[] = {3.3,4.4,1.1},expected[] = {1.1,3.3,4.4};
    void *elements[] = {&a[0],&a[1],&a[2]};
    msort(elements,3,compareDouble);
    ASSERT(expected[0] == *(double*)elements[0]);
    ASSERT(expected[1] == *(double*)elements[1]);
    ASSERT(expected[2] == *(double*)elements[2]);
};