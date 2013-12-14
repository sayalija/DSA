#include <stdio.h>
#include "testUtils.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareStack(Stack *src, Stack *dst){
	if(src->top == dst->top && src->maxSize == dst->maxSize && src->elementSize == dst->elementSize)
		return 0 == memcmp(src->elements, dst->elements, src->elementSize*(src->top+1));
	return 0;
}

void test_1_for_creating_a_stack_for_integer_type(){
	int a[3] = {0,0,0};
	int result;
	Stack expected = {a,-1,3,sizeof(int)};
	Stack* actual = create(3, sizeof(int));
	result = compareStack(actual, &expected);
	ASSERT(result);
	free(actual);
}

void test_2_for_creating_a_stack_for_float_type(){
	float a[3] = {0.0f,0.0f,0.0f};
	int result;
	Stack expected = {a,-1,3,sizeof(float)};
	Stack* actual = create(3, sizeof(float));
	result = compareStack(actual, &expected);
	ASSERT(result);
	free(actual);
}

void test_3_for_creating_a_stack_for_double_type(){
	double a[3] = {0.0f,0.0f,0.0f};
	int result;
	Stack expected = {a,-1,3,sizeof(double)};
	Stack* actual = create(3, sizeof(double));
	result = compareStack(actual, &expected);
	ASSERT(result);
	free(actual);
}

void test_4_for_creating_a_stack_for_character_type(){
	char a[3] = {'\0','\0','\0'};
	int result;
	Stack expected = {a,-1,3,sizeof(char)};
	Stack* actual = create(3, sizeof(char));
	result = compareStack(actual, &expected);
	ASSERT(result);
	free(actual);
}

