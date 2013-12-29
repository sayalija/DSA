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
	interns = createList(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	disposeList(internsPtr);	
}

void test_1_insert_element(){
	int result = insertElement(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)getElement(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_2_insert_multiple_elements() {
	insertElement(internsPtr, 0, &prateek);
	insertElement(internsPtr, 1, &ji);
	ASSERT(&prateek == getElement(internsPtr, 0));
	ASSERT(&ji == getElement(internsPtr, 1));
}

void test_3_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = createList(noOfElements);
	ArrayList *listPtr = &list;

	insertElement(listPtr, 0, &prateek);
	insertElement(listPtr, 1, &ji);

	ASSERT(&prateek == getElement(listPtr, 0));
	ASSERT(&ji == getElement(listPtr, 1));

	disposeList(listPtr);		
}

void test_4_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insertElement(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_5_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insertElement(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_6_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insertElement(internsPtr, 0, &prateek);
	insertElement(internsPtr, 1, &ji);
	insertElement(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == getElement(internsPtr, 0));
	ASSERT(&tanbirka == getElement(internsPtr, 1));
	ASSERT(&ji == getElement(internsPtr, 2));
}

void test_7_should_not_insert_when_list_is_null() {
	int result = insertElement(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}

void test_8_add_a_element_to_array(){
	int result = add(internsPtr,&prateek);
	ASSERT(result == SUCCESS);			
	ASSERT(&prateek == getElement(internsPtr, 0));
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
	result = removeElement(internsPtr, 0);
	ASSERT(result == 1);
}

void test_12_try_to_remove_a_element_which_is_not_present(){
	int result;
	result = removeElement(internsPtr, 0);
	ASSERT(result == 0);
}

void test_iterator_tells_that_next_data_is_present(){
    Iterator it;
    insertElement(internsPtr, 0, &prateek);
    it = getListIterator(internsPtr);
    ASSERT(1 == it.hasNext(&it));
}

void test_iterator_tells_that_next_data_is_not_present(){
    Iterator it;
    it = getListIterator(internsPtr);
    ASSERT(0 == it.hasNext(&it));
}

void test_iterator_gives_the_data_of_next_index(){
    Iterator it;
    insertElement(internsPtr, 0, &prateek);
    insertElement(internsPtr, 0, &ji);
    it = getListIterator(internsPtr);
    ASSERT(&ji == it.next(&it));
    ASSERT(&prateek == it.next(&it));
    ASSERT(NULL == it.next(&it));
}
