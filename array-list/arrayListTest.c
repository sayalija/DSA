#include <stdlib.h>
#include "testUtils.h"
#include "arrayList.h"
const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_1_insert_element(){
	int result = insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_2_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_3_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	dispose(listPtr);		
}

void test_4_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_5_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_6_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_7_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}

void test_8_add_a_element_to_array(){
	int result = add(internsPtr,&prateek);
	ASSERT(result == SUCCESS);			
	ASSERT(&prateek == get(internsPtr, 0));
}

int cmp(void* a, void* b){
	Intern list = *(Intern*)a;
	Intern data =*(Intern*)b;
	return list.id == data.id;
}

void test_9_to_search_a_element(){
	int result;
	add(internsPtr,&prateek);
	result = search(internsPtr , &prateek, cmp);
	ASSERT(result == SUCCESS);
}

void test_10_to_search_a_element_which_is_not_present(){
	int result;
	add(internsPtr,&ji);
	result = search(internsPtr , &prateek, cmp);
	ASSERT(result == FAILURE);
}

void test_11_remove_a_element(){
	int result;
	add(internsPtr,&prateek);
	result = remove(internsPtr, 0);
	ASSERT(result == 1);
}

void test_12_try_to_remove_a_element_which_is_not_present(){
	int result;
	result = remove(internsPtr, 0);
	ASSERT(result == 0);
}