void test_5_for_push_a_integer_element_in_stack(){
	int a[3] = {3,0,0};
	int result;
	int element = 3;
	Stack expected = {a,0,3,sizeof(int)};
	Stack* actual = create(3, sizeof(int));
	push(actual, &element);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_6_for_push_two_integer_element_in_stack(){
	int a[3] = {3,4,0};
	int result;
	int first = 3,second = 4;
	Stack expected = {a,1,3,sizeof(int)};
	Stack* actual = create(3, sizeof(int));
	push(actual, &first);
	push(actual, &second);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_7_for_push_a_integer_element_in_stack(){
	String a[3] = {"aaa","\0","\0"};
	int result;
	String element = "aaa";
	Stack expected = {a,0,3,sizeof(String)};
	Stack* actual = create(3, sizeof(String));
	push(actual, &element);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_8_for_push_two_integer_element_in_stack(){
	String a[3] = {"aaa","bbb",0};
	int result;
	String first = "aaa",second = "bbb";
	Stack expected = {a,1,3,sizeof(String)};
	Stack* actual = create(3, sizeof(String));
	push(actual, &first);
	push(actual, &second);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_9_for_push_a_float_element_in_stack(){
	float a[3] = {3.2f,0.0f,0.0f};
	float element = 3.2;
	int result;
	Stack expected = {a,0,3,sizeof(float)};
	Stack* actual = create(3, sizeof(float));
	push(actual, &element);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_10_for_push_two_float_element_in_stack(){
	float a[3] = {3.2f,4.3f,0.0f};
	float first = 3.2,second = 4.3;
	int result;
	Stack expected = {a,1,3,sizeof(float)};
	Stack* actual = create(3, sizeof(float));
	push(actual, &first);
	push(actual, &second);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_11_for_push_a_double_element_in_stack(){
	double a[3] = {3.2f,0.0f,0.0f};
	int result;
	double element = 3.2f;
	Stack expected = {a,0,3,sizeof(double)};
	Stack* actual = create(3, sizeof(double));
	push(actual, &element);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_12_for_push_two_double_element_in_stack(){
	double a[3] = {3.2,4.3,0.0};
	double first = 3.2,second = 4.3;
	int result;
	Stack expected = {a,1,3,sizeof(double)};
	Stack* actual = create(3, sizeof(double));
	push(actual, &first);
	push(actual, &second);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_13_for_push_a_character_element_in_stack(){
	char a[3] = {'a','\0','\0'};
	char element = 'a';
	int result;
	Stack expected = {a,0,3,sizeof(char)};
	Stack* actual = create(3, sizeof(char));
	push(actual, &element);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_14_for_push_two_character_element_in_stack(){
	char a[3] = {'a','b','\0'};
	char first = 'a',second = 'b';
	int result;
	Stack expected = {a,1,3,sizeof(char)};
	Stack* actual = create(3, sizeof(char));
	push(actual, &first);
	push(actual, &second);
	result = compareStack(actual, &expected);
	ASSERT(result);
}

void test_15_for_pop_a_interger_in_stack(){
	int element = 3;
	Stack* s = create(3, sizeof(int));
	push(s, &element);
	ASSERT( *(int*)pop(s)== 3);
}

void test_16_for_pop_two_interger_in_stack(){
	int first=3, second=4;
	Stack* s = create(3, sizeof(int));
	push(s, &first);
	push(s, &second);
	ASSERT( *(int*)pop(s)== 4);
	ASSERT( *(int*)pop(s)== 3);
}

void test_17_for_pop_a_float_in_stack(){
	float element = 3.2f;
	Stack* s = create(3, sizeof(float));
	push(s, &element);
	ASSERT( *(float*)pop(s)== 3.2f);
}

void test_18_for_pop_two_float_in_stack(){
	float first=3.2f, second=4.3f;
	Stack* s = create(3, sizeof(float));
	push(s, &first);
	push(s, &second);
	ASSERT( *(float*)pop(s)== 4.3f);
	ASSERT( *(float*)pop(s)== 3.2f);
}

void test_19_for_pop_a_double_in_stack(){
	double element = 3.2;
	Stack* s = create(3, sizeof(double));
	push(s, &element);
	ASSERT( *(double*)pop(s)== 3.2);
}

void test_20_for_pop_two_double_in_stack(){
	double first=3.2, second=4.3;
	Stack* s = create(3, sizeof(double));
	push(s, &first);
	push(s, &second);
	ASSERT( *(double*)pop(s)== 4.3);
	ASSERT( *(double*)pop(s)== 3.2);
}

void test_21_for_pop_a_character_in_stack(){
	char element = 'a';
	Stack* s = create(3, sizeof(char));
	push(s, &element);
	ASSERT( *(char*)pop(s)== 'a');
}

void test_22_for_pop_two_character_in_stack(){
	char first='a', second='b';
	Stack* s = create(3, sizeof(char));
	push(s, &first);
	push(s, &second);
	ASSERT( *(char*)pop(s)== 'b');
	ASSERT( *(char*)pop(s)== 'a');
}

void test_23_for_pop_a_character_in_stack(){
	char element = 'a';
	Stack* s = create(3, sizeof(char));
	push(s, &element);
	ASSERT( *(char*)pop(s)== 'a');
}

void test_24_for_pop_two_character_in_stack(){
	char first='a', second='b';
	Stack* s = create(3, sizeof(char));
	push(s, &first);
	push(s, &second);
	ASSERT( *(char*)pop(s)== 'b');
	ASSERT( *(char*)pop(s)== 'a');
}

void test_25_for_pop_a_character_in_stack(){
	String element = "aaa\0";
	Stack* s = create(3, sizeof(String));
	push(s, element);
	ASSERT(0 == strcmp(*(String*)pop(s),"aaa"));
}

void test_26_for_pop_two_character_in_stack(){
	String first="aaa", second="bbb";
	Stack* s = create(3, sizeof(String));
	push(s, &first);
	push(s, &second);
	ASSERT(0 == strcmp(*(String*)pop(s), "bbb"));
	ASSERT(0 ==strcmp(*(String*)pop(s), "aaa"));
}

void test_27_for_peek_a_interger_in_stack(){
	int element = 3;
	Stack* s = create(3, sizeof(int));
	push(s, &element);
	ASSERT( *(int*)peek(s)== 3);
}

void test_28_for_peek_two_interger_in_stack(){
	int first=3, second=4;
	Stack* s = create(3, sizeof(int));
	push(s, &first);
	push(s, &second);
	ASSERT( *(int*)peek(s)== 4);
}

void test_29_for_peek_a_float_in_stack(){
	float element = 3.2f;
	Stack* s = create(3, sizeof(float));
	push(s, &element);
	ASSERT( *(float*)peek(s)== 3.2f);
}

void test_30_for_peek_two_float_in_stack(){
	float first=3.2f, second=4.3f;
	Stack* s = create(3, sizeof(float));
	push(s, &first);
	push(s, &second);
	ASSERT( *(float*)peek(s)== 4.3f);
}

void test_31_for_peek_a_double_in_stack(){
	double element = 3.2;
	Stack* s = create(3, sizeof(double));
	push(s, &element);
	ASSERT( *(double*)peek(s)== 3.2);
}

void test_32_for_peek_two_double_in_stack(){
	double first=3.2, second=4.3;
	Stack* s = create(3, sizeof(double));
	push(s, &first);
	push(s, &second);
	ASSERT( *(double*)peek(s)== 4.3);
}

void test_33_for_peek_a_character_in_stack(){
	char element = 'a';
	Stack* s = create(3, sizeof(char));
	push(s, &element);
	ASSERT( *(char*)peek(s)== 'a');
}

void test_34_for_peek_two_character_in_stack(){
	char a[3] = {'a','b','\0'};
	char first='a', second='b';
	Stack* s = create(3, sizeof(char));
	push(s, &first);
	push(s, &second);
	ASSERT( *(char*)peek(s)== 'b');
}

void test_35_for_peek_a_character_in_stack(){
	char element = 'a';
	Stack* s = create(3, sizeof(char));
	push(s, &element);
	ASSERT( *(char*)peek(s)== 'a');
}

void test_36_for_peek_two_character_in_stack(){
	char first='a', second='b';
	Stack* s = create(3, sizeof(char));
	push(s, &first);
	push(s, &second);
	ASSERT( *(char*)peek(s)== 'b');
}

void test_37_for_peek_a_character_in_stack(){
	String element = "aaa\0";
	Stack* s = create(3, sizeof(String));
	push(s, element);
	ASSERT(0 == strcmp(*(String*)peek(s),"aaa"));
}

void test_38_for_peek_two_character_in_stack(){
	String first="aaa", second="bbb";
	Stack* s = create(3, sizeof(String));
	push(s, &first);
	push(s, &second);
	ASSERT(0 == strcmp(*(String*)peek(s), "bbb"));
}

void test_39_for_push_elements_more_than_given_maxSize(){
	int first = 3, second = 4,third = 5;
	Stack *s = create(2, sizeof(int));
	push(s, &first);
	push(s, &second);
	push(s, &third);	
	ASSERT(5 == *(int*)peek(s));
	ASSERT(4 == s->maxSize);
}