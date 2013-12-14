#include "testUtils.h"
#include "binarySearch.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(voidPtr a,voidPtr b){
        return *(int*)a - *(int*)b;
};
int compareChar(voidPtr a,voidPtr b){
        return *(char*)a - *(char*)b;
};
int compareFloat(voidPtr a,voidPtr b){
        return *(float*)a - *(float*)b;
};
int compareDouble(voidPtr a,voidPtr b){
        return *(double*)a - *(double*)b;
}
void test_1_to_search_30_element_in_given_array(){
        int a = 30;
        int data[] = {10,20,30,40,50};
        voidPtr result;
        result = binerySearch(&a,&data,5,sizeof(int),compareInt);
        ASSERT(30 == *(int*)result);
};

void test_2_to_search_float_element_in_given_array(){
        float a = 3.3f;
        float data[3] = {4.3f,2.2f,3.3f};
        voidPtr result;
        result = binerySearch(&a,&data,3,sizeof(float),compareFloat);
        ASSERT(a == *(float*)result);
};
void test_3_to_search_doubleType_element_in_given_array(){
        double a = 3.3;
        double data[] = {2.4,5.6,3.3,6.4,2.2};
        voidPtr result;
        result = binerySearch(&a,&data,5,sizeof(double),compareDouble);
        ASSERT(a == *(double*)result);
};
void test_4_to_search_30_element_in_given_array(){
        char a = 'a';
        char data[] = {'a','s'};
        voidPtr result;
        result = binerySearch(&a,&data,2,sizeof(char),compareChar);
        ASSERT(a == *(char*)result);
};