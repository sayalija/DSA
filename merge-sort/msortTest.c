#include "testUtils.h"
#include "msort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void* a, void* b){
        return *(int*)a - *(int*)b;
};
void test_1_for_sorting_sorted_integer_values() {
    int a[3] = {1,2,3};
    int expected[3] = {1,2,3};
    void* elements[] = {&a[0],&a[1],&a[2]}; 
    ASSERT(expected[0] == *(int*)elements[0]);
};

void test_2_for_sorting_unsorted_integer_values() {
    int a[3] = {2,3,1};
    int expected[3] = {1,2,3};
    void* elements[] = {&a[0],&a[1],&a[2]}; 
    ASSERT(expected[0] == *(int*)elements[0]);
};