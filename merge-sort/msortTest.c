#include "testUtils.h"
#include "msort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void *first,void *second){
        return *(int*)first - *(int*)second;
}

void test_sorting_two_elements_with_merge_sort(){
    int a[] = {3,2},expected[] = {2,3};
    void *elements[] = {&a[0],&a[1]};
    msort(elements,2,compareInts);
    ASSERT(expected[0] == *(int*)elements[0]);
    ASSERT(expected[1] == *(int*)elements[1]);
};

void test_sorting_four_elements_with_merge_sort(){
    int a[] = {2,3,4,1},expected[] = {1,2,3,4};
    void *elements[] = {&a[0],&a[1],&a[2],&a[3]};
    msort(elements,4,compareInts);
    ASSERT(expected[0] == *(int*)elements[0]);
    ASSERT(expected[1] == *(int*)elements[1]);
    ASSERT(expected[2] == *(int*)elements[2]);
    ASSERT(expected[3] == *(int*)elements[3]);
};


