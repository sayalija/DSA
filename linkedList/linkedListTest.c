#include "testUtils.h"
#include "linkedList.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_1_create_linledList_object(){
	List* list = create();
	ASSERT(list->head == NULL);
	ASSERT(list->tail == NULL);
	ASSERT(list->numberOfElements == 0);
}

void test_2_insert_a_node_at_first_of_integer_type(){
	int result;
	List* list = create();
	int *element = malloc(sizeof(int));
	*element = 3;
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->numberOfElements == 1);
	free(element);
}

void test_3_insert_a_node_at_last_of_integer_type(){
	int result;
	List* list = create();
	int *element = malloc(sizeof(int));
	*element = 3;
	result = insert(list, 0, &element);
	result = insert(list, 1, &element);
	ASSERT(result == 1);
	ASSERT(list->tail->data == &element);
	ASSERT(list->numberOfElements == 2);
	free(element);
}

void test_4_insert_a_node_at_first_of_float_type(){
	int result;
	List* list = create();
	float *element = malloc(sizeof(float));
	*element = 3.3;
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->numberOfElements == 1);
	free(element);
}

void test_5_insert_a_node_at_last_of_float_type(){
	int result;
	List* list = create();
	float *element = malloc(sizeof(float));
	*element = 3.3;
	result = insert(list, 0, &element);
	result = insert(list, 1, &element);
	ASSERT(result == 1);
	ASSERT(list->tail->data == &element);
	ASSERT(list->numberOfElements == 2);
	free(element);
}

void test_6_insert_a_node_at_first_of_double_type(){
	int result;
	List* list = create();
	double *element = malloc(sizeof(double));
	*element = 3.6;
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->numberOfElements == 1);
	free(element);
}

void test_7_insert_a_node_at_last_of_double_type(){
	int result;
	List* list = create();
	double *element = malloc(sizeof(double));
	*element = 3.6;
	result = insert(list, 0, &element);
	result = insert(list, 1, &element);
	ASSERT(result == 1);
	ASSERT(list->tail->data == &element);
	ASSERT(list->numberOfElements == 2);
	free(element);
}

void test_8_insert_a_node_at_first_of_char_type(){
	int result;
	List* list = create();
	float *element = malloc(sizeof(float));
	*element = 'a';
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->numberOfElements == 1);
	free(element);
}

void test_9_insert_a_node_at_last_of_char_type(){
	int result;
	List* list = create();
	float *element = malloc(sizeof(float));
	*element = 'a';
	insert(list, 0, &element);
	result = insert(list, 1, &element);
	ASSERT(result == 1);
	ASSERT(list->tail->data == &element);
	ASSERT(list->numberOfElements == 2);
	free(element);
}

void test_10_get_length_of_linkedList(){
	int result;
	List* list = create();
	int *firstNum = malloc(sizeof(int));
	int *secondNum = malloc(sizeof(int));
	int *thirdNum = malloc(sizeof(int));
	*firstNum = 3, *secondNum = 4, *thirdNum = 5;
	insert(list, 0, &firstNum);
	insert(list, 1, &secondNum);
	insert(list, 2, &thirdNum);
	result = getLength(list);
	ASSERT(result == 3);
}

void test_11_get_length_of_linkedList(){
	int result;
	List* list = create();
	char *firstNum = malloc(sizeof(char));
	char *secondNum = malloc(sizeof(char));
	*firstNum = 'a', *secondNum = 'b';
	insert(list, 0, &firstNum);
	insert(list, 1, &secondNum);
	result = getLength(list);
	ASSERT(result == 2);
}

