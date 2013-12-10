#include "testUtils.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compareQueue(Queue *src, Queue *dst){
	if(src->rear == dst->rear && src->maxSize == dst->maxSize && src->elementSize == dst->elementSize)
		return 0 == memcmp(src->elements, dst->elements, src->elementSize*(src->rear+1));
	return 0;
}

void test_1_for_creating_a_queue_for_integer_type(){
	int a[3] = {0,0,0};
	int result;
	Queue expected = {a,-1,3,sizeof(int)};
	Queue* actual = create(3, sizeof(int));
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);
}


void test_2_for_creating_a_queue_for_float_type(){
	float a[3] = {0.0f,0.0f,0.0f};
	int result;
	Queue expected = {a,-1,3,sizeof(float)};
	Queue* actual = create(3, sizeof(float));
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);
}

void test_3_for_creating_a_queue_for_double_type(){
	double a[3] = {0.0f,0.0f,0.0f};
	int result;
	Queue expected = {a,-1,3,sizeof(double)};
	Queue* actual = create(3, sizeof(double));
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);
}

void test_4_for_creating_a_queue_for_character_type(){
	char a[3] = {'\0','\0','\0'};
	int result;
	Queue expected = {a,-1,3,sizeof(char)};
	Queue* actual = create(3, sizeof(char));
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);
}

void test_5_for_creating_a_queue_for_string_type(){
	String a[3] = {"\0","\0","\0"};
	int result;
	Queue expected = {a,-1,3,sizeof(String)};
	Queue* actual = create(3, sizeof(String));
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);
}


void test_6_for_enqueue_a_integer_element_in_queue(){
	int a[3] = {3,0,0};
	int result;
	int element = 3;
	Queue expected = {a,0,3,sizeof(int)};
	Queue* actual = create(3, sizeof(int));
	enqueue(actual, &element);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);
}

void test_7_for_enqueue_two_integer_element_in_queue(){
	int a[3] = {3,4,0};
	int result;
	int first = 3,second = 4;
	Queue expected = {a,1,3,sizeof(int)};
	Queue* actual = create(3, sizeof(int));
	enqueue(actual, &first);
	enqueue(actual, &second);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);

}

void test_8_for_queue_a_string_element_in_queue(){
	String a[3] = {"aaa","\0","\0"};
	int result;
	String element = "aaa";
	Queue expected = {a,0,3,sizeof(String)};
	Queue* actual = create(3, sizeof(String));
	enqueue(actual, &element);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);

}

void test_9_for_queue_two_string_element_in_queue(){
	String a[3] = {"aaa","bbb",0};
	int result;
	String first = "aaa",second = "bbb";
	Queue expected = {a,1,3,sizeof(String)};
	Queue* actual = create(3, sizeof(String));
	enqueue(actual, &first);
	enqueue(actual, &second);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);

}

void test_10_for_queue_a_float_element_in_queue(){
	float a[3] = {3.2f,0.0f,0.0f};
	float element = 3.2;
	int result;
	Queue expected = {a,0,3,sizeof(float)};
	Queue* actual = create(3, sizeof(float));
	enqueue(actual, &element);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);

}

void test_11_for_queue_two_float_element_in_queue(){
	float a[3] = {3.2f,4.3f,0.0f};
	float first = 3.2,second = 4.3;
	int result;
	Queue expected = {a,1,3,sizeof(float)};
	Queue* actual = create(3, sizeof(float));
	enqueue(actual, &first);
	enqueue(actual, &second);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);

}

void test_12_for_queue_a_double_element_in_queue(){
	double a[3] = {3.2f,0.0f,0.0f};
	int result;
	double element = 3.2f;
	Queue expected = {a,0,3,sizeof(double)};
	Queue* actual = create(3, sizeof(double));
	enqueue(actual, &element);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);

}

void test_13_for_queue_two_double_element_in_queue(){
	double a[3] = {3.2,4.3,0.0};
	double first = 3.2,second = 4.3;
	int result;
	Queue expected = {a,1,3,sizeof(double)};
	Queue* actual = create(3, sizeof(double));
	enqueue(actual, &first);
	enqueue(actual, &second);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);

}

