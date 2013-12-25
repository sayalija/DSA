#include "testUtils.h"
#include "linkedList.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_1_create_linledList_object(){
	List* list = create();
	ASSERT(list->head == NULL);
	ASSERT(list->numberOfElements == 0);
}

void test_2_insert_a_node_of_integer_type_at_first(){
	int result;
	List* list = create();
	int element = 3;
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(*(int*)list->head->data == 3);
	ASSERT(list->numberOfElements == 1);
	free(list);
}

void test_3_insert_a_node_of_integer_type_at_last(){
	int result;
	List* list = create();
	int element = 3;
	insert(list, 0, &element);
	result = insert(list, 1, &element);
	ASSERT(result == 1);
	ASSERT(list->numberOfElements == 2);
}

void test_4_insert_a_node_of_float_type_at_first(){
	int result;
	List* list = create();
	float element = 3.3;
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->numberOfElements == 1);
}

void test_5_insert_a_node_of_float_type_at_last(){
	int result;
	List* list = create();
	float element = 3.3;
	result = insert(list, 0, &element);
	result = insert(list, 1, &element);
	ASSERT(result == 1);
	ASSERT(list->numberOfElements == 2);
}

void test_6_insert_a_node_of_double_type_at_first(){
	int result;
	List* list = create();
	double element = 3.6;
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->numberOfElements == 1);
}

void test_7_insert_a_node_of_double_type_at_last(){
	int result;
	List* list = create();
	double element = 3.6;
	insert(list, 0, &element);
	result = insert(list, 1, &element);
	ASSERT(result == 1);
	ASSERT(list->numberOfElements == 2);
}

void test_8_insert_a_node_of_char_type_at_first(){
	int result;
	List* list = create();
	char *element = malloc(sizeof(char));
	*element = 'a';
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->numberOfElements == 1);
	free(element);
}

void test_9_to_insert_in_middle(){
	int result;
	List* list = create();
	int first = 4, second = 5, third = 3, forth = 2;
	insert(list, 0, &first);
	insert(list, 0, &second);
	insert(list, 0, &third);
	result = insert(list, 2, &forth);
	ASSERT(result == 1);
	ASSERT(*(int*)list->head->next->next->data == 2);
}

void test_10_to_delete_first_node(){
	Node* result;
	List* list = create();
	int first = 4;
	insert(list, 0, &first);
	result = remove(list, 0);
	ASSERT(*(int*)result->data == 4);
}

void test_11_to_delete_node_from_between(){
	Node* result;
	List* list = create();
	int first = 4, second = 5, third = 3, forth = 2;
	insert(list, 0, &first);
	insert(list, 0, &second);
	insert(list, 0, &third);
	result = remove(list, 1);
	ASSERT(*(int*)result->data == 3);
	insert(list, 0, &forth);
	result = remove(list, 1);
	ASSERT(*(int*)result->data == 2);
}

void test_12_for_iterator(){
	Iterator it;
	List* list = create();
	int first = 4, second = 5, third = 3, forth = 2;
	insert(list, 0, &first);
	insert(list, 0, &second);
	insert(list, 0, &third);
}