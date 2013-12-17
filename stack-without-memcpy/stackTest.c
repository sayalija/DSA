#include <stdlib.h>
#include "testUtils.h"
#include "stack.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_for_creating_a_stack_and_push_one_element(){
	int* peekResult;
	int element = 3;
	Stack* s = create(3);
	push(s, &element);
	*peekResult = *(int*)peek(s);
	ASSERT(*peekResult == element);
}

void test_2_for_push_3_elements(){
	int* peekResult;
	int first = 3,second = 4, third = 5;
	Stack* s = create(3);
	push(s, &first);
	push(s, &second);
	push(s, &third);
	*peekResult = *(int*)peek(s);
	ASSERT(*peekResult == third);
}

void test_3_for_testing_peek_functionality(){
	int first = 3,second = 4, third = 5;
	Stack* s = create(3);
	push(s, &first);
	ASSERT(*(int*)peek(s) == first);
	push(s, &second);
	ASSERT(*(int*)peek(s) == second);
	push(s, &third);
	ASSERT(*(int*)peek(s) == third);
}

void test_4_for_testing_push_peek_create_using_float_type(){
	float first = 3.3f,second = 4.4f, third = 5.5f;
	Stack* s = create(3);
	push(s, &first);
	ASSERT(*(float*)peek(s) == first);
	push(s, &second);
	ASSERT(*(float*)peek(s) == second);
	push(s, &third);
	ASSERT(*(float*)peek(s) == third);
}

void test_5_for_pushing_element_in_stack_more_than_maxSize(){
	char* peekResult;
	char first = 'a',second = 'b', third = 'c';
	Stack* s = create(2);
	push(s, &first);
	push(s, &second);
	push(s, &third);
	*peekResult = *(char*)peek(s);
	ASSERT(*peekResult == third);
}

void test_6_for_push_and_pop_a_element_from_stack(){
	int* peekResult;
	int* popedResult;
	int first = 3;
	Stack* s = create(3);
	push(s, &first);
	*peekResult = *(int*)peek(s);
	ASSERT(*peekResult == first);
	popedResult = pop(s);
	ASSERT(*popedResult == first);
}

void test_7_for_push_and_pop_2_float_elements_from_stack(){
	float* peekResult;
	float* popedResult;
	float first = 3.3f, second = 4.4f;
	Stack* s = create(3);
	push(s, &first);
	push(s, &second);
	popedResult = pop(s);
	ASSERT(*popedResult == second);
	popedResult = pop(s);
	ASSERT(*popedResult == first);
	ASSERT(isEmpty(s) == 1);
}