void test_14_for_queue_a_character_element_in_queue(){
	char a[3] = {'a','\0','\0'};
	char element = 'a';
	int result;
	Queue expected = {a,0,3,sizeof(char)};
	Queue* actual = create(3, sizeof(char));
	enqueue(actual, &element);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);

}

void test_15_for_queue_two_character_element_in_queue(){
	char a[3] = {'a','b','\0'};
	char first = 'a',second = 'b';
	int result;
	Queue expected = {a,1,3,sizeof(char)};
	Queue* actual = create(3, sizeof(char));
	enqueue(actual, &first);
	enqueue(actual, &second);
	result = compareQueue(actual, &expected);
	ASSERT(result);
	free(actual);

}
void test_16_for_dequeue_a_interger_from_queue(){
	int a[3] = {3,0,0};
	int element = 3;
	Queue expected = {a,0,3,sizeof(int)};
	Queue* q = create(3, sizeof(int));
	enqueue(q, &element);
	ASSERT( *(int*)dequeue(q)== 3);
	free(q->elements);
	free(q);
}

void test_17_for_dequeue_two_interger_in_queue(){
	int a[3] = {3,4,0};
	int first=3, second=4;
	Queue* q = create(3, sizeof(int));
	enqueue(q, &first);
	enqueue(q, &second);
	ASSERT( *(int*)dequeue(q)== 3);
	ASSERT( *(int*)dequeue(q)== 4);
	free(q->elements);
	free(q);
}

void test_18_for_dequeue_a_float_in_queue(){
	float a[3] = {3.2f,0,0};
	float element = 3.2f;
	Queue* q = create(3, sizeof(float));
	enqueue(q, &element);
	ASSERT( *(float*)dequeue(q)== 3.2f);
	free(q->elements);
	free(q);
}

void test_19_for_dequeue_two_float_in_queue(){
	float a[3] = {3.2f,4.3f,0};
	float first=3.2f, second=4.3f;
	Queue* q = create(3, sizeof(float));
	enqueue(q, &first);
	enqueue(q, &second);
	ASSERT( *(float*)dequeue(q)== 3.2f);
	ASSERT( *(float*)dequeue(q)== 4.3f);
	free(q->elements);
	free(q);
}

void test_20_for_dequeue_a_double_in_queue(){
	double a[3] = {3.2,0.0,0.0};
	double element = 3.2;
	int res;
	double* hello;
	Queue* q = create(3, sizeof(double));
	res = enqueue(q, &element);
	hello = dequeue(q);
	ASSERT(res == 1);
	ASSERT(3.2 == *hello);
	free(q->elements);
	free(q);
}

void test_21_for_dequeue_two_double_in_queue(){
	double a[3] = {3.2,4.3,0.0};
	double first=3.2, second=4.3;
	Queue* q = create(3, sizeof(double));
	enqueue(q, &first);
	enqueue(q, &second);
	ASSERT( *(double*)dequeue(q)== 3.2);
	ASSERT( *(double*)dequeue(q)== 4.3);
}

void test_22_for_dequeue_a_character_in_queue(){
	char a[3] = {'a','\0','\0'};
	char element = 'a';
	Queue* q = create(3, sizeof(char));
	enqueue(q, &element);
	ASSERT( *(char*)dequeue(q)== 'a');
}

void test_23_for_dequeue_two_character_in_queue(){
	char a[3] = {'a','b','\0'};
	char first='a', second='b';
	Queue* q = create(3, sizeof(char));
	enqueue(q, &first);
	enqueue(q, &second);
	ASSERT( *(char*)dequeue(q)== 'a');
	ASSERT( *(char*)dequeue(q)== 'b');
}

void test_24_for_dequeue_a_string_in_queue(){
	String a[3] = {"aaa\0","\0","\0"};
	String element = "aaa\0";
	Queue* q = create(3, sizeof(String));
	enqueue(q, element);
	ASSERT(0 == strcmp(*(String*)dequeue(q),"aaa"));
}

void test_27_for_dequeue_two_string_in_queue(){
	String a[3] = {"aaa","bbb","\0"};
	String first="aaa", second="bbb";
	Queue* q = create(3, sizeof(String));
	enqueue(q, &first);
	enqueue(q, &second);
	ASSERT(0 == strcmp(*(String*)dequeue(q), "aaa"));
	ASSERT(0 ==strcmp(*(String*)dequeue(q), "bbb"));
}
